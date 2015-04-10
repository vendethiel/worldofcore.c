#ifndef VM_READ_HELPERS_
#define VM_READ_HELPERS_

#include "vm.h"
#include "warrior.h"

char vm_read_char(vm_t* vm, warrior_t* warrior);
short vm_read_short(vm_t* vm, warrior_t* warrior);
int vm_read_int(vm_t* vm, warrior_t* warrior);
long vm_read_long(vm_t* vm, warrior_t* warrior);

#endif
