#include "instr_header.h"

void instr_add(vm_t* vm, warrior_t* warrior)
{
  char code = vm_read_char(vm, warrior);
  int reg1 = vm_read_int(vm, warrior);
  if (reg1 < 1 || reg1 > REG_NUMBER) {
    warrior->pc += 2 * sizeof(int);
    return; /* we don't have that reg. */
  }
  int reg2 = vm_read_int(vm, warrior);
  if (reg2 < 1 || reg2 > REG_NUMBER) {
    warrior->pc += sizeof(int);
    return; /* we don't have that reg. */
  }
  int store = vm_read_int(vm, warrior);
  if (store < 1 || store > REG_NUMBER) {
    return; /* we don't have that reg. */
  }

  int param_add_1 = warrior->regs[reg1 - 1];
  int param_add_2 = warrior->regs[reg2 - 1];
  warrior->regs[store - 1] = param_add_1 + param_add_2;
}

void instr_sub(vm_t* vm, warrior_t* warrior)
{
  char code = vm_read_char(vm, warrior);
  int reg1 = vm_read_int(vm, warrior);
  if (reg1 < 1 || reg1 > REG_NUMBER) {
    warrior->pc += 2 * sizeof(int);
    return; /* we don't have that reg. */
  }
  int reg2 = vm_read_int(vm, warrior);
  if (reg2 < 1 || reg2 > REG_NUMBER) {
    warrior->pc += sizeof(int);
    return; /* we don't have that reg. */
  }
  int store = vm_read_int(vm, warrior);
  if (store < 1 || store > REG_NUMBER) {
    return; /* we don't have that reg. */
  }

  int param_add_1 = warrior->regs[reg1 - 1];
  int param_add_2 = warrior->regs[reg2 - 1];
  warrior->regs[store - 1] = param_add_1 - param_add_2;
}
