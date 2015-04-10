#include "../shared/err_helpers.h"
#include "vm_helpers.h"
#include "warrior.h"
#include "vm.h"

int warrior_dead(vm_t* vm, warrior_t* warrior)
{
  return !warrior->alive;
}

warrior_t* first_alive(vm_t* vm)
{
  list_t* list_warrior = vm->warriors;

  for (; list_warrior; list_warrior = list_warrior->next) {
    warrior_t* warrior = (warrior_t*)list_warrior->data;

    if (!warrior_dead(vm, warrior)) {
      return warrior;
    }
  }

  RIP("Unable to find anyone alive!");
}

int count_alive(vm_t* vm)
{
  int alive = 0;
  list_t* list_warrior = vm->warriors;

  while (list_warrior) {
    warrior_t* warrior = (warrior_t*)list_warrior->data;
    if (!warrior_dead(vm, warrior)) {
      alive++;
    }

    list_warrior = list_warrior->next;
  }

  return alive;
}

int game_ended(vm_t* vm)
{
  int alive = count_alive(vm);

  if (alive < 2) {
    if (alive == 0) {
      printf("Everyone's dead, no one left!");
    } else {
      printf("%s wins!", first_alive(vm)->name);
    }

    return 1;
  } else {
    return 0;
  }
}

void life_cycle(vm_t* vm)
{
  vm->cycle++;
  if (vm->cycle >= max_cycles(vm)) {
    vm->cycle = 0;
    vm->delta++;

    list_t* list_warrior = vm->warriors;
    for (; list_warrior; list_warrior = list_warrior->next) {
      warrior_t* warrior = (warrior_t*)list_warrior->data;

      if (!warrior->called_live) {
        warrior->alive = 0;
      }
      warrior->called_live = 0;
    }
  }
}
