#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"

SymTabEntry::SymTabEntry(const char *sym, bool isConst, SymTab *parent_st, SymTab *st, shared_ptr<TypeInfo> typ, shared_ptr<Address> addr) {
  this->sym = sym;
  this->isConst = isConst;
  this->parent_st = parent_st;
  this->st = st;
  this->typ = typ;
  this->addr = addr;
}

SymTab::SymTab(SymTabScope scope, SymTab *parent) {
  this->scope = scope;
  this->parent = parent;
  count = 0;
}

SymTab::~SymTab() {
  map<string, SymTabEntry*>::iterator it;
  SymTabEntry* entry;
  for (it = t.begin(); it != t.end(); it++) {
    entry = it->second;
    delete entry;
  }
  t.clear();
}

void SymTab::insertEntry(const char *sym, bool isConst, SymTab *sub, shared_ptr<TypeInfo> typ) {
  if (t[sym]) {
    printf("semantic error: redeclaration of %s\n", sym);
    exit(1);
  } else {
    if (sub)
      sub->parent = this;

    SymTabEntry *newEntry = new SymTabEntry(sym, isConst, this, sub, typ, make_shared<Address>(scopeName(), this->count));
    t[sym] = newEntry;

    int len = strlen(sym);
    while(len > 0) {
      count += 8;
      len -= 8;
    }
  }
}

SymTabEntry *SymTab::lookupEntry(const char *sym) {
  map<string, SymTabEntry*>::iterator it = t.find(sym);
  if (it != t.end())
    return it->second;

  if (parent)
    return parent->lookupEntry(sym);

  return NULL;
}

size_t SymTab::size() {
  return t.size();
}

shared_ptr<ClassType> SymTab::mkCls(char *name) {
  uint fIdx = 0, mIdx = 0;
  uint nfields = 0, nmethods = 0;
  Parameter **fields = NULL, **methods = NULL;
  map<string, SymTabEntry*>::iterator it;
  SymTabEntry* entry;

  for (it = t.begin(); it != t.end(); it++) {
    entry = it->second;
    if (entry->typ->basetype == METHOD_TYPE)
      nmethods++;
    else
      nfields++;
  }

  if (nfields > 0)
    fields = (Parameter**)calloc(nfields, sizeof(Parameter*));

  if (nmethods > 0)
    methods = (Parameter**)calloc(nmethods, sizeof(Parameter*));

  for (it = t.begin(); it != t.end(); it++) {
    entry = it->second;
    if (entry->typ->basetype == METHOD_TYPE)
      methods[mIdx++] = new Parameter(entry->sym, entry->typ);
    else
      fields[fIdx++] = new Parameter(entry->sym, entry->typ);
  }

  return make_shared<ClassType>(name, this, nfields, fields, nmethods, methods);
}

shared_ptr<Address> SymTab::genLocal() {
    char *s = (char*)malloc(25);
    sprintf(s, "__local$%u", count);
    insertEntry(s, false, NULL, make_shared<IntType>());
    return lookupEntry(s)->addr;
}

void SymTab::print(int level) {
  map<string, SymTabEntry*>::iterator it;
  SymTabEntry* entry;

  for(int i=0; i<level; i++)
    printf(" ");

  printf("%s - %ld symbols\n", scopeName(), t.size());

  for (it = t.begin(); it != t.end(); it++) {
    for(int i=0; i<level; i++)
      printf(" ");

    entry = it->second;
    printf("%s", entry->sym);
    if (entry->isConst)
      printf(" (const)");

    printf("\n");
    if (entry->st)
      entry->st->print(level+1);
  }
}

const char *SymTab::scopeName() {
  switch (scope) {
  case GLOBAL_SCOPE:
    return "global";
  case CLASS_SCOPE:
    return "class";
  case METHOD_SCOPE:
    return "method";
  case STRINGS_SCOPE:
    return "strings";
  default:
    return "unknown";
  }
}
