#ifndef TREE_H
#define TREE_H

#include <memory>
#include <vector>
#include <stdio.h>
#include "symtab.h"
#include "typeinfo.h"
#include "tac.h"

class Token {
  public:
    int id;
    int cat;
    char *text;
    int lineno;
    int colno;
    std::shared_ptr<TypeInfo> typ;

    Token(int cat, const char *text, int lineno, int colno);
    ~Token();
    const char *name();
    std::shared_ptr<TypeInfo> catType();
};

class Tree {
public:
  int id;
  const char *sym;
  int rule;
  Token *tok = NULL;
  int nkids = 0;
  Tree **kids = NULL;
  bool isConst = false;
  SymTab *symTab = NULL;
  std::shared_ptr<TypeInfo> typ;
  int ncode = 0;
  std::vector<std::shared_ptr<Tac>> icode;
  std::shared_ptr<Address> addr = NULL;
  std::shared_ptr<Address> first = NULL;
  std::shared_ptr<Address> follow = NULL;
  std::shared_ptr<Address> onTrue = NULL;
  std::shared_ptr<Address> onFalse = NULL;

  Tree(const char *sym, int rule, Token *tok);
  Tree(const char *sym, int rule, int nkids, Tree **kids);
  ~Tree();
  std::shared_ptr<TypeInfo> tokenType();
  void print(int level);
  void printGraph(FILE *f);
  void calcIsConst();
  void mkSymTables(SymTab *stab);
  void populateSymTables();
  void checkSymTables();
  void calcType();
  void assignType(std::shared_ptr<TypeInfo> typeInfo);
  void mkCls();
  void checkType(bool inCodeBlock);
  void genFirst();
  void genFollow();
  void genTargets();
  void genCode();
  void printIcode();
private:
  void printLeaf(FILE *f);
  void printBranch(FILE *f);
  char *prettyPrintName(char *dest);
  void insertVardeclarator(Tree *vd);
  void checkCodeblocks();
  void checkBlock();
  bool checkKids(bool inCodeBlock);
  std::shared_ptr<TypeInfo> checkTypes(std::shared_ptr<TypeInfo> op1, std::shared_ptr<TypeInfo> op2);
  const char *getOp();
  Tree *findToken();
  std::shared_ptr<TypeInfo> dequalify();
  std::vector<std::shared_ptr<TypeInfo>> *mksig();
  void cksig(MethodType *sig);
  std::shared_ptr<Address> genLabel();
  void genClassDecl();
  void genAddExpr();
  void genMulExpr();
  void genRelExpr();
  void genWhileStmt();
  void genIfThenStmt();
  void genAssignment();
  void genMethodCall();
  void genMethodDecl();
  void genQualifiedName();
  void genToken();
  std::shared_ptr<Address> genLocal();
  void addCode(const char *op, std::shared_ptr<Address> addr1, std::shared_ptr<Address> addr2, std::shared_ptr<Address> addr3);
  void addCode(const char *op, std::shared_ptr<Address> addr1, std::shared_ptr<Address> addr2);
  void addCode(const char *op, std::shared_ptr<Address> addr1);
  void addCode(const char *op);
  void copyIcodeFrom(Tree *src);
};

#endif /* TREE_H */
