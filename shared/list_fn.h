#ifndef LIST_FN_H_
#define LIST_FN_H_

#include "list.h"

char* find_value_by_key(list_t*, char*);
list_t* find(list_t* list, int (*pred)(void*));
void append_ptr(list_t** list, void* data);

#endif
