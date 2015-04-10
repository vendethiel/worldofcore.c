#ifndef LIST_H_
#define LIST_H_

typedef struct list_s {
  void* data;
  struct list_s* next;
} list_t;

list_t* make_list_data(void*);
void append(list_t*, void*);
void each(list_t*, void (*fn)(void*));
list_t* find(list_t*, int (*pred)(void*));
int length(list_t*);
list_t* map(list_t*, void* (*fn)(void*));

#endif
