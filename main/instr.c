#include "stddef.h"
#include "instr.h"
#include "instructions/instr_header.h"
#include "vm_read_helpers.h"

instr_t instructions[] = {
    {0x01, instr_live},
    {0x02, instr_ld},
    {0x03, instr_st},
    {0x04, instr_add},
    {0x05, instr_sub},
    {0x06, instr_and},
    {0x07, instr_or},
    {0x08, instr_xor},
    {0x09, instr_zjmp},
    {0x0a, instr_ldi},
    {0x0b, instr_sti},
    {0x0c, instr_fork},
    {0x0d, instr_lld},
    {0x0e, instr_lldi},
    {0x0f, instr_lfork},
    {0x10, instr_aff},
    {0, NULL},
};

instr_t* find_instr(char c)
{
  for (int i = 0;; i++) {
    if (!instructions[i].op) {
      break;
    }
    if (instructions[i].op == c) {
      return &instructions[i];
    }
  }
  return NULL;
}

char get_arg_type(int arg_pos, char code_byte)
{
  code_byte = code_byte >> (8 - (arg_pos * 2));
  return (code_byte & 0x03);
}

void* warrior_pc_add_idx(int val, vm_t* vm, warrior_t* warrior)
{
  return vm->memory + (warrior->pc + (val % IDX_MOD) % MEM_SIZE);
}

int read_int_at(char arg_type, vm_t* vm, warrior_t* warrior)
{
  int val = vm_read_int(vm, warrior);
  switch (arg_type) {
  case T_DIR:
    return val;

  case T_REG:
    if (val < 1 || val > 16) {
      return 0;
    }
    return warrior->regs[val - 1];

  case T_IND:
    return read_int(warrior_pc_add_idx(val, vm, warrior));

  default:
    return 0;
  }
}

int byte_to_skip(char cur_pos, char code)
{
  int ret = 0;
  int nb_args = get_nb_args(code);

  for (nb_args = nb_args; nb_args > cur_pos; nb_args--) {
    if (get_arg_type(nb_args, code) == T_REG ||
        get_arg_type(nb_args, code) == T_DIR) {
      ret += REG_SIZE;
    } else {
      ret += IND_SIZE;
    }
  }
  return ret;
}

int get_nb_args(char code)
{
  int ret = 0;
  int i;

  for (i = 1; i <= 4; i++) {
    if (get_arg_type(i, code) > 0) {
      ret++;
    }
  }
  return ret;
}

int get_val_for_arg(char arg_pos, vm_t* vm, warrior_t* warrior, char code)
{
  switch (get_arg_type(arg_pos, code)) {
  case T_REG: // 4
    errno = 0;
    int ret = get_reg_stored_val(arg_pos, vm, warrior, code);
    if (errno == EFAULT) {
      return 0;
    } else {
      return ret;
    }
    break;
  case T_DIR: // 4
    return vm_read_int(vm, warrior);
    break;
  case T_IND: // 2
    return vm_read_short(vm, warrior);
    break;
  default:
    return 0;
  }
}

// set errno to 0 before call and check for errno == EFAULT after call
int get_reg_stored_val(char cur_pos, vm_t* vm, warrior_t* warrior, char code)
{
  int reg = vm_read_int(vm, warrior);
  if (reg < 1 || reg > REG_NUMBER) {
    warrior->pc += byte_to_skip(cur_pos, code);
    errno = EFAULT;
    return 0;
  }
  char* mem_addr = (char*)warrior->regs + (reg - 1) * REG_SIZE;
  return read_int(mem_addr);
}
