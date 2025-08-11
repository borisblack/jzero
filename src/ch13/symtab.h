#ifndef SYMTAB_H
#define SYMTAB_H

#include <string>
#include <map>
#include <memory>
#include <c.h>
#include "typeinfo.h"
#include "tac.h"

using namespace std;

enum SymTabScope {
  GLOBAL_SCOPE,
  CLASS_SCOPE,
  METHOD_SCOPE,
  STRINGS_SCOPE
};

class SymTabEntry {
public:
  const char *sym;
  bool isConst;
  SymTab *parent_st;
  SymTab *st;
  shared_ptr<TypeInfo> typ;
  shared_ptr<Address> addr;
  SymTabEntry(const char *sym, bool isConst, SymTab *parent_st, SymTab *st, shared_ptr<TypeInfo> typ, shared_ptr<Address> addr);
  SymTabEntry(const char *sym, bool isConst, SymTab *parent_st) : SymTabEntry(sym, isConst, parent_st, NULL, NULL, NULL) {}
};

class SymTab {
  const char *scopeName();
public:
  SymTabScope scope;
  SymTab *parent;
  map<string, SymTabEntry*> t;
  uint count;
  SymTab(SymTabScope scope) : SymTab(scope, NULL) {}
  SymTab(SymTabScope scope, SymTab *parent);
  ~SymTab();
  void insertEntry(const char *sym, bool isConst, SymTab *sub, shared_ptr<TypeInfo> typ);
  SymTabEntry *lookupEntry(const char *sym);
  size_t size();
  shared_ptr<ClassType> mkCls(char *name);
  shared_ptr<Address> genLocal();
  void print(int level);
};

#endif /* SYMTAB_H */
