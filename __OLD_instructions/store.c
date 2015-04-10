#include "instr_header.h"

void instr_st(vm_t* vm, warrior_t* warrior)
{
  char code = vm_read_char(vm, warrior);
  int reg = vm_read_int(vm, warrior);
  if (reg < 1 || reg > REG_NUMBER) {
    warrior->pc += sizeof(int);
    return; /* we don't have that reg. */
  }

  if (get_arg_type(2, code) == T_REG) {
    int reg_read = vm_read_int(vm, warrior);
    if (reg_read < 1 || reg_read > REG_NUMBER) {
      return; /* we don't have that reg. */
    }
    warrior->regs[reg - 1] = warrior->regs[reg_read - 1];
  } else {
    int offset = vm_read_int(vm, warrior);
    warrior->regs[reg - 1] =
        read_int(vm->memory + (warrior->pc + (offset % IDX_MOD)) % MEM_SIZE);
  }
}

void instr_sti(vm_t* vm, warrior_t* warrior)
{
  rip("tbd sti");
}
