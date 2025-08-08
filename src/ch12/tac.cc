#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tac.h"

Address::Address(const char *region, uint32 offset) {
  this->region = strdup(region);
  this->offset = offset;
}

Address::Address(const Address &ob) {
  region = strdup(ob.region);
  offset = ob.offset;
}

Address::~Address() {
  free(region);
}

const char *Address::regaddr() {
  return !strcmp("method", region) ? "loc" : (const char*)region;
}

char *Address::str(char *dest) {
  if (!strcmp("lab", region))
    sprintf(dest, "L%u", offset);
  else
    sprintf(dest, "%s:%u", regaddr(), offset);

  return dest;
}

void Address::print() {
  if (!strcmp("lab", region)) {
    printf("L%u", offset);
  } else if (
    !strcmp("loc", region) ||
    !strcmp("imm", region) ||
    !strcmp("method", region) ||
    !strcmp("global", region) ||
    !strcmp("class", region) ||
    !strcmp("strings", region)
  ) {
    const char *regaddr = !strcmp("method", region) ? "loc" : region;
    printf("%s:%u", regaddr, offset);
  } else {
    printf("%s", region);
  }
}

Tac::Tac(const char *op, shared_ptr<Address> op1, shared_ptr<Address> op2, shared_ptr<Address> op3) {
  this->op = op;
  this->op1 = op1;
  this->op2 = op2;
  this->op3 = op3;
}

Tac::Tac(const Tac &ob) {
  op = ob.op;
  op1 = ob.op1;
  op2 = ob.op2;
  op3 = ob.op3;
}

Tac::~Tac() {}

void Tac::print() {
  if (!strcmp("proc", op)) {
    printf("%s\t%s,0,0\n", op, op1->region);
  } else if (!strcmp("end", op) || !strcmp(".code", op) || !strcmp(".global", op) || !strcmp(".string", op)) {
    printf("%s\n", op);
  } else if (!strcmp("LAB", op)) {
    printf("L%u:\n", op1->offset);
  } else {
    printf("\t%s\t", op);

    if (op1)
      op1->print();

    if (op2) {
      printf(",");
      op2->print();
    }

    if (op3) {
      printf(",");
      op3->print();
    }

    printf("\n");
  }
}
