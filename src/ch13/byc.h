#ifndef BYC_H
#define BYC_H

#include <string>
#include <map>
#include <stdio.h>
#include "tac.h"

enum Op {
  HALT = 1,
  NOOP = 2,
  ADD = 3,
  SUB = 4,
  MUL = 5,
  DIV = 6,
  MOD = 7,
  NEG = 8,
  PUSH = 9,
  POP = 10,
  CALL = 11,
  RET = 12,
  GOTO = 13,
  BIF = 14,
  LT = 15,
  LE = 16,
  GT = 17,
  GE = 18,
  EQ = 19,
  NEQ = 20,
  LOCAL = 21,
  LOAD = 22,
  STORE = 23
};

enum Area {
  LABEL = 101,
  STR = 102,
  CODE = 103,
  PROC = 104,
  GLOBAL = 105,
  END = 106
};

enum Region {
  R_NONE = 0,
  R_ABS = 1,
  R_IMM = 2,
  R_STACK = 3,
  R_HEAP = 4
};

class Byc {
  static std::map<int, std::string> ops;
  static bool isOpsInit;
  static void initOps();
  void addr(Address *address);
  const char *nameof();
  char *addrof(char *dest);
public:
  int op, opreg;
  long opnd;
  Byc(int op, Address *address);
  void print(FILE *f);
  void printb(FILE *f);
  uint printb(char *dest);
};

#endif /* BYC_H */
