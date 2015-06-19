#ifndef INSTR_H_
#define INSTR_H_

#include <errno.h>
#include "warrior.h"
#include "vm.h"

typedef struct {
  char op;
  void (*fn)(vm_t* vm, warrior_t* warrior);
} instr_t;

extern instr_t instructions[];
instr_t* find_instr(char);
char get_arg_type(int, char);

void* warrior_pc_add_idx(int, vm_t*, warrior_t*);
int read_int_at(char, vm_t*, warrior_t*);

int byte_to_skip(char, char);
int get_nb_args(char);
int get_val_for_arg(char, vm_t*, warrior_t*, char);
int get_reg_stored_val(char, vm_t*, warrior_t*, char);

/* instructions */
void instr_live(vm_t* vm, warrior_t* warrior);
void instr_ld(vm_t* vm, warrior_t* warrior);
void instr_st(vm_t* vm, warrior_t* warrior);
void instr_add(vm_t* vm, warrior_t* warrior);
void instr_sub(vm_t* vm, warrior_t* warrior);
void instr_and(vm_t* vm, warrior_t* warrior);
void instr_or(vm_t* vm, warrior_t* warrior);
void instr_xor(vm_t* vm, warrior_t* warrior);
void instr_zjmp(vm_t* vm, warrior_t* warrior);
void instr_ldi(vm_t* vm, warrior_t* warrior);
void instr_sti(vm_t* vm, warrior_t* warrior);
void instr_fork(vm_t* vm, warrior_t* warrior);
void instr_lld(vm_t* vm, warrior_t* warrior);
void instr_lldi(vm_t* vm, warrior_t* warrior);
void instr_lfork(vm_t* vm, warrior_t* warrior);
void instr_aff(vm_t* vm, warrior_t* warrior);

#endif

/*
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
*/
