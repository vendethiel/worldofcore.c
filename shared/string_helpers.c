#include <string.h>
#include "string_helpers.h"

char* remove_first_char(char* str)
{
  return memmove(str, str + 1, strlen(str));
}

int is_last_char(char* str, char find)
{
  if (str[strlen(str) - 1] == find) {
    return 1;
  } else {
    return 0;
  }
}

int count_carac(char* str, char charac)
{
  int count;
  int i = 0;
  count = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (charac == str[i]) {
      count++;
    }
  }
  return count;
}
