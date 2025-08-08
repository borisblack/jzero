#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "j0gram.tab.h"
#include "tree.h"
#include "serial.h"

typedef struct TacListNode TacListNode;

struct TacListNode {
  dlist_node node;
  Tac *tac;
};

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
static Address *tree_genLabel(Tree *tree);
static void tree_genClassDecl(Tree *tree);
static void tree_genAddExpr(Tree *tree);
static void tree_genMulExpr(Tree *tree);
static void tree_genRelExpr(Tree *tree);
static void tree_genWhileStmt(Tree *tree);
static void tree_genIfThenStmt(Tree *tree);
static void tree_genAssignment(Tree *tree);
static void tree_genMethodCall(Tree *tree);
static void tree_genMethodDecl(Tree *tree);
static void tree_genQualifiedName(Tree *tree);
static void tree_genToken(Tree *tree);
static Address *tree_genLocal(Tree *tree);
static void tree_addCode(Tree *tree, const char *op, int nop, ...);
static void tree_addStringConst(const HTableNode *node, void *arg, void *local_arg);
static void tree_addGlobal(const HTableNode *node, void *arg, void *local_arg);
static void tree_copyIcode(Tree *dest, Tree *src);
static void tree_printLeaf(FILE *f, Tree *tree);
static void tree_printBranch(FILE *f, Tree *tree);
static char *escape(char *dest, const char *src);
static char *prettyPrintName(char *dest, Tree *tree);

extern SymTab *global_st;
extern SymTab *string_st;

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

void tree_CalcIsConst(Tree *tree) {
  for(int i=0; i<tree->nkids; i++)
    tree_CalcIsConst(tree->kids[i]);

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
  } else if (!strcmp("RelExpr", tree->sym)) {
    tree->typ = tree_checkTypes(tree, tree->kids[0]->typ, tree->kids[2]->typ);
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
    if (tree->kids[0]->typ->basetype == CLASS_TYPE) {
      ClassType *ct = (ClassType*)(tree->kids[0]->typ);
      tree->typ = symtab_LookupEntry(ct->st, tree->kids[1]->tok.text)->typ;
    } else if (tree->kids[0]->typ->basetype == ARRAY_TYPE) {
      tree->typ = (TypeInfo*)typeinfo_IntType();
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
  } else if (!strcmp("IfThenStmt", tree->sym) || !strcmp("WhileStmt", tree->sym)) {
    return; // no checks for j0 statements
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

void tree_GenFirst(Tree *tree) {
  for(int i=0; i<tree->nkids; i++)
    tree_GenFirst(tree->kids[i]);

  if (!strcmp("UnaryExpr", tree->sym)) {
    if (tree->kids[1]->first)
      tree->first = tree->kids[1]->first;
    else
      tree->first = tree_genLabel(tree);
  } else if (!strcmp("AddExpr", tree->sym) || !strcmp("MulExpr", tree->sym) || !strcmp("RelExpr", tree->sym)) {
    if (tree->kids[0]->first)
      tree->first = tree->kids[0]->first;
    else if (tree->kids[1]->first)
      tree->first = tree->kids[1]->first;
    else
      tree->first = tree_genLabel(tree);
  } else if (!strcmp("Block", tree->sym) || !strcmp("WhileStmt", tree->sym)) {
    if (tree->kids[0]->first)
      tree->first = tree->kids[0]->first;
    else
      tree->first = tree_genLabel(tree);
  } else if (!strcmp("BlockStmts", tree->sym)) {
    if (!tree->kids[1]->first)
      tree->kids[1]->first = tree_genLabel(tree);

    if (tree->kids[0]->first)
      tree->first = tree->kids[0]->first;
    else
      tree->first = tree->kids[1]->first;
  }
  // ...
  else {
    for(int i=0; i<tree->nkids; i++) {
      Tree *kid = tree->kids[i];
      if (kid->first) {
        tree->first = kid->first;
        break;
      }
    }
  }
}

void tree_GenFollow(Tree *tree) {
  if (!strcmp("MethodDecl", tree->sym)) {
    tree->kids[1]->follow = tree->follow = tree_genLabel(tree);
  } else if (!strcmp("BlockStmts", tree->sym)) {
    tree->kids[0]->follow = tree->kids[1]->first;
    tree->kids[1]->follow = tree->follow;
  } else if (!strcmp("Block", tree->sym)) {
    tree->kids[0]->follow = tree->follow;
  }
  // ...

  for(int i=0; i<tree->nkids; i++) {
    tree_GenFollow(tree->kids[i]);
  }
}

void tree_GenTargets(Tree *tree) {
  if (!strcmp("IfThenStmt", tree->sym) || !strcmp("WhileStmt", tree->sym)) {
    tree->kids[0]->onTrue = tree->kids[1]->first;
    tree->kids[0]->onFalse = tree->follow;
  } else if (!strcmp("CondAndExpr", tree->sym)) {
    tree->kids[0]->onTrue = tree->kids[1]->first;
    tree->kids[0]->onFalse = tree->onFalse;
    tree->kids[1]->onTrue = tree->onTrue;
    tree->kids[1]->onFalse = tree->onFalse;
  }
  // ...

  for(int i=0; i<tree->nkids; i++) {
    tree_GenTargets(tree->kids[i]);
  }
}

void tree_GenCode(Tree *tree) {
  for(int i=0; i<tree->nkids; i++) {
    tree_GenCode(tree->kids[i]);
  }

  if (!strcmp("ClassDecl", tree->sym)) {
    tree_genClassDecl(tree);
  } else if (!strcmp("AddExpr", tree->sym)) {
    tree_genAddExpr(tree);
  } else if (!strcmp("MulExpr", tree->sym)) {
    tree_genMulExpr(tree);
  } else if (!strcmp("RelExpr", tree->sym)) {
    tree_genRelExpr(tree);
  } else if (!strcmp("WhileStmt", tree->sym)) {
    tree_genWhileStmt(tree);
  } else if (!strcmp("IfThenStmt", tree->sym)) {
    tree_genIfThenStmt(tree);
  } else if (!strcmp("Assignment", tree->sym)) {
    tree_genAssignment(tree);
  } else if (!strcmp("MethodCall", tree->sym)) {
    tree_genMethodCall(tree);
  } else if (!strcmp("MethodDecl", tree->sym)) {
    tree_genMethodDecl(tree);
  } else if (!strcmp("QualifiedName", tree->sym)) {
    tree_genQualifiedName(tree);
  }
  // ...
  else if (!strcmp("token", tree->sym)) {
    tree_genToken(tree);
  } else {
    for (int i=0; i<tree->nkids; i++) {
      tree_copyIcode(tree, tree->kids[i]);
    }
  }
}

void tree_PrintIcode(Tree *tree) {
  dlist_iter iter;
  TacListNode *listNode;

  dlist_foreach(iter, &tree->icode) {
    listNode = (TacListNode*)iter.cur;
    tac_PrintTac(listNode->tac);
  }
}

void tree_Free(Tree *tree) {
  if (!tree)
    return;

  for (int i=0; i<tree->nkids; i++) {
    tree_Free(tree->kids[i]);
  }
  free(tree->kids);
  tree->kids = NULL;
  tree->nkids = 0;

  free(tree->tok.text);
  tree->tok.text = NULL;

  symtab_Free(tree->symTab);
  tree->symTab = NULL;

  typeinfo_Free(tree->typ);
  tree->typ = NULL;

  TacListNode *tacListNode;
  for (int i=0; i<tree->ncode; i++) {
    tacListNode = (TacListNode*)dlist_pop_head_node(&tree->icode);
    tac_FreeTac(tacListNode->tac);
    free(tacListNode);
  }
  tree->ncode = 0;

  tac_FreeAddress(tree->addr);
  tac_FreeAddress(tree->first);
  tac_FreeAddress(tree->follow);
  tac_FreeAddress(tree->onTrue);
  tac_FreeAddress(tree->onFalse);
  tree->addr = NULL;
  tree->first = NULL;
  tree->follow = NULL;
  tree->onTrue = NULL;
  tree->onFalse = NULL;
  
  free(tree);
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
  } else if (!strcmp("RelExpr", tree->sym)) {
    tree_CheckType(tree->kids[0], inCodeBlock);
    tree_CheckType(tree->kids[2], inCodeBlock);
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
      if (tk = tree_findToken(tree)) {
        // printf("line %d: ", tk->tok.lineno);
      }

      if (op1->basetype == op2->basetype && (op1->basetype == INT_TYPE || op1->basetype == DOUBLE_TYPE || op1->basetype == STRING_TYPE)) {
        // printf("typecheck %s on a %s and a %s -> OK\n", op, typeinfo_Name(op2), typeinfo_Name(op1));
        return op1;
      } else if (op1->basetype == ARRAY_TYPE && op2->basetype == ARRAY_TYPE && !strcmp("=", op) && tree_checkTypes(tree, ((ArrayType*)op1)->elementType, ((ArrayType*)op2)->elementType)) {
          return op1;
      } else if (op1->basetype == op2->basetype && !strcmp("=", op)) {
          // printf("typecheck %s on a %s and a %s -> OK\n", op, typeinfo_Name(op1), typeinfo_Name(op2));
          return op1;
      }
      else {
        if (tk)
          printf("line %d: ", tk->tok.lineno);

        printf("semantic error: typecheck %s on a %s and a %s -> FAIL\n", op, typeinfo_Name(op2), typeinfo_Name(op1));
        exit(1);
      }
    } else if (!strcmp("<", op) || !strcmp(">", op)) {
      if (op1->basetype == op2->basetype && (op1->basetype == INT_TYPE || op1->basetype == DOUBLE_TYPE)) {
        return (TypeInfo*)typeinfo_BoolType();
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
  } else if (!strcmp("RelExpr", tree->sym)) {
    if (!strcmp("token", tree->kids[1]->sym))
      return tree->kids[1]->tok.text;
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

static void tree_genClassDecl(Tree *tree) {
  dlist_iter iter;
  TacListNode *listNode, *newListNode;

  // emit string constants
  if (symTab_Size(string_st) > 0) {
    tree_addCode(tree, ".string", 0);
    htable_foreach(&string_st->t, tree_addStringConst, tree);
  }

  // emit the globals
   if (symTab_Size(global_st) > 0) {
    tree_addCode(tree, ".global", 0);
    htable_foreach(&global_st->t, tree_addGlobal, tree);
  }

  tree_addCode(tree, ".code", 0);

  for (int i=0; i<tree->nkids; i++) {
    tree_copyIcode(tree, tree->kids[i]);
  }
}

static void tree_genAddExpr(Tree *tree) {
  tree->addr = tree_genLocal(tree);
  tree_copyIcode(tree, tree->kids[0]);
  tree_copyIcode(tree, tree->kids[1]);
  tree_addCode(tree, tree->rule==1320 ? "ADD" : "SUB", 3, tree->addr, tree->kids[0]->addr, tree->kids[1]->addr);
}

static void tree_genMulExpr(Tree *tree) {
  tree->addr = tree_genLocal(tree);
  tree_copyIcode(tree, tree->kids[0]);
  tree_copyIcode(tree, tree->kids[1]);

  if (tree->rule == 1310)
    tree_addCode(tree, "MUL", 3, tree->addr, tree->kids[0]->addr, tree->kids[1]->addr);
  else if (tree->rule == 1311)
    tree_addCode(tree, "DIV", 3, tree->addr, tree->kids[0]->addr, tree->kids[1]->addr);
  else
    tree_addCode(tree, "MOD", 3, tree->addr, tree->kids[0]->addr, tree->kids[1]->addr);
}

static void tree_genRelExpr(Tree *tree) {
  const char *op = "ERROR";
  switch (tree->kids[1]->tok.cat) {
    case '<':
      op="BLT";
      break;
    case '>':
      op="BGT";
      break;
    case LESSTHANOREQUAL:
      op="BLE";
      break;
    case GREATERTHANOREQUAL:
      op="BGE";
      break;
    default:
      break;
  }

  tree_copyIcode(tree, tree->kids[0]);
  tree_copyIcode(tree, tree->kids[2]);

  tree_addCode(tree, op, 3, tree->onTrue, tree->kids[0]->addr, tree->kids[2]->addr);
  tree_addCode(tree, "GOTO", 1, tree->onFalse);
}

static void tree_genWhileStmt(Tree *tree) {
  tree_addCode(tree, "LAB", 1, tree->kids[0]->first);
  tree_copyIcode(tree, tree->kids[0]);
  tree_addCode(tree, "LAB", 1, tree->kids[0]->onTrue);
  tree_copyIcode(tree, tree->kids[1]);
  tree_addCode(tree, "GOTO", 1, tree->kids[0]->first);
}

static void tree_genIfThenStmt(Tree *tree) {
  tree_copyIcode(tree, tree->kids[0]);
  tree_addCode(tree, "LAB", 1, tree->kids[0]->onTrue);
  tree_copyIcode(tree, tree->kids[1]);
}

static void tree_genAssignment(Tree *tree) {
  tree->addr = tree->kids[0]->addr;
  tree_copyIcode(tree, tree->kids[0]);
  tree_copyIcode(tree, tree->kids[2]);
  tree_addCode(tree, "ASN", 2, tree->addr, tree->kids[2]->addr);
}

static void tree_genMethodCall(Tree *tree) {
  int nparms = 0;
  if (tree->kids[1]) {
    tree_copyIcode(tree, tree->kids[1]);
    Tree *k = tree->kids[1];
    while (!strcmp("ArgList", k->sym)) {
      tree_addCode(tree, "PARM", 1, k->kids[1]->addr);
      k = k->kids[0];
      nparms++;
    }
    tree_addCode(tree, "PARM", 1, k->addr);
    nparms++;
  }

  if (!strcmp("QualifiedName", tree->kids[0]->sym)) {
    tree_copyIcode(tree, tree->kids[0]);
    tree_addCode(tree, "PARM", 1, tree->kids[0]->kids[0]->addr);
  } else {
    tree_addCode(tree, "PARM", 1, tac_CreateAddress("self", 0));
  }

  tree_addCode(tree, "CALL", 2, tree->kids[0]->addr, tac_CreateAddress("imm", nparms));
}

static void tree_genMethodDecl(Tree *tree) {
  tree_addCode(tree, "proc", 1, tac_CreateAddress(tree->kids[0]->kids[1]->kids[0]->tok.text, 0));
  for (int i=0; i<tree->nkids; i++) {
    tree_copyIcode(tree, tree->kids[i]);
  }

  tree_addCode(tree, "LAB", 1, tree->follow);
  tree_addCode(tree, "RET", 0);
  tree_addCode(tree, "end", 0);
}

static void tree_genQualifiedName(Tree *tree) {
  SymTabEntry *ste;
  ClassType *ct;
  tree_copyIcode(tree, tree->kids[0]);

  if (tree->typ && tree->typ->basetype == METHOD_TYPE) {// no icode, compile-time method resolution
    char *s = malloc(100);
    sprintf(s, "%s__%s", typeinfo_Name(tree->kids[0]->typ), tree->kids[1]->tok.text);
    tree->addr = tac_CreateAddress(s, 0);
  } else {
    tree->addr = tree_genLocal(tree);
    if (tree->kids[0]->typ && tree->kids[0]->typ->basetype == ARRAY_TYPE) { // array.length
      tree_addCode(tree, "ASIZE", 2, tree->addr, tree->kids[0]->addr);
    } else if (
      tree->kids[0]->typ &&
      tree->kids[0]->typ->basetype == CLASS_TYPE &&
      (ct = (ClassType*)tree->kids[0]->typ) &&
      (ste = symtab_LookupEntry(ct->st, tree->kids[1]->tok.text))
    ) {
      // lookup address within class
      if (!tree->kids[1]->addr)
        tree->kids[1]->addr = ste->addr;

      tree_addCode(tree, "FIELD", 3, tree->addr, tree->kids[0]->addr, tree->kids[1]->addr);
    }
  }
}

static void tree_genToken(Tree *tree) {
  switch (tree->tok.cat) {
    case IDENTIFIER: {
      SymTabEntry *ste;
      ste = symtab_LookupEntry(tree->symTab, tree->tok.text);
      if (ste) {
        tree->addr = ste->addr;
      }
      break;
    }
    case INTLIT: {
      tree->addr = tac_CreateAddress("imm", atoi(tree->tok.text));
      break;
    }
    case STRINGLIT: {
      symtab_InsertEntry(string_st, tree->tok.text, true, NULL, (TypeInfo*)typeinfo_StringType());
      tree->addr = symtab_LookupEntry(string_st, tree->tok.text)->addr;
      break;
    }
    // ...
    default:
      break;
  }
}

static Address *tree_genLocal(Tree *tree) {
  return symtab_Genlocal(tree->symTab);
}

static Address *tree_genLabel(Tree *tree) {
  return tac_CreateAddress("lab", serial_GetId());
}

static void tree_addCode(Tree *tree, const char *op, int nop, ...) {
  va_list ap;
  va_start(ap, nop);

  Tac *tac = NULL;
  Address *addr1, *addr2, *addr3;
  switch(nop) {
    case 3:
      addr1 = va_arg(ap, Address*);
      addr2 = va_arg(ap, Address*);
      addr3 = va_arg(ap, Address*);
      tac = tac_CreateTac(op, addr1, addr2, addr3);
      break;
    case 2:
      addr1 = va_arg(ap, Address*);
      addr2 = va_arg(ap, Address*);
      tac = tac_CreateTac(op, addr1, addr2, NULL);
      break;
    case 1:
      addr1 = va_arg(ap, Address*);
      tac = tac_CreateTac(op, addr1, NULL, NULL);
      break;
    case 0:
      tac = tac_CreateTac(op, NULL, NULL, NULL);
      break;
    default:
      printf("semantic error: gen(): wrong # of arguments\n");
      exit(1);
  }

  va_end(ap);

  TacListNode *tacListNode = malloc(sizeof(TacListNode));
  tacListNode->tac = tac;
  dlist_push_tail(&tree->icode, (dlist_node*)tacListNode);
  tree->ncode++;
}

static void tree_addStringConst(const HTableNode *node, void *arg, void *local_arg) {
  SymTabEntryNode entryNode = (SymTabEntryNode)node;
  Tree *tree = (Tree*)local_arg;
  if (!entryNode->addr) {
    printf("null label in stringtab\n");
    exit(1);
  }

  tree_addCode(tree, "LAB", 1, entryNode->addr);
  tree_addCode(tree, "string", 1, tac_CreateAddress(entryNode->sym, 0));
}

static void tree_addGlobal(const HTableNode *node, void *arg, void *local_arg) {
  SymTabEntryNode entryNode = (SymTabEntryNode)node;
  Tree *tree = (Tree*)local_arg;

  tree_addCode(tree, "global", 2, entryNode->addr, tac_CreateAddress(entryNode->sym, 0));
}

static void tree_copyIcode(Tree *dest, Tree *src) {
  dlist_iter iter;
  TacListNode *listNode, *newListNode;

  dlist_foreach(iter, &src->icode) {
    listNode = (TacListNode*)iter.cur;
    newListNode = malloc(sizeof(TacListNode));
    newListNode->tac = listNode->tac;
    dlist_push_tail(&dest->icode, (dlist_node*)newListNode);
    dest->ncode++;
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
