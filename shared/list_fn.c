#include <string.h>
#include "list.h"
#include "kv.h"

char* find_value_by_key(list_t* list, char* key)
{
  while (list) {
    kv_t* kv = (kv_t*)list->data;
    if (!strcmp(key, kv->key)) {
      return kv->value;
    }
  }

  return NULL;
}

list_t* find(list_t* list, int (*pred)(void*))
{
  while (list) {
    if (pred(list->data)) {
      return list;
    }
    list = list->next;
  }
  return NULL;
}

void append_ptr(list_t** list, void* data)
{
  if (*list) {
    append(*list, data);
  } else {
    *list = make_list_data(data);
  }
}
