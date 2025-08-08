#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

static void tree_printLeaf(FILE *f, Tree *tree);
static void tree_printBranch(FILE *f, Tree *tree);
static void insertVardeclarator(SymTab *symTab, Tree *vd);
static void tree_checkCodeblocks(Tree *tree);
static void tree_checkBlock(Tree *tree);
static char *escape(char *dest, const char *src);
static char *prettyPrintName(char *dest, Tree *tree);

void tree_Print(Tree *tree, int level) {
  int i;
  for(i=0; i<level; i++)
    printf(" ");

  if (tree->tok.id != 0) {
    printf("%d   %s (%d): %d\n", tree->id, tree->tok.text, tree->tok.cat, tree->tok.lineno);
  } else {
    printf("%d   %s (%d): %d\n", tree->id, tree->sym, tree->rule, tree->nkids);
  }

  for(i=0; i<tree->nkids; i++)
    tree_Print(tree->kids[i], level+1);
}

void tree_PrintGraph(FILE *f, Tree *tree) {
  int i;
  if (tree->tok.id != 0) {
    tree_printLeaf(f, tree);
    return;
  }

  // from here on out, we know we are not a leaf
  tree_printBranch(f, tree);

  for(i=0; i<tree->nkids; i++) {
    Tree *child = tree->kids[i];
    fprintf(f, "N%d -> N%d;\n", tree->id, child->id);
    tree_PrintGraph(f, child);
  }
}

void tree_Free(Tree *tree) {
  if (!tree)
    return;

  for (int i = 0; i < tree->nkids; i++) {
    Tree *child = tree->kids[i];
    tree_Free(child);
  }
  free(tree->kids);

  free(tree->tok.text);

  if (tree->symTab)
    symtab_Free(tree->symTab);

  free(tree);
}

void tree_CalcIsConst(Tree *tree) {
  if (!strcmp(tree->sym, "INTLIT") || !strcmp(tree->sym, "DOUBLELIT") || !strcmp(tree->sym, "STRINGLIT") || !strcmp(tree->sym, "BOOLFALSE") || !strcmp(tree->sym, "BOOLTRUE")) {
    tree->isConst = true;
  } else if (!strcmp(tree->sym, "UnaryExpr")) {
    tree->isConst = tree->kids[1]->isConst;
  } else if (!strcmp(tree->sym, "RelExpr")) {
    tree->isConst = tree->kids[0]->isConst && tree->kids[2]->isConst;
  } else if (!strcmp(tree->sym, "CondOrExpr") || !strcmp(tree->sym, "CondAndExpr") || !strcmp(tree->sym, "EqExpr") || !strcmp(tree->sym, "MULEXPR") || !strcmp(tree->sym, "ADDEXPR")) {
    tree->isConst = tree->kids[0]->isConst && tree->kids[1]->isConst;
  } else {
    tree->isConst = false;
  }

  for(int i=0; i<tree->nkids; i++)
    tree_CalcIsConst(tree->kids[i]);
}

void tree_MkSymTables(Tree *tree, SymTab *stab) {
  tree->symTab = stab;
  if (strcmp("ClassDecl", tree->sym) == 0) {
    stab = symtab_Create("class", stab);
  } else if (strcmp("MethodDecl", tree->sym) == 0) {
    stab = symtab_Create("method", stab);
  }

  for (int i=0; i<tree->nkids; i++)
    tree_MkSymTables(tree->kids[i], stab);
}

void tree_PopulateSymTables(Tree *tree) {
  if (strcmp("ClassDecl", tree->sym) == 0) {
    symtab_InsertEntry(tree->symTab, tree->kids[0]->tok.text, false, tree->kids[0]->symTab);
  } else if (strcmp("FieldDecl", tree->sym) == 0 || strcmp("LocalVarDecl", tree->sym) == 0) {
    Tree *k = tree->kids[1];
    while (strcmp("VarDecls", k->sym) == 0) {
        insertVardeclarator(tree->symTab, k->kids[1]);
        k = k->kids[0];
    }
    insertVardeclarator(tree->symTab, k);
    return;
  } else if (strcmp("MethodDecl", tree->sym) == 0) {
    symtab_InsertEntry(tree->symTab, tree->kids[0]->kids[1]->kids[0]->tok.text, false, tree->kids[0]->symTab);

    // Not sure for the next two lines! Repeats block for FormalParam below
    insertVardeclarator(tree->symTab, tree->kids[1]);
    return;
  } else if (strcmp("FormalParm", tree->sym) == 0) {
    insertVardeclarator(tree->symTab, tree->kids[1]);
    return;
  }

  for(int i = 0; i < tree->nkids; i++) {
      Tree *k = tree->kids[i];
      tree_PopulateSymTables(k);
  }
}

void tree_CheckSymTables(Tree *tree) {
  tree_checkCodeblocks(tree);
}

static void insertVardeclarator(SymTab *symTab, Tree *vd) {
  if (vd->tok.id != 0)
    symtab_InsertEntry(symTab, vd->tok.text, false, NULL);
  else
    insertVardeclarator(symTab, vd->kids[0]);
}

static void tree_checkCodeblocks(Tree *tree) {
  Tree *k;
  if (strcmp("MethodDecl", tree->sym) == 0) {
    tree_checkBlock(tree->kids[1]);
  } else {
    for(int i=0; i<tree->nkids; i++){
      k = tree->kids[i];
      if (k->nkids>0)
        tree_checkCodeblocks(k);
    }
  }
}

static void tree_checkBlock(Tree *tree) {
  if (strcmp("IDENTIFIER", tree->sym) == 0) {
    if (!symtab_LookupEntry(tree->symTab, tree->sym)) {
      printf("semantic error: undeclared variable %s\n", tree->tok.text);
      exit(1);
    }
  } else if (strcmp("FieldAccess", tree->sym) == 0 || strcmp("QualifiedName", tree->sym) == 0) {
    tree_checkBlock(tree->kids[0]);
  } else if (strcmp("MethodCall", tree->sym) == 0) {
    tree_checkBlock(tree->kids[0]);
    if (tree->rule == 1290)
      tree_checkBlock(tree->kids[1]);
    else
      tree_checkBlock(tree->kids[2]);
  } else if (strcmp("LocalVarDecl", tree->sym) == 0) {
    return;
  } else {
    for(int i=0; i<tree->nkids; i++)
      tree_checkBlock(tree->kids[i]);
  }
}

static void tree_printLeaf(FILE *f, Tree *tree) {
  const char *s = token_Name(tree->tok.cat);
  tree_printBranch(f, tree);
  fprintf(f, "N%d [shape=box style=dotted label=\" %s \\n ", tree->id, s);

  char escapedText[strlen(tree->tok.text)+3];
  fprintf(f, "text = %s \\l lineno = %d \\l\"];\n", escape(escapedText, tree->tok.text), tree->tok.lineno);
}

static void tree_printBranch(FILE *f, Tree *tree) {
  fprintf(f, "N%d ", tree->id);

  int prettyNameLen = tree->tok.id == 0 ? (strlen(tree->sym)+3) : (strlen(tree->tok.text)+10);
  char prettyName[prettyNameLen];
  fprintf(f, "[shape=box label=\"%s", prettyPrintName(prettyName, tree));

  if (tree->tok.id != 0)
    fprintf(f, "struct token* leaf %d", tree->tok.id);

  fprintf(f, "\"];\n");
}

static char *escape(char *dest, const char *src) {
  if (src[0] == '"') {
    int len = strlen(src);
    dest[0] = '\\';
    strncat(dest, src, len-1);
    strcat(dest, "\\\"");
  } else {
    strcpy(dest, src);
  }

  return dest;
}

static char *prettyPrintName(char *dest, Tree *tree) {
  if (tree->tok.id == 0) {
    sprintf(dest, "%s#%d", tree->sym, tree->rule%10);
  } else {
    char escapedText[strlen(tree->tok.text)+3];
    sprintf(dest, "%s:%d", escape(escapedText, tree->tok.text), tree->tok.cat);
  }

  return dest;
}
