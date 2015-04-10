#include <stddef.h>

#define DEFINE_READER(T)                                                       \
  T read_##T(const char* bytes)                                                \
  {                                                                            \
    char tmp[sizeof(T)];                                                       \
                                                                               \
    for (size_t i = sizeof(tmp); i--; ++bytes)                                 \
      tmp[i] = *bytes;                                                         \
                                                                               \
    return *(T*)(void*)tmp;                                                    \
  }

DEFINE_READER(char)
DEFINE_READER(short)
DEFINE_READER(int)
DEFINE_READER(long)

#undef DEFINE_READER
