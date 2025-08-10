#ifndef TREE_H
#define TREE_H

#include <memory>
#include <vector>
#include <stdio.h>
#include "symtab.h"
#include "typeinfo.h"
#include "tac.h"

using namespace std;

class Token {
  public:
    int id;
    int cat;
    char *text;
    int lineno;
    int colno;
    shared_ptr<TypeInfo> typ;

    Token(int cat, const char *text, int lineno, int colno);
    ~Token();
    const char *name();
    shared_ptr<TypeInfo> catType();
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
    shared_ptr<TypeInfo> typ;
    int ncode = 0;
    vector<shared_ptr<Tac>> icode;
    shared_ptr<Address> addr = NULL;
    shared_ptr<Address> first = NULL;
    shared_ptr<Address> follow = NULL;
    shared_ptr<Address> onTrue = NULL;
    shared_ptr<Address> onFalse = NULL;
  
    Tree(const char *sym, int rule, Token *tok);
    Tree(const char *sym, int rule, int nkids, Tree **kids);
    ~Tree();
    shared_ptr<TypeInfo> tokenType();
    void print(int level);
    void printGraph(FILE *f);
    void calcIsConst();
    void mkSymTables(SymTab *stab);
    void populateSymTables();
    void checkSymTables();
    void calcType();
    void assignType(shared_ptr<TypeInfo> typeInfo);
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
    shared_ptr<TypeInfo> checkTypes(shared_ptr<TypeInfo> op1, shared_ptr<TypeInfo> op2);
    const char *getOp();
    Tree *findToken();
    shared_ptr<TypeInfo> dequalify();
    vector<shared_ptr<TypeInfo>> *mksig();
    void cksig(MethodType *sig);
    shared_ptr<Address> genLabel();
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
    shared_ptr<Address> genLocal();
    void addCode(const char *op, shared_ptr<Address> addr1, shared_ptr<Address> addr2, shared_ptr<Address> addr3);
    void addCode(const char *op, shared_ptr<Address> addr1, shared_ptr<Address> addr2);
    void addCode(const char *op, shared_ptr<Address> addr1);
    void addCode(const char *op);
    void copyIcodeFrom(Tree *src);
};

#endif /* TREE_H */
