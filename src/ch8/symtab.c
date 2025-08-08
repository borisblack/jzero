#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"

typedef struct MkClsArgs MkClsArgs;

struct MkClsArgs {
  uint fIdx;
  uint nfields;
  Parameter **fields;
  uint mIdx;
  uint nmethods;
  Parameter **methods;
};

static bool symtab_keyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg);
static uint32 symtab_hashFunc(const HTableNode* a_, void *arg);
static void* symtab_allocFunc(size_t size, void *arg);
static void symtab_freeFunc(void* mem, void *arg);
static void symtab_printEntry(const HTableNode *node, void *arg, void *local_arg);
static void symtab_countFields(const HTableNode *node, void *arg, void *local_arg);
static void symtab_mkFields(const HTableNode *node, void *arg, void *local_arg);
static const char *scope(SymTabScope scope);

SymTab *symtab_Create(SymTabScope scope, SymTab *parent) {
  SymTab *symTab = malloc(sizeof(SymTab));
  symTab->scope = scope;
  symTab->parent = parent;
  
  /* Initialize symbol table */
  htable_create(
    &symTab->t,
    sizeof(SymTabEntry),
    symtab_hashFunc,
    symtab_keyeqFunc,
    symtab_allocFunc,
    symtab_freeFunc,
    NULL,
    NULL
  );

  return symTab;
}

void symtab_InsertEntry(SymTab *symTab, const char *sym, bool isConst, SymTab *sub, TypeInfo *typ) {
  SymTabEntry newEntry = {
    .sym = sym,
    .isConst = isConst,
    .parent_st = symTab,
    .st = sub,
    .typ = typ
  };
  SymTabEntryNode existingEntryNode;
  bool isNewNode;

  existingEntryNode = (SymTabEntryNode)htable_find(&symTab->t, (HTableNode*)&newEntry);
  if (existingEntryNode) {
    printf("semantic error: redeclaration of %s\n", sym);
    exit(1);
  } else {
    if (sub)
      sub->parent = symTab;

    htable_insert(&symTab->t, (HTableNode*)&newEntry, &isNewNode);
  }
}

SymTabEntryNode symtab_LookupEntry(SymTab *symTab, char *sym) {
  SymTabEntry searchingEntry = {
    .sym = sym,
    .parent_st = symTab
  };
  SymTabEntryNode existingEntryNode;

  existingEntryNode = (SymTabEntryNode)htable_find(&symTab->t, (HTableNode*)&searchingEntry);
  if (existingEntryNode)
    return existingEntryNode;

  if (symTab->parent)
    return symtab_LookupEntry(symTab->parent, sym);

  return NULL;
}

const ClassType *symtab_MkCls(char *name, SymTab *symTab) {
  MkClsArgs args = {
    .fIdx = 0,
    .nfields = 0,
    .fields = NULL,
    .mIdx = 0,
    .nmethods = 0,
    .methods = NULL
  };

  htable_foreach(&symTab->t, symtab_countFields, &args);

  if (args.nfields > 0)
    args.fields = calloc(args.nfields, sizeof(Parameter*));

  if (args.nmethods > 0)
    args.methods = calloc(args.nmethods, sizeof(Parameter*));

  htable_foreach(&symTab->t, symtab_mkFields, &args);

  return typeinfo_CreateClassType(name, symTab, args.nfields, args.fields, args.nmethods, args.methods);
}

void symtab_Print(SymTab *symTab, int level) {
  for(int i=0; i<level; i++)
    printf(" ");

  printf("%s - %ld symbols\n", scope(symTab->scope), htable_nitems(&symTab->t));

  int nextLevel = level+1;
  htable_foreach(&symTab->t, symtab_printEntry, &nextLevel);
}

void symtab_Free(SymTab *symTab) {
  if (!symTab)
    return;
    
  htable_free_items(&symTab->t);
  free(symTab);
}

/* Symbol table entry compare func */
static bool symtab_keyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg) {
	SymTabEntryNode a = (SymTabEntryNode)a_;
	SymTabEntryNode b = (SymTabEntryNode)b_;
	return strcmp(a->sym, b->sym) == 0;
}

/* Symbol table entry hash func */
static uint32 symtab_hashFunc(const HTableNode* a_, void *arg) {
	SymTabEntryNode a = (SymTabEntryNode)a_;
	return htable_default_hash(a->sym, strlen(a->sym));
}

/* Symbol table entry alloc func */
static void* symtab_allocFunc(size_t size, void *arg) {
	return malloc(size);
}

/* Symbol table entry free func */
static void symtab_freeFunc(void* mem, void *arg) {
  SymTabEntryNode entryNode = (SymTabEntryNode)mem;

  typeinfo_Free(entryNode->typ); // detached type

	free(mem);
}

static void symtab_printEntry(const HTableNode *node, void *arg, void *local_arg) {
  SymTabEntryNode entryNode = (SymTabEntryNode)node;
  int level = *(int*)local_arg;
  for(int i=0; i<level; i++)
    printf(" ");

  printf("%s", entryNode->sym);
  if (entryNode->isConst)
    printf(" (const)");

  printf("\n");
  if (entryNode->st)
    symtab_Print(entryNode->st, level+1);
}

static void symtab_countFields(const HTableNode *node, void *arg, void *local_arg) {
  SymTabEntryNode entryNode = (SymTabEntryNode)node;
  MkClsArgs *args = (MkClsArgs*)local_arg;
  if (entryNode->typ->basetype == METHOD_TYPE)
    args->nmethods++;
  else
    args->nfields++;
}

static void symtab_mkFields(const HTableNode *node, void *arg, void *local_arg) {
  SymTabEntryNode entryNode = (SymTabEntryNode)node;
  MkClsArgs *args = (MkClsArgs*)local_arg;
  if (entryNode->typ->basetype == METHOD_TYPE)
    args->methods[args->mIdx++] = typeinfo_CreateParameter(entryNode->sym, entryNode->typ);
  else
    args->fields[args->fIdx++] = typeinfo_CreateParameter(entryNode->sym, entryNode->typ);
}

static const char *scope(SymTabScope scope) {
  switch (scope) {
  case GLOBAL_SCOPE:
    return "global";
  case CLASS_SCOPE:
    return "class";
  case METHOD_SCOPE:
    return "method";
  default:
    return "unknown";
  }
}
