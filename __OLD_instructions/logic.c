#include "instr_header.h"

void instr_and(vm_t* vm, warrior_t* warrior)
{
  int val[2];
  int i;
  char code = vm_read_char(vm, warrior);

  for (i = 0; i < 2; i++) {
    val[i] = get_val_for_arg(i + 1, vm, warrior, code);
    if (!val[i] && errno == EFAULT) {
      return;
    }
  }
  int reg = vm_read_int(vm, warrior);
  if (reg < 1 || reg > REG_NUMBER) {
    return; /* we don't have that reg. */
  }
  warrior->regs[reg - 1] = val[0] & val[1];
}

void instr_or(vm_t* vm, warrior_t* warrior)
{
  int val[2];
  int i;
  char code = vm_read_char(vm, warrior);

  for (i = 0; i < 2; i++) {
    val[i] = get_val_for_arg(i + 1, vm, warrior, code);
    if (!val[i] && errno == EFAULT) {
      return;
    }
  }
  int reg = vm_read_int(vm, warrior);
  if (reg < 1 || reg > REG_NUMBER) {
    return; /* we don't have that reg. */
  }
  warrior->regs[reg - 1] = val[0] | val[1];
}

void instr_xor(vm_t* vm, warrior_t* warrior)
{
  int val[2];
  int i;
  char code = vm_read_char(vm, warrior);

  for (i = 0; i < 2; i++) {
    val[i] = get_val_for_arg(i + 1, vm, warrior, code);
    if (!val[i] && errno == EFAULT) {
      return;
    }
  }
  int reg = vm_read_int(vm, warrior);
  if (reg < 1 || reg > REG_NUMBER) {
    return; /* we don't have that reg. */
  }
  warrior->regs[reg - 1] = val[0] ^ val[1];
}
