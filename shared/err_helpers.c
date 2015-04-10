#include <stdio.h>
#include <stdlib.h>

void rip(const char* str)
{
  printf("[err] %s\n", str);
  exit(1);
}

void* xmalloc(size_t size)
{
  void* data = malloc(size);
  if (!data) {
    rip("malloc failed");
  }
  return data;
}

void* xcalloc(size_t count, size_t size)
{
  void* data = calloc(count, size);
  if (!data) {
    rip("malloc failed");
  }
  return data;
}
