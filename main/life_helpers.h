#ifndef LIFE_HELPERS_
#define LIFE_HELPERS_

warrior_t* first_alive(vm_t*);
int warrior_dead(vm_t*, warrior_t*);
int count_alive(vm_t*);
int game_ended(vm_t*);
void life_cycle(vm_t*);

#endif
