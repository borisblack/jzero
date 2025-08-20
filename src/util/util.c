#ifndef YY_NO_UNISTD_H
#include <unistd.h>
#endif

#include <stdlib.h>
#include <string.h>
#include "util.h"

#define HIGHBIT 0x80
#define LOWBITS 0x7F

/* Reads buffer data. */
u_char *fread_buf(FILE *file, size_t size) {
  u_char *buf = (u_char*)calloc(size, sizeof(u_char));
  if (!buf)
    return NULL;

  fread(buf, 1, size, file);
  return buf;
}

/* Reads buffer data. */
u_char *fread_buf_at(FILE *file, size_t size, size_t offset) {
  u_char *buf = (u_char*)calloc(size, sizeof(u_char));
  if (!buf)
    return NULL;

  fseek(file, offset, SEEK_SET);
  fread(buf, 1, size, file);
  return buf;
}

/* Reads byte. */
u_char fread_byte(FILE *file) {
  u_char byte;
    fread(&byte, 1, 1, file);
    return byte;
}

/* Reads byte. */
u_char read_byte(u_char *buf) {
  if (buf == NULL)
    return 0;

  return *buf;
}

/* Reads byte at the given offset. */
u_char fread_byte_at(FILE *file, size_t offset) {
  u_char byte;

  fseek(file, offset, SEEK_SET);
  fread(&byte, 1, 1, file);
  return byte;
}

/* Reads byte at the given offset. */
u_char read_byte_at(u_char *buf, size_t offset) {
  if (buf == NULL)
    return 0;

  return buf[offset];
}

/* Reads integer. TODO: Consider a sign. */
long fread_int(FILE *file, u_int count) {
  if (count == 0)
    return 0;

  u_char *buffer = malloc(count); // buffer for intermediate data
  fread(&buffer, 1, count, file);
  unsigned int res = buffer[count-1]; // last byte
  for (int i = count-2; i >= 0; --i) {
    res |= (buffer[i] << 8);
  }
  free(buffer);
  
  return res;
}

/* Reads integer. TODO: Consider a sign. */
long read_int(u_char *buf, uint32 count) {
  if (buf == NULL || count <= 0)
    return 0;

  u_int res = buf[count - 1]; // last byte
  for (u_char *pBuf = buf+count-2; pBuf >= buf; --pBuf) {
    res |= (*pBuf << 8);
  }
  
  return res;
}

/* Reads integer at the given offset. TODO: Consider a sign. */
long fread_int_at(FILE *file, u_int count, size_t offset) {
  if (count == 0)
    return 0;

  fseek(file, offset, SEEK_SET);
  
  return fread_int(file, count);
}

/* Reads integer at the given offset. TODO: Consider a sign. */
long read_int_at(u_char *buf, u_int count, size_t offset) {
  if (buf == NULL || count <= 0)
    return 0;
  
  return read_int(buf + offset, count);
}

/* Reads variable-length integer. */
size_t fread_varint(FILE *file, u_int *size) {
  size_t num = 0;
  u_char bytes_read = 0;
  while (bytes_read < 9) {
    u_char byte = fread_byte(file);
    bytes_read++;
    if (bytes_read < 9) {
      num = ((byte & LOWBITS) | (num << 7));
    } else {
      num = (byte | (num << 8));
    }

    if (!(byte & HIGHBIT)) {
      break;
    }
  }
  *size = bytes_read;

  return num;
}

/* Reads variable-length integer. */
size_t read_varint(u_char *buf, uint *size) {
  if (buf == NULL)
    return 0;

  u_char *pBuf = buf;
  size_t num = 0;
  u_char bytes_read = 0;
  while (bytes_read < 9) {
    u_char byte = *pBuf++;
    bytes_read++;
    if (bytes_read < 9) {
      num = ((byte & LOWBITS) | (num << 7));
    } else {
      num = (byte | (num << 8));
    }

    if (!(byte & HIGHBIT)) {
      break;
    }
  }
  *size = bytes_read;

  return num;
}

/* Reads variable-length integer at the given offset. */
size_t fread_varint_at(FILE *file, size_t offset, u_int *size) {
  fseek(file, offset, SEEK_SET);

  return fread_varint(file, size);
}

/* Reads variable-length integer at the given offset. */
size_t read_varint_at(u_char *buf, size_t offset, u_int *size) {
  return read_varint(buf + offset, size);
}

/* Prints PID and waits key. */
void print_pid() {
  if(isatty(0) && isatty(2)) {
    char zLine[100];
    fprintf(stderr, "Current PID is %d. Press ENTER to continue...", getpid());
    if (fgets(zLine, sizeof(zLine), stdin) != 0 && strcmp(zLine, "stop") == 0
    ) {
      exit(1);
    }
  }
}

/* Replaces all occurences of one substring to another. */
char *str_replace(char *src, char *from, char *to) {
  const size_t srcLen = strlen(src);
  const size_t fromLen = strlen(from);
  const size_t toLen = strlen(to);

  // Check if src string is less than search substring
  if (srcLen < fromLen)
    return strdup(src);

  // Count matches
  char *pMachStart = src;
  int nMatches = 0;
  while ( (pMachStart = strstr(pMachStart, from)) ) {
    pMachStart += fromLen;
    nMatches++;
  }

  // Check if no matches
  if (nMatches == 0)
    return strdup(src);

  // Replace each match
  const int targetLen = srcLen - fromLen * nMatches + toLen * nMatches;
  char *target = malloc(targetLen + 1);
  char *pMatchPrefix = src;
  char *pTarget = target;
  pMachStart = src;
  while ( (pMachStart = strstr(pMachStart, from)) ) {
    pMachStart += fromLen;
    const int prefixLen = pMachStart - pMatchPrefix - fromLen;
    strncpy(pTarget, pMatchPrefix, prefixLen);
    pTarget += prefixLen;
    strncpy(pTarget, to, toLen);
    pTarget += toLen;
    pMatchPrefix = pMachStart;
  }

  // Copy tail substring
  strcpy(pTarget, pMatchPrefix);
  target[targetLen] = '\0';
  
  return target;
}
