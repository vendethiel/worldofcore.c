#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "err_helpers.h"

off_t get_file_size(char* path)
{
  int file;
  struct stat file_stat;

  file = open(path, O_RDWR);
  if (file == -1) {
    printf("%s: unable to open file", path);
    exit(1);
  }
  if (stat(path, &file_stat) == -1) {
    printf("%s: unable to stat()", path);
    exit(1);
  }
  return file_stat.st_size;
}

char* read_file(char* path)
{
  int file;
  int return_read;
  char* contents;
  struct stat file_stat;

  file = open(path, O_RDWR);
  if (file == -1) {
    printf("%s: unable to open file", path);
    exit(1);
  }
  if (stat(path, &file_stat) == -1) {
    printf("%s: unable to stat()", path);
    exit(1);
  }
  contents = xmalloc(sizeof(char) * file_stat.st_size + 1);
  return_read = read(file, contents, file_stat.st_size);
  if (return_read != -1) {
    return contents;
  } else {
    printf("%s: unable to read", path);
    exit(1);
  }
}
