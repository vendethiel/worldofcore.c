#ifndef ERR_HELPERS_H
#define ERR_HELPERS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define RIP(...)                                                               \
  ({                                                                           \
    printf(__VA_ARGS__);                                                       \
    exit(1);                                                                   \
  })

void rip(const char* str);
void* xmalloc(size_t size);
void* xcalloc(size_t count, size_t size);

#endif
