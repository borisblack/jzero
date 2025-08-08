#ifndef TAC_H
#define TAC_H

#include "c.h"

typedef struct Address Address;
typedef struct Tac Tac;

struct Address {
  char *region;
  uint32 offset;
};

struct Tac {
  char *op;
  Address *op1;
  Address *op2;
  Address *op3;
};

void tac_Init();
Address *tac_CreateAddress(const char *region, uint32 offset);
void tac_FreeAddress(Address *addr);
Tac *tac_CreateTac(char *op, Address *op1, Address *op2, Address *op3);
void tac_PrintTac(Tac *tac);
void tac_FreeTac(Tac *tac);

#endif /* TAC_H */