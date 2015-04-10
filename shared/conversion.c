
#include "conversion.h"

int str_to_int(char* str)
{
  long nb;
  char* endptr;
  errno = 0;

  nb = strtol(str, &endptr, 10);
  if ((errno == ERANGE && (nb == LONG_MAX || nb == LONG_MIN)) ||
      (errno != 0 && nb == 0) || endptr == str) {
    printf("Failed convert to int : nb = %i str = %s \n", (int)nb, str);
    return 0;
  }
  nb = fix_endian(nb);
  return (int)nb;
}

// char* int_to_hex(int nb) {
// 	char buff[256];

// 	if (sprintf(buff, "%#x", nb) < 0) {
// 		printf("%s\n", "Failed convert to Hex");
// 		return NULL;
// 	}
// 	return buff;
// }