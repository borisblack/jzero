#ifndef SYMTAB_H
#define SYMTAB_H

#include <c.h>
#include "htable.h"
#include "typeinfo.h"

typedef enum SymTabScope SymTabScope;
typedef struct SymTabEntry SymTabEntry;
typedef struct SymTabEntry *SymTabEntryNode;
typedef struct SymTab SymTab;

enum SymTabScope {
  GLOBAL_SCOPE,
  CLASS_SCOPE,
  METHOD_SCOPE
};

struct SymTabEntry {
  HTableNode node;
  const char *sym;
  bool isConst;
  SymTab *parent_st;
  SymTab *st;
  TypeInfo *typ;
};

struct SymTab {
  SymTabScope scope;
  SymTab *parent;
  HTable t;
};

SymTab *symtab_Create(SymTabScope scope, SymTab *parent);
void symtab_InsertEntry(SymTab *symTab, char *sym, bool isConst, SymTab *sub, TypeInfo *typ);
SymTabEntryNode symtab_LookupEntry(SymTab *symTab, char *sym);
const ClassType *symtab_MkCls(char *name, SymTab *symTab);
void symtab_Print(SymTab *symTab, int level);
void symtab_Free(SymTab *symTab);

#endif /* SYMTAB_H */
