#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symtab.h"

static bool symtab_keyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg);
static uint32 symtab_hashFunc(const HTableNode* a_, void *arg);
static void* symtab_allocFunc(size_t size, void *arg);
static void symtab_freeFunc(void* mem, void *arg);
static void symtab_printEntry(const HTableNode *node, void *arg, void *local_arg);

SymTab *symtab_Create(char *scope, SymTab *parent) {
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

void symtab_InsertEntry(SymTab *symTab, char *sym, bool isConst, SymTab *sub) {
  SymTabEntry newEntry;
  SymTabEntryNode existingEntryNode;
  bool isNewNode;

  newEntry.sym = sym;
  newEntry.isConst = isConst;
  newEntry.parent_st = symTab;
  newEntry.st = sub;

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
  SymTabEntry searchingEntry;
  SymTabEntryNode existingEntryNode;
  searchingEntry.sym = sym;
  searchingEntry.parent_st = symTab;

  return (SymTabEntryNode)htable_find(&symTab->t, (HTableNode*)&searchingEntry);
}

void symtab_Print(SymTab *symTab, int level) {
  for(int i=0; i<level; i++)
    printf(" ");

  printf("%s - %ld symbols\n", symTab->scope, htable_nitems(&symTab->t));

  int nextLevel = level+1;
  htable_foreach(&symTab->t, symtab_printEntry, &nextLevel);
}

void symtab_Free(SymTab *symTab) {
  htable_free_items(&symTab->t);
  free(symTab);
}

/* Symbol table entry compare func */
static bool symtab_keyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg) {
	SymTabEntryNode a = (SymTabEntryNode)a_;
	SymTabEntryNode b = (SymTabEntryNode)b_;
	return strcmp(a->sym, b->sym) == 0 && strcmp(a->parent_st->scope, b->parent_st->scope) == 0;
}

/* Symbol table entry hash func */
static uint32 symtab_hashFunc(const HTableNode* a_, void *arg) {
	SymTabEntryNode a = (SymTabEntryNode)a_;
	return htable_default_hash(a->sym, strlen(a->sym)) + htable_default_hash(a->parent_st->scope, strlen(a->parent_st->scope));
}

/* Symbol table entry alloc func */
static void* symtab_allocFunc(size_t size, void *arg) {
	return malloc(size);
}

/* Symbol table entry free func */
static void symtab_freeFunc(void* mem, void *arg) {
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

static void symtab_CountFields(const HTableNode *node, void *arg, void *local_arg) {
  SymTabEntryNode entryNode = (SymTabEntryNode)node;
}

static void symtab_MkFields(const HTableNode *node, void *arg, void *local_arg) {
  SymTabEntryNode entryNode = (SymTabEntryNode)node;
}

