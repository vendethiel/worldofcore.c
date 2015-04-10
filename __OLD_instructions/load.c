#include <string.h>
#include "instr_header.h"

void instr_ld(vm_t* vm, warrior_t* warrior)
{
  char code = vm_read_char(vm, warrior);
  char* mem_addr;
  if (get_arg_type(1, code) == T_DIR) {
    int offset = vm_read_int(vm, warrior);
    mem_addr = vm->memory + (warrior->pc + (offset % IDX_MOD) % MEM_SIZE);
  } else {
    int reg = vm_read_int(vm, warrior);
    if (reg < 1 || reg > REG_NUMBER) {
      warrior->pc += sizeof(int);
      return; /* we don't have that reg. */
    }

    mem_addr = (char*)warrior->regs + (reg - 1) * REG_SIZE;
  }

  int reg = vm_read_int(vm, warrior);
  if (reg < 1 || reg > REG_NUMBER) {
    return; /* we don't have that reg. */
  }
  /* we have a char*, we need to read an int: go read_int */
  warrior->regs[reg - 1] = read_int(mem_addr);
}

void instr_ldi(vm_t* vm, warrior_t* warrior)
{
  char code = vm_read_char(vm, warrior);

  int value = read_int_at(get_arg_type(1, code), vm, warrior);
  if (get_arg_type(2, code) == T_IND) {
    return; /* Invalid value, read_int_at is forbidden to read that */
  }
  value += read_int_at(get_arg_type(2, code), vm, warrior);
  warrior->regs[0] = value;
}

/* IGNORE IDX_MOD */
void instr_lld(vm_t* vm, warrior_t* warrior)
{
  char code = vm_read_char(vm, warrior);
  char* mem_addr;
  if (code & T_DIR) {
    int offset = vm_read_int(vm, warrior);
    mem_addr = vm->memory + (warrior->pc + offset % MEM_SIZE);
  } else {
    int reg = vm_read_int(vm, warrior);
    if (reg < 1 || reg > REG_NUMBER) {
      warrior->pc += sizeof(int);
      return; /* we don't have that reg. */
    }

    mem_addr = (char*)warrior->regs + (reg - 1) * REG_SIZE;
  }

  int reg = vm_read_int(vm, warrior);
  if (reg < 1 || reg > REG_NUMBER) {
    warrior->pc += sizeof(int);
    return; /* we don't have that reg. */
  }
  /* we have a char*, we need to read an int: go read_int */
  warrior->regs[reg - 1] = read_int(mem_addr);
}

/* IGNORE IDX_MOD */
void instr_lldi(vm_t* vm, warrior_t* warrior)
{
  rip("tbd lldi");
}
