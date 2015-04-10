#include <stddef.h>
#include <stdio.h>
#include "../shared/err_helpers.h"
#include "../shared/op.h"
#include "../shared/list.h"
#include "warrior.h"
#include "vm.h"

int max_cycles(vm_t* vm)
{
  return CYCLE_TO_DIE + (CYCLE_DELTA * vm->delta);
}

warrior_t* find_warrior_by_id(vm_t* vm, int id)
{
  list_t* list_warrior = vm->warriors;

  for (; list_warrior; list_warrior = list_warrior->next) {
    warrior_t* warrior = (warrior_t*)list_warrior->data;
    if (warrior->id == id) {
      return warrior;
    }
  }
  return NULL;
}
