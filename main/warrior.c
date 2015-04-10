#include "../shared/op.h"
#include "../shared/err_helpers.h"
#include "../shared/file_helper.h"
#include "../shared/kv.h"
#include "../shared/read_helpers.h"
#include "warrior.h"

#define PROGRAM_OFFSET PROG_NAME_LENGTH + 1 /* \0 (magic added before) */

kv_t* read_warrior_name_prog(char* path)
{
  char* prog = read_file(path);
  int magic_number = read_int(prog);
  if (magic_number != COREWAR_EXEC_MAGIC) {
    RIP("%s is not a valid coretna champion (invalid magic number %d)\n", path,
        magic_number);
  }
  prog += sizeof(int);

  return make_kv(prog, prog + PROGRAM_OFFSET);
}

list_t* add_warrior(list_t* l_war, char* path)
{
  off_t size = get_file_size(path);
  if (size <= PROGRAM_OFFSET) {
    RIP("%s is not a valid coretna champion (invalid size)\n", path);
  }
  size -= PROGRAM_OFFSET;
  kv_t* name_prog = read_warrior_name_prog(path);
  warrior_t* warrior = make_warrior(name_prog->key, size, name_prog->value);

  if (l_war) {
    append(l_war, warrior);
    return l_war;
  } else { /* first one... welcome to the arena! */
    return make_list_data(warrior);
  }
}

warrior_t* make_warrior(char* name, off_t prog_size, char* prog)
{
  warrior_t* warrior = xcalloc(1, sizeof(warrior_t));
  warrior->name = name;
  warrior->alive = 1;
  warrior->prog_size = prog_size;
  warrior->prog = prog;
  warrior->next_instr = -1; /* will need to fetch */
  /* warrior->regs = xcalloc(REG_NUMBER, REG_SIZE); */
  return warrior;
}
