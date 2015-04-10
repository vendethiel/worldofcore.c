#include "../shared/err_helpers.h"
#include "../shared/op.h"
#include "warrior.h"
#include "vm.h"
#include "vm_helpers.h"
#include "life_helpers.h"
#include "instr.h"

void fetch_op(vm_t* vm, warrior_t* warrior)
{
  op_t* op = find_op(vm->memory[warrior->pc]);
  if (op) {
    warrior->next_instr = warrior->pc;
    warrior->waiting = op->nbr_cycles;
  } else {
		warrior->pc++; /* skip that senseless op */
	}
  warrior->pc %= MEM_SIZE; /* so circular... */
}

void play(vm_t* vm, warrior_t* warrior)
{
  if (warrior->next_instr != -1) {
    instr_t* instr = find_instr(vm->memory[warrior->next_instr]);
    warrior->pc++; /* increment anyhow, so that we don't get stuck on that one expr */
    if (instr) {
			warrior->next_instr = -1; /* to allow for overriding */
      instr->fn(vm, warrior);
    }
  }
  warrior->pc %= MEM_SIZE; /* so circular... */
  if (warrior->next_instr == -1) {
    fetch_op(vm, warrior);
  }
}

void run_warriors(vm_t* vm)
{
  list_t* list_warrior = vm->warriors;

  for (; list_warrior; list_warrior = list_warrior->next) {
    warrior_t* warrior = (warrior_t*)list_warrior->data;
    if (warrior_dead(vm, warrior)) {
      continue;
    }

    if (warrior->waiting) {
      warrior->waiting--;
    } else {
      play(vm, warrior);
    }
  }
}

void run(vm_t* vm)
{
  if (game_ended(vm)) {
    return; /* wrong arguments... */
  }

  for (;;) {
    run_warriors(vm);
    life_cycle(vm);
    if (game_ended(vm)) {
      return;
    }
  }
}
