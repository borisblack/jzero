#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "x64.h"

X64Loc::X64Loc(const char *reg) {
  this->reg = strdup(reg);
  mode = 1;
}

X64Loc::X64Loc(int offset) {
  this->offset.ival = offset;
  mode=2;
}

X64Loc::X64Loc(const char *reg, int offset) {
  if (!strcmp("imm", reg)) {
    this->offset.ival = offset;
    mode = 5;
  }
  else if (!strcmp("lab", reg)) {
    this->offset.ival = offset;
    mode = 6;
  }
  else {
    this->reg = strdup(reg);
    this->offset.ival = offset;
    mode = 3;
  }
}

X64Loc::X64Loc(const char *reg, const char *offset) {
  this->reg = strdup(reg);
  this->offset.sval = strdup(offset);
  mode=4;
}

X64Loc::~X64Loc() {
  if (reg)
    free(reg);

  if (mode == 4)
    free(offset.sval);
}

char *X64Loc::str(char *dest) {
  switch (mode) {
    case 1:
      strcpy(dest, reg);
      break;
    case 2:
      sprintf(dest, "%d",offset.ival);
      break;
    case 3: {
      if (!strcmp("lab", reg))
        strcpy(dest, offset.sval);
      else
        sprintf(dest, "%s(%s)", offset.sval, reg);
      break;
    }
    case 4: {
      if (!strcmp("lab", reg))
        sprintf(dest, "%s", offset.sval);
      else
        sprintf(dest, "%s(%s)", offset.sval, reg);
      break;
    }
    case 5:
      sprintf(dest, "$%d", offset.ival);
      break;
    case 6:
      sprintf(dest, ".L%d", offset.ival);
      break;
    default:
      fprintf(stderr, "x64loc unknown mode %d\n", mode);
      strcpy(dest, "unknown");
      break;
  }

  return dest;
}

X64Instr::X64Instr(const char *op, X64Loc *src, X64Loc *dst) {
  this->op = strdup(op);
  opnd1 = src;
  opnd2 = dst;
}

X64Instr::~X64Instr() {
  free(op);

  if (opnd1)
    delete opnd1;

  if (opnd2)
    delete opnd2;
}

void X64Instr::print(FILE *f) {
  char tmpStr[25];
  if (!strcmp("lab", op)) {
    if (opnd1)
      fprintf(f, "%s:\n", opnd1->str(tmpStr));
  }
  else {
    fprintf(f, "\t%s", op);
    if (opnd1)
      fprintf(f, " %s", opnd1->str(tmpStr));
    if (opnd2)
      fprintf(f, ",%s", opnd2->str(tmpStr));

    fprintf(f, "\n");
  }
}

void X64Instr::print() {
  print(stdout);
}

RegUse::RegUse(const char *reg, int offset) {
  this->reg = reg;
  this->offset=offset;
  loaded=dirty=false;
}

X64Generator::X64Generator(SymTab *strTab) {
  this->strTab = strTab;
}

X64Generator::~X64Generator() {
  X64Instr *instr;
  for (auto it = xcode.begin(); it != xcode.end(); it++) {
    instr = *it;
    delete instr;
  }
  xcode.clear();
}

X64Instr *X64Generator::xgen(const char *opt) {
  return new X64Instr(opt);
}

X64Instr *X64Generator::xgen(const char *op, Address *src, Address *dst) {
  return new X64Instr(op, src ? createX64Loc(src) : nullptr, dst ? createX64Loc(dst) : nullptr);
}

X64Instr *X64Generator::xgen(const char *op, Address *opnd) {
  return new X64Instr(op, opnd ? createX64Loc(opnd) : nullptr);
}

X64Instr *X64Generator::xgen(const char *op, Address *src, const char *dst) {
  return new X64Instr(op, src ? createX64Loc(src) : nullptr, new X64Loc(dst));
}

X64Instr *X64Generator::xgen(const char *op, const char *src, Address *dst) {
  return new X64Instr(op, new X64Loc(src), dst ? createX64Loc(dst) : nullptr);
}

X64Instr *X64Generator::xgen(const char *op, const char *src, const char *dst) {
  return new X64Instr(op, new X64Loc(src), new X64Loc(dst));
}

X64Instr *X64Generator::xgen(const char *op, const char *opnd) {
  return new X64Instr(op, new X64Loc(opnd));
}

X64Loc *X64Generator::createX64Loc(Address *addr) {
  char tmpstr[25];
  if (!strcmp("method", addr->region) || !strcmp("loc", addr->region)) {
    if (addr->offset <= 88) {
      return loadReg(addr);
    } else {
      return new X64Loc("rbp", -addr->offset);
    }
  }
  else if (!strcmp("glob", addr->region)) {
    return new X64Loc("rip", addr->offset);
  }
  else if (!strcmp("const", addr->region)) {
    return new X64Loc("imm", addr->offset);
  }
  else if (!strcmp("lab", addr->region)) {
    return new X64Loc("lab", addr->offset);
  }
  else if (!strcmp("obj", addr->region)) {
    return new X64Loc("r15", addr->offset);
  }
  else if (!strcmp("imm", addr->region)) {
    return new X64Loc("imm", addr->offset);
  }
  else if (!strcmp("strings", addr->region)) {
    sprintf(tmpstr, ".Lstr%u", addr->offset);
    return new X64Loc("%rip", tmpstr);
  }
  else {
    return new X64Loc("lab", addr->region);
  }
}

X64Loc *X64Generator::loadReg(Address *addr) {
  char tmpstr[25];
  int r = addr->offset/8;
  if (!(regs[r]->loaded)) {
    sprintf(tmpstr, "%d(%%rbp)", -addr->offset);
    xcode.push_back(xgen("movq", tmpstr, regs[r]->reg));
    regs[r]->loaded = true;
  }

  return new X64Loc(regs[r+1]->reg);
}

X64Instr *X64Generator::loadReg(RegUse *reg) {
  if (reg->loaded)
    return nullptr;

  reg->loaded = true;

  char tmpstr[25];
  sprintf(tmpstr, "%d(%%rbp)", reg->offset);
  return xgen("movq", tmpstr, reg->reg);
}

X64Instr *X64Generator::saveReg(RegUse *reg) {
  if (!reg->dirty)
    return nullptr;

  reg->dirty = false;

  char tmpstr[25];
  sprintf(tmpstr, "%d(%%rbp)", reg->offset);
  return xgen("movq", reg->reg, tmpstr);
}

void X64Generator::genCode(vector<shared_ptr<Tac>> icode) {
  char tmpstr[50];
  int nregs = sizeof(regs)/sizeof(RegUse*);
  int parmCount = -1;
  shared_ptr<Tac> instr, callinstr;
  for(size_t i=0; i<icode.size(); i++) {
    instr = icode[i];
    if (!strcmp("ADD", instr->op)) {
      xcode.push_back(xgen("movq", instr->op2.get(), "%rax"));
      xcode.push_back(xgen("addq", instr->op3.get(), "%rax"));
      xcode.push_back(xgen("movq", "%rax", instr->op1.get()));
    }
    else if (!strcmp("SUB", instr->op) || !strcmp("NEG", instr->op)) {
      xcode.push_back(xgen("movq", instr->op2.get(), "%rax"));
      xcode.push_back(xgen("negq", "%rax"));
      xcode.push_back(xgen("movq", "%rax", instr->op1.get()));
    }
    else if (!strcmp("ASN", instr->op)) {
      xcode.push_back(xgen("movq", instr->op2.get(), "%rax"));
      xcode.push_back(xgen("movq", "%rax", instr->op1.get()));
    }
    else if (!strcmp("ADDR", instr->op)) {
      xcode.push_back(xgen("leaq", instr->op2.get(), "%rax"));
      xcode.push_back(xgen("%rax", instr->op1.get()));
    }
    else if (!strcmp("LCON", instr->op)) {
      xcode.push_back(xgen("movq", instr->op2.get(), "%rax"));
      xcode.push_back(xgen("movq", "(%rax)", "%rax"));
      xcode.push_back(xgen("movq", "%rax", instr->op1.get()));
    }
    else if (!strcmp("SCON", instr->op)) {
      xcode.push_back(xgen("movq", instr->op2.get(), "%rbx"));
      xcode.push_back(xgen("movq", instr->op1.get(), "%rax"));
      xcode.push_back(xgen("movq", "%rbx", "(%rax)"));
    }
    else if (!strcmp("GOTO", instr->op)) {
      xcode.push_back(xgen("goto", instr->op1.get()));
    }
    else if (!strcmp("BLT", instr->op)) {
      xcode.push_back(xgen("movq", instr->op2.get(), "%rax"));
      xcode.push_back(xgen("cmpq", instr->op3.get(), "%rax"));
      xcode.push_back(xgen("jle", instr->op1.get()));
    }
    else if (!strcmp("PARM", instr->op)) {
      if (parmCount == -1) {
        parmCount = 0;
        for(size_t j = i+1; j<icode.size(); j++) {
          callinstr = icode[j];
          if (!strcmp("CALL", callinstr->op))
            break;
          parmCount++;
        }
      }
      else parmCount--;
      genParm(parmCount, instr->op1.get());
    }
    else if (!strcmp("CALL", instr->op)) {
      xcode.push_back(xgen("call", instr->op1.get()));
      if (instr->op3)
        xcode.push_back(xgen("movq", "%rax", instr->op2.get()));
      
      methodAddrPushed = false;
      parmCount = -1;
    }
    else if (!strcmp("RET", instr->op) || !strcmp("RETURN", instr->op)) {
      if (!instr->op1)
        xcode.push_back(xgen("movq", "$0", "%rax"));
      else
        xcode.push_back(xgen("movq", instr->op1.get(), "%rax"));

      xcode.push_back(xgen("leave"));
      xcode.push_back(xgen("ret", instr->op1 ? instr->op1.get() : nullptr));
    }
    else if (!strcmp("proc", instr->op)) {
      int n = 0;
      if (!instr->op2)
        fprintf(stderr, "instr->op2 is null\n");

      if (!instr->op3.get())
        fprintf(stderr, "instr->op3 is null\n");

      if (instr->op2)
        n += instr->op2->intgr();
      
      if (instr->op3)
        n += instr->op3->intgr();

      n *= 8;
      // int n = (instr->op1->offset + instr->op2->offset) * 8;
      xcode.push_back(xgen(".text"));
      xcode.push_back(xgen(".globl", instr->op1->region));

      sprintf(tmpstr, ".def\t%s;\t.scl\t2;\t.type\t32;\t.endef", instr->op1->region);
      xcode.push_back(xgen(tmpstr));

      sprintf(tmpstr, ".seh_proc\t%s", instr->op1->region);
      xcode.push_back(xgen(tmpstr));
      xcode.push_back(xgen("lab", instr->op1->region));
      // Linux?
      // xcode.push_back(xgen(".type", instr->op1.get(), "@function"));
      xcode.push_back(xgen("pushq", "%rbp"));
      xcode.push_back(xgen(".seh_pushreg\t%rbp"));
      xcode.push_back(xgen("movq", "%rsp", "%rbp"));
      xcode.push_back(xgen(".seh_setframe\t%rbp, 0"));

      sprintf(tmpstr, "$%d", n);
      xcode.push_back(xgen("subq", tmpstr, "%rsp"));

      sprintf(tmpstr, ".seh_stackalloc\t%d", n);
      xcode.push_back(xgen(tmpstr));
      xcode.push_back(xgen(".seh_endprologue"));

      if (!strcmp("main", instr->op1->region))
        xcode.push_back(xgen("call","__main"));

      uint32 j = 0;
      if (instr->op2)
        for ( ; j < instr->op2->offset; j++)
          regs[j]->loaded = regs[j]->dirty = true;

      for( ; j < 11; j++)
        regs[j]->loaded = regs[j]->dirty = false;
    }
    else if (!strcmp("end", instr->op)) {
      if (strcmp("ret", xcode[xcode.size()-1]->op)) {
        xcode.push_back(xgen("leave"));
        xcode.push_back(xgen("ret"));
      }
      xcode.push_back(xgen(".seh_endproc"));
    }
    else if (!strcmp(".code", instr->op) || !strcmp(".global", instr->op) || !strcmp(".string", instr->op)) {
      //
    }
    else if (!strcmp("LAB", instr->op)) {
      for (int i=0; i<nregs; i++) {
        RegUse *reg = regs[i];
        if (reg->dirty)
          saveReg(reg);
      }

      if (strncmp("strings:", instr->op1->str(tmpstr), 8))
        xcode.push_back(xgen("lab", instr->op1.get()));
    }
  }
}

void X64Generator::genParm(int n, Address *addr) {
  char tmpstr[25];
  int nregs = sizeof(regs)/sizeof(RegUse*);
  for (int i=0; i<nregs; i++) {
    saveReg(regs[i]);
  }

  if (n > 6) {
    xcode.push_back(xgen("pushq", addr));
  }
  else {
    switch (n) {
      case 1:
        strcpy(tmpstr, "%rdi");
        break;
      case 2:
        strcpy(tmpstr, "%rsi");
        break;
      case 3:
        strcpy(tmpstr, "%rdx");
        break;
      case 4:
        strcpy(tmpstr, "%rcx");
        break;
      case 5:
        strcpy(tmpstr, "%r8");
        break;
      case 6:
        strcpy(tmpstr, "%r9");
        break;
      default:
        sprintf(tmpstr, "error:%d", n);
        break;
    }
    
    if (addr && !strcmp("strings", addr->region))
      xcode.push_back(xgen("leaq", addr, tmpstr));
    else
      xcode.push_back(xgen("movq", addr, tmpstr));
  }
}

void X64Generator::writeCode(const char *filename, const char *origFilename) {
  FILE *f = fopen(filename, "w");
  if (!f) {
    fprintf(stderr, "cannot open file %s for writing\n", filename);
    exit(1);
  }

  fprintf(f, "\t.file\t\"%s\"\n", origFilename);
  // write out our "runtime system" with every generated code
  fprintf(f, "\t.text\n");
  fprintf(f, "\t.globl\tPrintStream__println\n");
  fprintf(f, "\t.def\tPrintStream__println;\t.scl\t2;\t.type\t32;\t.endef\n");
  fprintf(f, "\t.seh_proc\tPrintStream__println\n");
  fprintf(f, "PrintStream__println:\n");
  fprintf(f, "\tpushq\t%%rbp\n");
  fprintf(f, "\t.seh_pushreg\t%%rbp\n");
  fprintf(f, "\tmovq\t%%rsp, %%rbp\n");
  fprintf(f, "\t.seh_setframe\t%%rbp, 0\n");
  fprintf(f, "\tsubq\t$32, %%rsp\n");
  fprintf(f, "\t.seh_stackalloc\t32\n");
  fprintf(f, "\t.seh_endprologue\n");
  fprintf(f, "\tmovq\t%%rsi, %%rcx\n"); // Windows conventions!
  fprintf(f, "\tcall\tputs\n");
  fprintf(f, "\tnop\n");
  fprintf(f, "\taddq\t$32, %%rsp\n");
  fprintf(f, "\tpopq\t%%rbp\n");
  fprintf(f, "\tret\n");
  fprintf(f, "\t.seh_endproc\n");
  fprintf(f, "\t.text\n");
  fprintf(f, "\t.def\t__main;\t.scl\t2;\t.type\t32;\t.endef\n");
  
  writeStrings(f);
  writeInstrs(f);

  fprintf(f, "\t.ident\t\"j0: (Unicon) 0.1.0\"\n");
  fprintf(f, "\t.def\tputs;\t.scl\t2;\t.type\t32;\t.endef\n");
  fclose(f);
}

void X64Generator::writeStrings(FILE *f) {
  map<string, SymTabEntry*>::iterator it;
  string s;
  int i = 0;
  fprintf(f, "\t.section\t.rdata,\"dr\"\n");
  for (it = strTab->t.begin(); it != strTab->t.end(); it++) {
    s = it->first;
    fprintf(f, ".Lstr%d:\n", i);
    s = s.substr(0, s.length()-1) + "\\0\"";
    fprintf(f, "\t.ascii %s\n", s.c_str());
    i++;
  }
}

void X64Generator::writeInstrs(FILE *f) {
  X64Instr* instr;
  for(vector<X64Instr*>::iterator it = xcode.begin(); it != xcode.end(); it++) {
    instr = *it;
    instr->print(f);
  }
}
