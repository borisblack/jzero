#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include "c.h"

/* Reads buffer data. */
u_char *fread_buf(FILE *file, size_t size);

/* Reads buffer data. */
u_char *fread_buf_at(FILE *file, size_t size, size_t offset);

/* Reads byte. */
u_char fread_byte(FILE *file);

/* Reads byte. */
u_char read_byte(u_char *buf);

/* Reads byte at the given offset. */
u_char fread_byte_at(FILE *file, size_t offset);

/* Reads byte at the given offset. */
u_char read_byte_at(u_char *buf, size_t offset);

/* Reads integer. TODO: Consider a sign. */
long fread_int(FILE *file, u_int count);

/* Reads integer. TODO: Consider a sign. */
long read_int(u_char *buf, u_int count);

/* Reads integer at the given offset. */
long fread_int_at(FILE *file, u_int count, size_t offset);

/* Reads integer at the given offset. */
long read_int_at(u_char *buf, u_int count, size_t offset);

/* Reads variable-length integer. */
size_t fread_varint(FILE *file, u_int *size);

/* Reads variable-length integer. */
size_t read_varint(u_char *buf, u_int *size);

/* Reads variable-length integer at the given offset. */
size_t fread_varint_at(FILE *file, size_t offset, u_int *size);

/* Reads variable-length integer at the given offset. */
size_t read_varint_at(u_char *buf, size_t offset, u_int *size);

/* Prints PID and waits key. */
void print_pid();

/* Replaces all occurences of one substring to another. */
char *str_replace(char *src, char *from, char *to);

#endif /* UTIL_H */