#include <string.h>

#define DEFINE_READER(T)                                                       \
  T read_##T(const char* bytes)                                                \
  {                                                                            \
    T value;                                                                   \
    memcpy(&value, bytes, sizeof(T));                                          \
    return value;                                                              \
  }

DEFINE_READER(char)
DEFINE_READER(short)
DEFINE_READER(int)
DEFINE_READER(long)

#undef DEFINE_READER
