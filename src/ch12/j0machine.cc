#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "c.h"
#include "byc.h"

static long ncode = 0;
static char *code = NULL, *stack = NULL;
static int ip, sp, bp, op, opr, finstr;
static long opnd;

static bool loadByteCode(char *filename);
static int find(const char *needle, char *haystack);
static long getOpnd();
static void fetch();
static void doPrintln();
static long deref(int reg, long od);
static void assign(long ad, long val);
static void push(long val);
static long pop();
static long getLong(char *buf, int idx);
static void putLong(char *buf, int idx, long value);

void j0m_Init(char *filename) {
  ip = sp = 0;
  if (!loadByteCode(filename)) {
    printf("cannot open %s\n", filename);
    exit(1);
  }

  ip = 16;
  ip = finstr = (int)(8*getOpnd());
  stack = (char*)malloc(800000);
}

void j0m_Interp() {
  while (true) {
    fetch();
    switch (op) {
      case HALT: {
        printf("Execution complete.\n");
        exit(1);
        break;
      }
      case NOOP: {
        break;
      }
      case ADD: {
        long val1 = getLong(stack, sp--);
        long val2 = getLong(stack, sp--);
        putLong(stack, sp++, val1 + val2);
        break;
      }
      case PUSH: {
        long val = deref(opr, opnd);
        push(val);
        break;
      }
      case POP: {
        long val = pop();
        assign(opnd, val);
        break;
      }
      case GOTO: {
        ip = (int)opnd;
        break;
      }
      case BIF: {
        if (pop())
          ip = (int)opnd;
        break;
      }
      case CALL: {
        long f;
        f = getLong(stack, sp-16-(int)(8*opnd));
        if (f >= 0) {
          push(ip);
          push(bp);
          bp = sp;
          ip = (int)f;
        } else if (f == -1) {
          doPrintln();
        } else {
          printf("no CALL defined for %ld\n", f);
          exit(1);
        }
        break;
      }
      case RET: {
        sp = bp;
        bp = (int)pop();
        ip = (int)pop();
        break;
      }
      case LT: {
        printf("LT not implemented yet.\n");
        exit(1);
      }
      case LE: {
        printf("LE not implemented yet.\n");
        exit(1);
      }
      default: {
        printf("Illegal opcode %d\n", op);
        exit(1);
      }
    }
  }
}

void j0m_Dispose() {
  if (code)
    free(code);

  if (stack)
    free(stack);
}

static bool loadByteCode(char *filename) {
  FILE *f = fopen(filename, "r");
  if (!f) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(1);
  }
  fseek(f, 0, SEEK_END);
  ncode = ftell(f);
  fseek(f, 0, SEEK_SET);
  code = (char*)malloc(ncode + 1);
  fread(code, ncode, 1, f);
  fclose(f);
  code[ncode] = 0;
  const char *magstr = "Jzero!!";
  int i = find(magstr, code);
  
  return i >= 0;
}

static int find(const char *needle, char *haystack) {
  char *pNeedle = strstr(haystack, needle);
  if (!pNeedle)
    return -1;
  
  return haystack - pNeedle;
}

static long getOpnd() {
  long i=0;
  if (code[ip+7] < 0)
    i = -1;

  for(int j=7; j>1; j--)
    i = (i<<8) | code[ip+j];

  return i;
}

static void fetch() {
  op = code[ip];
  opr = code[ip+1];
  if (opr != 0) {
    opnd = getOpnd();
  }
  ip += 8;
}

static void doPrintln() {
  // Execute a System.out.println on an argument on the stack
  long addr = getLong(stack, sp-16);
  char b = code[(int)addr++];
  while (b) {
    printf("%c", b);
    b = code[(int)addr++];
  }
  printf("\n");
}

static long deref(int reg, long od) {
  switch(reg) {
    case R_ABS: {
      return getLong(code, (int)od);
    }
    case R_IMM: {
      return od;
    }
    case R_STACK: {
      return getLong(stack, bp+(int)od);
    }
    default: {
      printf("deref region %d\n", reg);
      exit(1);
    }
  }
  return 0;
}

static void assign(long ad, long val) {
  switch(opr) {
    case R_ABS: {}
    case R_IMM: {}
    case R_STACK: {}
    default: {
      // printf("assign region %d\n", opr);
      // exit(1);
    }
  }
}

static void push(long val) {
  putLong(stack, sp, val);
  sp += 8;
}

static long pop() {
  sp -= 8;
  long rv = getLong(stack, sp);
  return rv;
}

static long getLong(char *buf, int idx) {
  if (buf == NULL || idx < 0)
    return 0;

  long l;
  memcpy(&l, buf + idx, sizeof(long));
  
  return l;
}

static void putLong(char *buf, int idx, long value) {
  if (buf == NULL || idx < 0)
    return;

  memcpy(buf+idx, &value, sizeof(long));
}
