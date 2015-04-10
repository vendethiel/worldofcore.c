#include "instr_header.h"
#include "string.h"

void instr_fork(vm_t* vm, warrior_t* warrior)
{
  warrior_t* copy = xmalloc(sizeof(*copy));
  memcpy(copy, warrior, sizeof(*warrior));
  append(vm->warriors, make_list_data(copy));

  int where = vm_read_int(vm, warrior);
  warrior->pc += where % IDX_MOD;
}

/* IGNORE IDX_MOD */
void instr_lfork(vm_t* vm, warrior_t* warrior)
{
  warrior_t* copy = xmalloc(sizeof(*copy));
  memcpy(copy, warrior, sizeof(*warrior));
  append(vm->warriors, make_list_data(copy));

  int where = vm_read_int(vm, warrior);
  warrior->pc += where;
}
