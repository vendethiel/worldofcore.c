#include <stdio.h>
#include "../shared/list.h"
#include "../shared/kv.h"
#include "../shared/err_helpers.h"
#include "warrior.h"
#include "vm.h"
#include "vm_create_helpers.h"

int main(int argc, char** argv)
{
  list_t* list_warrior = NULL;

  /* TODO option for --dump_cycle */
  for (int i = 1; i < argc; ++i) {
    list_warrior = add_warrior(list_warrior, argv[i]);
  }
  run(make_vm(list_warrior));
  return 0;
}
