#include "err_helpers.h"
#include "kv.h"

kv_t* make_kv(char* key, char* value)
{
  kv_t* kv = xmalloc(sizeof(kv_t));
  kv->key = key;
  kv->value = value;
  return kv;
}
