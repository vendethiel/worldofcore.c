#ifndef VM_H_
#define VM_H_

#include "../shared/list.h"

typedef struct {
  list_t* warriors;
  unsigned int num_warriors;

  char* memory;

  unsigned int cycle;
  unsigned int delta;
} vm_t;

void run(vm_t* vm);

#endif
