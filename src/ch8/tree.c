#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j0gram.tab.h"
#include "tree.h"

static void tree_printLeaf(FILE *f, Tree *tree);
static void tree_printBranch(FILE *f, Tree *tree);
static void insertVardeclarator(SymTab *symTab, Tree *vd);
static void tree_checkCodeblocks(Tree *tree);
static void tree_checkBlock(Tree *tree);
static bool tree_checkKids(Tree *tree, bool inCodeBlock);
static TypeInfo *tree_checkTypes(Tree *tree, TypeInfo *op1, TypeInfo *op2);
static const char *tree_getOp(Tree *tree);
static Tree *tree_findToken(Tree *tree);
static TypeInfo *tree_dequalify(Tree *tree);
static TypeInfo **tree_mksig(Tree *tree, uint *nparams);
static void tree_cksig(Tree *tree, MethodType *sig);
static char *escape(char *dest, const char *src);
static char *prettyPrintName(char *dest, Tree *tree);

TypeInfo *token_CatType(int cat) {
  switch (cat) {
    case VOID:
      return (TypeInfo*)typeinfo_VoidType();
    case INT:
    case INTLIT:
      return (TypeInfo*)typeinfo_IntType();
    case DOUBLE:
    case DOUBLELIT:
      return (TypeInfo*)typeinfo_DoubleType();
    case STRING:
    case STRINGLIT:
      return (TypeInfo*)typeinfo_StringType();
    case BOOLEAN:
    case BOOLLIT:
      return (TypeInfo*)typeinfo_BoolType();
    case NULLVAL:
      return (TypeInfo*)typeinfo_NullType();
    case '=':
    case '+':
    case '-':
      return (TypeInfo*)typeinfo_NaType();
    default:
      return NULL;
  }
}

TypeInfo *token_Type(Token *token, SymTab *stab) {
  SymTabEntry *rv;

  if (token->typ)
    return token->typ;

  if (token->cat == IDENTIFIER && (rv = symtab_LookupEntry(stab, token->text)))
    return token->typ = rv->typ;
  
  printf("semantic error: cannot check the type of %s\n", token->text);
  exit(1);

  return NULL;
}

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
  tree->kids = NULL;

  free(tree->tok.text);
  tree->tok.text = NULL;

  symtab_Free(tree->symTab);
  tree->symTab = NULL;

  typeinfo_Free(tree->typ);
  tree->typ = NULL;

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
    stab = symtab_Create(CLASS_SCOPE, stab);
  } else if (strcmp("MethodDecl", tree->sym) == 0) {
    stab = symtab_Create(METHOD_SCOPE, stab);
  }

  for (int i=0; i<tree->nkids; i++)
    tree_MkSymTables(tree->kids[i], stab);
}

void tree_PopulateSymTables(Tree *tree) {
  if (strcmp("ClassDecl", tree->sym) == 0) {
    symtab_InsertEntry(
      tree->symTab,
      tree->kids[0]->tok.text,
      false,
      tree->kids[0]->symTab,
      NULL
    );
  } else if (strcmp("FieldDecl", tree->sym) == 0 || strcmp("LocalVarDecl", tree->sym) == 0) {
    Tree *k = tree->kids[1];
    while (strcmp("VarDecls", k->sym) == 0) {
        insertVardeclarator(tree->symTab, k->kids[1]);
        k = k->kids[0];
    }
    insertVardeclarator(tree->symTab, k);
    return;
  } else if (strcmp("MethodDecl", tree->sym) == 0) {
    char *s = tree->kids[0]->kids[1]->kids[0]->tok.text;
    symtab_InsertEntry(
      tree->symTab,
      s,
      false,
      tree->kids[0]->symTab,
      tree->kids[0]->kids[1]->typ
    );

    symtab_InsertEntry(
      tree->kids[0]->symTab,
      "return",
      false,
      NULL,
      tree->kids[0]->kids[0]->typ
    );
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

void tree_CalcType(Tree *tree) {
  for(int i=0; i<tree->nkids; i++)
    tree_CalcType(tree->kids[i]);

  if (!strcmp("FieldDecl", tree->sym)) {
    tree->typ = tree->kids[0]->typ;
    return;
  } else if (!strcmp("token", tree->sym)) {
    if (tree->typ = tree->tok.typ)
      return;

    switch (tree->tok.cat) {
      case IDENTIFIER:
        if (tree->symTab) {
          SymTabEntry *rv = symtab_LookupEntry(tree->symTab, tree->tok.text);
          if (rv && (tree->typ = rv->typ))
            return;
        }
        tree->typ = (TypeInfo*)typeinfo_CreateClassType(tree->tok.text, NULL, 0, NULL, 0, NULL);
        return;
      default:
        printf("semantic error: can't grok the type of %s cat %d\n", tree->tok.text, tree->tok.cat);
        exit(1);
    }
  } else {
    printf("semantic error: don't know how to calctype %s\n", tree->sym);
    exit(1);
  }
}

void tree_AssignType(Tree *tree, TypeInfo *typeInfo) {
  tree->typ = typeInfo;

  if (!strcmp("VarDeclarator", tree->sym)) {
    tree_AssignType(tree->kids[0], (TypeInfo*)typeinfo_CreateArrayType(typeInfo));
    return;
  } else if (!strcmp("MethodDeclarator", tree->sym)) {
    TypeInfo **params;
    uint nparams;
    if (tree->kids[1]) {
      params = tree_mksig(tree->kids[1], &nparams);
    } else {
      TypeInfo *naType = (TypeInfo*)typeinfo_NaType();
      params = calloc(1, sizeof(TypeInfo*));
      params[0] = naType;
      nparams = 1;
    }
    
    tree->kids[0]->typ = tree->typ = (TypeInfo*)typeinfo_CreateMethodType(typeInfo, nparams, params);
    return;
  } else if (!strcmp("token", tree->sym)) {
    if (tree->tok.cat == IDENTIFIER) {
      return;
    } else {
      printf("semantic error: eh? %d", tree->tok.cat);
      exit(1);
    }
  } else {
    printf("semantic error: don't know how to assign type %s\n", tree->sym);
    exit(1);
  }

  for(int i=0; i<tree->nkids; i++)
    tree_AssignType(tree->kids[i], typeInfo);
}

void tree_CheckType(Tree *tree, bool inCodeBlock) {
  if (tree_checkKids(tree, inCodeBlock))
    return;

  if (!inCodeBlock)
    return;

  if (!strcmp("Assignment", tree->sym)) {
    tree->typ = tree_checkTypes(tree, tree->kids[0]->typ, tree->kids[2]->typ);
  } else if (!strcmp("AddExpr", tree->sym)) {
    tree->typ = tree_checkTypes(tree, tree->kids[0]->typ, tree->kids[1]->typ);
  } else if (!strcmp("ArgList", tree->sym) || !strcmp("Block", tree->sym) || !strcmp("BlockStmts", tree->sym)) {
    tree->typ = NULL;
  } else if (!strcmp("MethodCall", tree->sym)) {
    if (tree->rule == 1290) {
      SymTabEntry *rve;
      MethodType *rv;
      if (!strcmp("QualifiedName", tree->kids[0]->sym)){
        rv = (MethodType*)(tree_dequalify(tree->kids[0]));
        tree_cksig(tree, rv);
      } else {
        if (strcmp("token", tree->kids[0]->sym)) { // if not a token
          printf("semantic error: can't check type of %s\n", tree->kids[0]->sym);
          exit(1);
        }

        if (tree->kids[0]->tok.cat == IDENTIFIER) {
          printf("checking the type of a call to %s\n", tree->kids[0]->tok.text);
          if (rve = symtab_LookupEntry(tree->symTab, tree->kids[0]->tok.text)) {
            if (rve->typ->basetype != METHOD_TYPE) {
              printf("semantic error: method expected, got %s\n", typeinfo_Name(rve->typ));
              exit(1);
            }
            rv = (MethodType*)rve->typ;
            tree_cksig(tree, rv);
          }
        } else {
          printf("semantic error: can't typecheck token %d\n", tree->kids[0]->tok.cat);
          exit(1);
        }
      }
    } else {
      printf("semantic error: Jzero does not handle complex calls\n");
      exit(1);
    }
  } else if (!strcmp("QualifiedName", tree->sym)) {
    if (tree->kids[0]->typ && tree->kids[0]->typ->basetype == CLASS_TYPE) {
        ClassType *ct = (ClassType*)(tree->kids[0]->typ);
        tree->typ = symtab_LookupEntry(ct->st, tree->kids[1]->tok.text)->typ;
    } else {
      printf("semantic error: illegal . on %s\n", typeinfo_Name(tree->kids[0]->typ));
      exit(1);
    }
  } else if (!strcmp("InstanceCreation", tree->sym)) {
    SymTabEntry *rv;
    if (!(rv = symtab_LookupEntry(tree->symTab, tree->kids[0]->tok.text))) {
      printf("semantic error: unknown type %s\n", tree->kids[0]->tok.text);
      exit(1);
    }

    if (!(tree->typ = rv->typ)) {
      printf("semantic error: %s has unknown type\n", tree->kids[0]->tok.text);
      exit(1);
    }
  } else if (!strcmp("ArrayCreation", tree->sym)) {
    tree->typ = (TypeInfo*)typeinfo_CreateArrayType(tree->kids[0]->typ);
  } else if (!strcmp("ArrayAccess", tree->sym)) {
    if (tree->kids[0]->typ->basetype == ARRAY_TYPE) {
      if (tree->kids[1]->typ->basetype == INT_TYPE) {
        tree->typ = ((ArrayType*)tree->kids[0]->typ)->elementType;
      } else {
        printf("semantic error: subscripting array with %s\n", typeinfo_Name(tree->kids[1]->typ));
        exit(1);
      }
    } else {
      printf("semantic error: illegal subscript on type %s\n", typeinfo_Name(tree->kids[0]->typ));
      exit(1);
    }
  } else if (!strcmp("ReturnStmt", tree->sym)) {
    SymTabEntry *ste;
    if (!(ste = symtab_LookupEntry(tree->symTab, "return"))) {
      printf("semantic error: stab did not find a returntype\n");
      exit(1);
    }

    TypeInfo *rt = ste->typ;
    if (tree->kids[0]->typ) {
      tree->typ = tree_checkTypes(tree, rt, tree->kids[0]->typ);
    } else { // return; check that return type is void
      if (rt->basetype != VOID_TYPE) {
        printf("semantic error: void return from non-void method\n");
        exit(1);
      }
      tree->typ = rt;
    }
  } else if (!strcmp("token", tree->sym)) {
    tree->typ = token_Type(&tree->tok, tree->symTab);
  } else {
    printf("semantic error: cannot check type of %s\n", tree->sym);
    exit(1);
  }
}

void tree_MkCls(Tree *tree) {
  SymTabEntry *rv;
  if (!strcmp("ClassDecl", tree->sym)) {
    rv = symtab_LookupEntry(tree->symTab, tree->kids[0]->tok.text);
    rv->typ = (TypeInfo*)symtab_MkCls(tree->kids[0]->tok.text, rv->st);
  } else {
    for(int i = 0; i<tree->nkids; i++) {
      if (tree->kids[i]->nkids > 0)
        tree_MkCls(tree->kids[i]);
    }
  }
}


static void insertVardeclarator(SymTab *symTab, Tree *vd) {
  if (vd->tok.id != 0)
    symtab_InsertEntry(symTab, vd->tok.text, false, NULL, vd->typ);
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

static bool tree_checkKids(Tree *tree, bool inCodeBlock) {
  if (!strcmp("MethodDecl", tree->sym)) {
    tree_CheckType(tree->kids[1], true);
    return true;
  } else if (!strcmp("LocalVarDecl", tree->sym)) {
    tree_CheckType(tree->kids[1], false);
    return true;
  } else if (!strcmp("FieldAccess", tree->sym)) {
    tree_CheckType(tree->kids[0], inCodeBlock);
    return true;
  } else if (!strcmp("QualifiedName", tree->sym)) {
    tree_CheckType(tree->kids[0], inCodeBlock);
  } else {
    for (int i=0; i<tree->nkids; i++) {
      tree_CheckType(tree->kids[i], inCodeBlock);
    }
    
  }

  return false;
}

static TypeInfo *tree_checkTypes(Tree *tree, TypeInfo *op1, TypeInfo *op2) {
    const char *op = tree_getOp(tree);
    if (!strcmp("param", op) || !strcmp("return", op) || !strcmp("=", op) || !strcmp("+", op) || !strcmp("-", op)) {
      Tree *tk;
      if (tk = tree_findToken(tree))
        printf("line %d: ", tk->tok.lineno);

      if (op1->basetype == op2->basetype && (op1->basetype == INT_TYPE || op1->basetype == DOUBLE_TYPE || op1->basetype == STRING_TYPE)) {
        printf("typecheck %s on a %s and a %s -> OK\n", op, typeinfo_Name(op2), typeinfo_Name(op1));
        return op1;
      } else if (op1->basetype == ARRAY_TYPE && op2->basetype == ARRAY_TYPE && !strcmp("=", op) && tree_checkTypes(tree, ((ArrayType*)op1)->elementType, ((ArrayType*)op2)->elementType)) {
          return op1;
      } else if (op1->basetype == op2->basetype && !strcmp("=", op)) {
          printf("typecheck %s on a %s and a %s -> OK\n", op, typeinfo_Name(op1), typeinfo_Name(op2));
          return op1;
      }
      else {
        printf("semantic error: typecheck %s on a %s and a %s -> FAIL\n", op, typeinfo_Name(op2), typeinfo_Name(op1));
        exit(1);
      }
    } else {
      printf("semantic error: don't know how to check %s\n", op);
      exit(1);
    }

    return NULL;
}

static const char *tree_getOp(Tree *tree) {
  if (!strcmp("ReturnStmt", tree->sym)) {
    return "return";
  } else if (!strcmp("MethodCall", tree->sym)) {
    return "param";
  } else if (!strcmp("Assignment", tree->sym)) {
    return "=";
  } else if (!strcmp("AddExpr", tree->sym)) {
    return tree->rule == 1320 ? "+" : "-";
  }

  return NULL;
}

static Tree *tree_findToken(Tree *tree) {
  Tree *rv;
  if (!strcmp("token", tree->sym))
    return tree;

  for (int i=0; i<tree->nkids; i++) {
    if (rv = tree_findToken(tree->kids[i]))
      return rv;
  }

  return NULL;
}

static TypeInfo *tree_dequalify(Tree *tree) {
  TypeInfo *rv = NULL;
  SymTabEntry *ste;
  if (!strcmp("QualifiedName", tree->kids[0]->sym)) {
    rv = tree_dequalify(tree->kids[0]);
  } else if (!strcmp("token", tree->kids[0]->sym) && tree->kids[0]->tok.cat == IDENTIFIER) {
    if (!(ste = symtab_LookupEntry(tree->symTab, tree->kids[0]->tok.text))) {
      printf("semantic error: unknown symbol %s\n", tree->kids[0]->tok.text);
      exit(1);
    }
    rv = ste->typ;
  } else {
    printf("semantic error: can't dequalify %s\n", tree->sym);
    exit(1);
  }

  if (rv->basetype != CLASS_TYPE) {
    printf("semantic error: can't dequalify %s\n", typeinfo_Name(rv));
    exit(1);
  }

  ste = symtab_LookupEntry(((ClassType*)rv)->st, tree->kids[1]->tok.text);
  if (ste)
    return ste->typ;
  
  printf("semantic error: couldn't lookup %s in %s\n", tree->kids[1]->tok.text, typeinfo_Name(rv));
  exit(1);

  return NULL;
}

static TypeInfo **tree_mksig(Tree *tree, uint *nparams) {
  TypeInfo **res = NULL;
  if (!strcmp("FormalParm", tree->sym)) {
    *nparams = 1;
    res = calloc(1, sizeof(TypeInfo*));
    int sz = sizeof *(tree->kids[0]->typ);
    TypeInfo *typeInfo = malloc(sz);
    memcpy(typeInfo, tree->kids[0]->typ, sz);
    res[0] = typeInfo;
    return res;
  } else if (!strcmp("FormalParmList", tree->sym)) {
    int nparams1, nparams2;
    TypeInfo **t1 = tree_mksig(tree->kids[0], &nparams1);
    TypeInfo **t2 = tree_mksig(tree->kids[1], &nparams2);
    *nparams = nparams1 + nparams2;
    res = calloc(nparams1 + nparams2, sizeof(TypeInfo*));
    for(int i=0; i<nparams1; i++)
      res[i]=t1[i];

    for(int j=0; j<nparams2; j++)
        res[nparams1+j]=t2[j];

    free(t1);
    free(t2);
  }

  return res;
}

static void tree_cksig(Tree *tree, MethodType *sig) {
    int i = sig->nparams, nactual = 1;
    Tree *t = tree->kids[1];
    if (!t) {
      if (i != 0) {
        printf("semantic error: 0 params, expected %d\n", i);
        exit(1);
      }
    } else {
      while (!strcmp("ArgList", t->sym)) {
        nactual++;
        t = t->kids[0];
      }

      if (nactual != i) {
        printf("semantic error: %d parameters, expected %d\n", nactual, i);
        exit(1);
      }

      t = tree->kids[1];
      i--;
      while (!strcmp("ArgList", t->sym)) {
        tree_checkTypes(tree, t->kids[1]->typ, (TypeInfo*)sig->params[i]);
        t = t->kids[0];
        i--;
      }
      tree_checkTypes(tree, t->typ, (TypeInfo*)sig->params[0]);
    }
    tree->typ = sig->returnType;
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
