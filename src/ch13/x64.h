#ifndef X64_H
#define X64_H

#include <stdio.h>
#include <vector>
#include <memory>
#include "c.h"
#include "tac.h"
#include "symtab.h"

using namespace std;

class X64Loc {
  char *reg = nullptr;
  union {
    int ival;
    char *sval;
  } offset;
  int mode;
  public:
    X64Loc(const char *reg);
    X64Loc(int offset);
    X64Loc(const char *reg, int offset);
    X64Loc(const char *reg, const char *offset);
    ~X64Loc();
    // X64loc::X64loc(Address *addr);
    char *str(char *dest);
};

class X64Instr {
  X64Loc *opnd1 = nullptr, *opnd2 = nullptr;
  public:
    char *op;
    X64Instr(const char *op, X64Loc *src, X64Loc *dst);
    X64Instr(const char *op, X64Loc *opnd) : X64Instr(op, opnd, nullptr) {}
    X64Instr(const char *op) : X64Instr(op, nullptr, nullptr) {}
    ~X64Instr();
    void print(FILE *f);
    void print();
};

class RegUse {
  public:
    int offset;
    const char *reg;
    bool loaded, dirty;
    RegUse(const char *reg, int offset);
};

class X64Generator {
  RegUse *regs[11] = {
    new RegUse("%rdi", -8),
    new RegUse("%rsi", -16),
    new RegUse("%rdx", -24),
    new RegUse("%rcx", -32),
    new RegUse("%r8", -40),
    new RegUse("%r9",-48),
    new RegUse("%r10", -56),
    new RegUse("%r11", -64),
    new RegUse("%r12", -72),
    new RegUse("%r13", -80),
    new RegUse("%r14", -88)
  };
  vector<X64Instr*> xcode;
  bool methodAddrPushed = false;
  X64Instr *xgen(const char *opt);
  X64Instr *xgen(const char *op, Address *src, Address *dst);
  X64Instr *xgen(const char *op, Address *opnd);
  X64Instr *xgen(const char *op, Address *src, const char *dst);
  X64Instr *xgen(const char *op, const char *src, Address *dst);
  X64Instr *xgen(const char *op, const char *src, const char *dst);
  X64Instr *xgen(const char *op, const char *opnd);
  X64Loc *createX64Loc(Address *addr);
  X64Loc *loadReg(Address *addr);
  X64Instr *loadReg(RegUse *reg);
  X64Instr *saveReg(RegUse *reg);
  void genParm(int n, Address *addr);
  void writeStrings(FILE *f, SymTab *strTab);
  void writeInstrs(FILE *f);
  public:
    X64Generator();
    ~X64Generator();
    void genCode(vector<shared_ptr<Tac>> icode);
    void writeCode(const char *filename, const char *origFilename, SymTab *strTab);
};

#endif /* X64_H */