#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <sys/types.h>
#include "../shared/list.h"
#include "../shared/op.h"

typedef struct {
  int id;
  char* name;

  long prog_size;
  char* prog;

  int next_instr;
  int pc;               /* that's really just a pointer */
  unsigned int waiting; /* number of times before executing PC */

  short alive;
  short called_live;

  short carry;
  int regs[REG_NUMBER];
} warrior_t;

warrior_t* make_warrior(char*, off_t, char*);
list_t* add_warrior(list_t* l_war, char* path);

#endif
