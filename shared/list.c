#include "err_helpers.h"
#include "list.h"

list_t* make_list_data(void* data)
{
  list_t* list = xcalloc(1, sizeof(list_t));
  list->data = data;
  return list;
}

void append(list_t* list, void* data)
{
  while (list->next) {
    list = list->next;
  }
  list->next = make_list_data(data);
}

void each(list_t* list, void (*fn)(void*))
{
  while (list) {
    fn(list->data);
    list = list->next;
  }
}

list_t* map(list_t* list, void* (*fn)(void*))
{
  list_t* ret = make_list_data(fn(list->data));
  list = list->next;

  while (list) {
    append(ret, fn(list->data));
    list = list->next;
  }

  return ret;
}

int length(list_t* list)
{
  int size = 0;

  while (list) {
    size++;
    list = list->next;
  }

  return size;
}