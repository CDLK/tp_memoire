#include "memory_operations.h"
#include <stdlib.h>
#include <stdio.h>

void *my_memcpy(void *dst, const void *src, size_t len) {
  for (int i = 0; i < len; i++) {
    *(((char*)dst)+i) = *(((char*)src)+i);
  }
  return dst;
}

void *my_memmove(void *dst, const void *src, size_t len) {
  void *buffer = malloc(len);
  for (int i = 0; i < len; i++) {
    *(((char*)buffer)+i) = *(((char*)src)+i);
  }
  for (int i = 0; i < len; i++) {
    *(((char*)dst)+i) = *(((char*)buffer)+i);
  }
  free(buffer);
  return dst;
}

int is_little_endian() {
  unsigned int x = 0x76543210;
  char* c = (char*) &x;
  return c[0] < c[1];
}

int reverse_endianess(int value) {
  unsigned int n = value;
  unsigned char octets[4];
  for (int i = 0; i < 4; i++) {
    octets[3-i] = n >> i*8;
  }
  return *((int*)&octets);
}
