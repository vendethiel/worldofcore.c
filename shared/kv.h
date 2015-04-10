#ifndef KV_H_
#define KV_H_

typedef struct {
  char* key;
  char* value;
} kv_t;

kv_t* make_kv(char*, char*);

#endif
