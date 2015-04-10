#include <math.h>
#include <string.h>
#include "../shared/err_helpers.h"
#include "../shared/op.h"
#include "../shared/list.h"
#include "warrior.h"
#include "vm.h"

void vm_set_warrior_ids(vm_t* vm)
{
  int id = 0;
  list_t* list_warrior = vm->warriors;

  for (; list_warrior; list_warrior = list_warrior->next) {
    warrior_t* warrior = (warrior_t*)list_warrior->data;
    warrior->id = id++;
    memcpy(warrior->regs, &id, REG_SIZE);
  }
}

void vm_set_memory_parts(vm_t* vm)
{
  int available_size = ceil(MEM_SIZE / vm->num_warriors);

  /* first off, check if we have overweight warriors */
  list_t* list_warrior = vm->warriors;
  for (; list_warrior; list_warrior = list_warrior->next) {
    warrior_t* warrior = (warrior_t*)list_warrior->data;

    if (warrior->prog_size > available_size) {
      RIP("Warrior #%d is too big (%ld > %d)", warrior->id, warrior->prog_size,
          available_size);
    }

    warrior->pc = warrior->id * available_size;
    memcpy(vm->memory + warrior->pc, warrior->prog, warrior->prog_size);
    /* TODO check if the nulbyte is there! */
  }
}

vm_t* make_vm(list_t* list_warrior)
{
  vm_t* vm = xcalloc(1, sizeof(vm_t*));
  vm->warriors = list_warrior;
  vm->num_warriors = length(list_warrior);
  vm->memory = xcalloc(1, MEM_SIZE + 10 /* security padding */);

  vm_set_warrior_ids(vm);
  vm_set_memory_parts(vm);

  return vm;
}
