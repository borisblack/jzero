#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "j0machine.h"

int main(int argc, char *argv[]) {
  if (argc < 1) {
    printf("usage: j0x file[.j0]\n");
    exit(1);
  }

  size_t len = strlen(argv[1]);
  char *filename = new char[len+4];
  strcpy(filename, argv[1]);
  if (len < 4 || strcmp(filename+len-3, ".j0"))
    strcat(filename, ".j0");

  j0m_Init(filename);
  j0m_Interp();
  j0m_Dispose();

  delete [] filename;
}
