#include "byc.h"
#include "string.h"

map<int, string> Byc::ops;
bool Byc::isOpsInit = false;

void Byc::initOps() {
  if (isOpsInit)
    return;

  ops[HALT] = "halt";
  ops[NOOP] = "noop";
  ops[ADD] = "add";
  ops[SUB] = "sub";
  ops[MUL] = "mul";
  ops[DIV] = "div";
  ops[MOD] = "mod";
  ops[NEG] = "neg";
  ops[PUSH] = "push";
  ops[POP] = "pop";
  ops[CALL] = "call";
  ops[RET] = "return";
  ops[GOTO] = "goto";
  ops[BIF] = "bif";
  ops[LT] = "lt";
  ops[LE] = "le";
  ops[GT] = "gt";
  ops[GE] = "ge";
  ops[EQ] = "eq";
  ops[NEQ] = "neq";
  ops[LOCAL] = "local";
  ops[LOAD] = "load";
  ops[STORE] = "store";
  ops[LABEL] = "LABEL";
  ops[STR] = "STRING";
  ops[CODE] = "CODE";
  ops[PROC] = "PROC";
  ops[GLOBAL] = "GLOBAL";
  ops[END] = "END";

  isOpsInit = true;
}

Byc::Byc(int op, Address *address) {
  this->op = op;
  addr(address);
}

void Byc::print(FILE *f) {
  char addr[25];
  fprintf(f, "\t%s %s", nameof(), addrof(addr));
}

void Byc::printb(FILE *f) {
  long x = opnd;
  fprintf(f, "%c", (char)op);
  fprintf(f, "%c", (char)opreg);
  for(int i = 0; i < 6; i++) {
    fprintf(f, "%c", (char)(x & 0xff));
    x = x>>8;
  }
}

uint Byc::printb(char *dest) {
  char *pCode = dest;
  long x = opnd;
  char c;
  c = (char)op;
  memcpy(pCode++, &c, 1);

  c = (char)opreg;
  memcpy(pCode++, &c, 1);
  for(int i = 0; i < 6; i++) {
    c = (char)(x & 0xff);
    memcpy(pCode++, &c, 1); // correct signed shift only from C++ 20
    x = x >> 8;
  }

  return pCode - dest;
}

void Byc::addr(Address *address) {
  if (!address) {
    opreg = R_NONE;
  }
  else if (!strcmp("method", address->region)) {
    opreg = R_STACK;
    opnd = address->offset;
  }
  else if (!strcmp("global", address->region)) {
    opreg = R_ABS;
    opnd = address->offset;
  }
  else if (!strcmp("const", address->region)) {
    opreg = R_ABS;
    opnd = address->offset;
  }
  else if (!strcmp("lab", address->region)) {
    opreg = R_ABS;
    opnd = address->offset;
  }
  else if (!strcmp("obj", address->region)) {
    opreg = R_HEAP;
    opnd = address->offset;
  }
  else if (!strcmp("imm", address->region)) {
    opreg = R_IMM;
    opnd = address->offset;
  }
  else if (!strcmp("strings", address->region)) {
    opreg = R_IMM;
    opnd = address->offset + 24;
  }
}

const char *Byc::nameof() {
  initOps();
  return ops[op].c_str();
}

char *Byc::addrof(char *dest) {
  switch (opreg) {
    case R_NONE:
      strcpy(dest, "");
      break;
    case R_ABS:
      sprintf(dest, "@%lX", (ulong)opnd);
      break;
    case R_IMM:
      sprintf(dest, "%ld", opnd);
      break;
    case R_STACK:
      sprintf(dest, "stack:%ld", opnd);
      break;
    case R_HEAP:
      sprintf(dest, "heap:%ld", opnd);
      break;
    default:
      sprintf(dest, "%d:%ld", opreg, opnd);
      break;
  }

  return dest;
}