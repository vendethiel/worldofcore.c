#include "instr_header.h"

void instr_live(vm_t* vm, warrior_t* warrior)
{
  int warrior_id = vm_read_int(vm, warrior);
  warrior_t* warrior_by_id = find_warrior_by_id(vm, warrior_id);
  if (warrior_by_id) { /* existing ID */
    printf("%s will live!\n", warrior_by_id->name);
    warrior_by_id->called_live = 1;
  }
}

void instr_zjmp(vm_t* vm, warrior_t* warrior)
{
  /* NO CODE OCTET */
  int index = vm_read_int(vm, warrior);
  if (!warrior->carry) {
    return; /* zjmp is conditional */
  }
  warrior->pc += index * IDX_MOD;
}

void instr_aff(vm_t* vm, warrior_t* warrior)
{
  char code = vm_read_char(vm, warrior);
  int val = get_val_for_arg(1, vm, warrior, code);
  if (!val && errno == EFAULT) {
    return;
  }
  char out = val % 256;
  printf("%c\n", out);
}
