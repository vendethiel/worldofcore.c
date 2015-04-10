#include "../shared/op.h"
#include "../shared/read_helpers.h"
#include "vm_read_helpers.h"
#include "vm.h"
#include "warrior.h"

#define DEFINE_VM_READER(T)                                                    \
  T vm_read_##T(vm_t* vm, warrior_t* warrior)                                  \
  {                                                                            \
    T ret = read_##T(vm->memory + warrior->pc);                                \
    warrior->pc += sizeof(T);                                                  \
    warrior->pc %= MEM_SIZE;                                                   \
    return ret;                                                                \
  }

DEFINE_VM_READER(char)
DEFINE_VM_READER(short)
DEFINE_VM_READER(int)
DEFINE_VM_READER(long)

#undef DEFINE_VM_READER
