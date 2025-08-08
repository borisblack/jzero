#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "htable.h"
#include "tac.h"

typedef struct AddressEntry AddressEntry;
typedef struct AddressEntry *AddressEntryNode;
typedef struct TacEntry TacEntry;
typedef struct TacEntry *TacEntryNode;

struct AddressEntry {
  HTableNode node;
  Address *addr;
};

struct TacEntry {
  HTableNode node;
  Tac *tac;
};

static HTable addressRegistry, tacRegistry;

static void *tac_printAddress(Address *addr);
static uint32 tac_addrHashFunc(const HTableNode* a_, void *arg);
static bool tac_addrKeyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg);
static void *tac_addrAllocFunc(size_t size, void *arg);
static void tac_addrFreeFunc(void* mem, void *arg);
static uint32 tac_tacHashFunc(const HTableNode* a_, void *arg);
static bool tac_tacKeyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg);
static void *tac_tacAllocFunc(size_t size, void *arg);
static void tac_tacFreeFunc(void* mem, void *arg);

void tac_Init() {
  htable_create(
    &addressRegistry,
    sizeof(AddressEntry),
    tac_addrHashFunc,
    tac_addrKeyeqFunc,
    tac_addrAllocFunc,
    tac_addrFreeFunc,
    NULL,
    NULL
  );

  htable_create(
    &tacRegistry,
    sizeof(TacEntry),
    tac_tacHashFunc,
    tac_tacKeyeqFunc,
    tac_tacAllocFunc,
    tac_tacFreeFunc,
    NULL,
    NULL
  );
}

Address *tac_CreateAddress(const char *region, uint32 offset) {
  Address *addr = malloc(sizeof(Address));
  addr->region = strdup(region);
  addr->offset = offset;

  AddressEntry newEntry = {
    .addr = addr
  };
  bool isNewNode;
  htable_insert(&addressRegistry, (HTableNode*)&newEntry, &isNewNode);

  return addr;
}

void tac_FreeAddress(Address *addr) {
  if (!addr)
    return;

  AddressEntry searchingEntry = {
    .addr = addr
  };
  if (htable_find(&addressRegistry, (HTableNode*)&searchingEntry)) {
    free(addr->region);
    free(addr);
    htable_delete(&addressRegistry, (HTableNode*)&searchingEntry);
  }
}

Tac *tac_CreateTac(char *op, Address *op1, Address *op2, Address *op3) {
  Tac *tac = malloc(sizeof(Tac));
  tac->op = op;
  tac->op1 = op1;
  tac->op2 = op2;
  tac->op3 = op3;

  TacEntry newEntry = {
    .tac = tac
  };
  bool isNewNode;
  htable_insert(&tacRegistry, (HTableNode*)&newEntry, &isNewNode);

  return tac;
}

void tac_PrintTac(Tac *tac) {
  if (!strcmp("proc", tac->op)) {
    printf("%s\t%s,0,0\n", tac->op, tac->op1->region);
  } else if (!strcmp("end", tac->op) || !strcmp(".code", tac->op) || !strcmp(".global", tac->op) || !strcmp(".string", tac->op)) {
    printf("%s\n", tac->op);
  } else if (!strcmp("LAB", tac->op)) {
    printf("L%u:\n", tac->op1->offset);
  } else {
    printf("\t%s\t", tac->op);

    if (tac->op1)
      tac_printAddress(tac->op1);

    if (tac->op2) {
      printf(",");
      tac_printAddress(tac->op2);
    }

    if (tac->op3) {
      printf(",");
      tac_printAddress(tac->op3);
    }

    printf("\n");
  }
}

void tac_FreeTac(Tac *tac) {
  if (!tac)
    return;

  TacEntry searchingEntry = {
    .tac = tac
  };
  if (htable_find(&tacRegistry, (HTableNode*)&searchingEntry)) {
    // free(tac->op);
    free(tac);
    htable_delete(&tacRegistry, (HTableNode*)&searchingEntry);
  }
}

static void *tac_printAddress(Address *addr) {
  if (!strcmp("lab", addr->region)) {
    printf("L%u", addr->offset);
  } else if (
    !strcmp("loc", addr->region) ||
    !strcmp("imm", addr->region) ||
    !strcmp("method", addr->region) ||
    !strcmp("global", addr->region) ||
    !strcmp("class", addr->region) ||
    !strcmp("strings", addr->region)
  ) {
    char *regaddr = !strcmp("method", addr->region) ? "loc" : addr->region;
    printf("%s:%u", regaddr, addr->offset);
  } else {
    printf("%s", addr->region);
  }
}

/* Address entry hash func */
static uint32 tac_addrHashFunc(const HTableNode* a_, void *arg) {
	AddressEntryNode a = (AddressEntryNode)a_;
	return (ulong)a->addr;
}

/* Address entry compare func */
static bool tac_addrKeyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg) {
	AddressEntryNode a = (AddressEntryNode)a_;
	AddressEntryNode b = (AddressEntryNode)b_;
	return a->addr == b->addr;
}

/* Address entry alloc func */
static void *tac_addrAllocFunc(size_t size, void *arg) {
	return malloc(size);
}

/* Address entry free func */
static void tac_addrFreeFunc(void* mem, void *arg) {
  free(mem);
}

/* TAC entry hash func */
static uint32 tac_tacHashFunc(const HTableNode* a_, void *arg) {
	TacEntryNode a = (TacEntryNode)a_;
	return (ulong)a->tac;
}

/* TAC entry compare func */
static bool tac_tacKeyeqFunc(const HTableNode* a_, const HTableNode* b_, void *arg) {
	TacEntryNode a = (TacEntryNode)a_;
	TacEntryNode b = (TacEntryNode)b_;
	return a->tac == b->tac;
}

/* TAC entry alloc func */
static void *tac_tacAllocFunc(size_t size, void *arg) {
	return malloc(size);
}

/* TAC entry free func */
static void tac_tacFreeFunc(void* mem, void *arg) {
  TacEntryNode tacEntryNode = (TacEntryNode)mem;

  if (tacEntryNode->tac) {
    tac_FreeAddress(tacEntryNode->tac->op1);
    tac_FreeAddress(tacEntryNode->tac->op2);
    tac_FreeAddress(tacEntryNode->tac->op3);
  }
  free(mem);
}