#ifndef SYMTAB_H
#define SYMTAB_H

#include <c.h>
#include "htable.h"

typedef struct SymTabEntry SymTabEntry;
typedef struct SymTabEntry *SymTabEntryNode;
typedef struct SymTab SymTab;

struct SymTabEntry {
  bool isConst;
  SymTab *parent_st;
  SymTab *st;
  const char *sym;
};

struct SymTab {
  const char *scope;
  SymTab *parent;
  HTable t;
};

SymTab *symtab_Create(char *scope, SymTab *parent);
void symtab_InsertEntry(SymTab *symTab, char *sym, bool isConst, SymTab *sub);
SymTabEntryNode symtab_LookupEntry(SymTab *symTab, char *sym);
void symtab_Print(SymTab *symTab, int level);
void symtab_Free(SymTab *symTab);

#endif /* SYMTAB_H */
