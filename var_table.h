#include "common.h"
#include <string.h>
const unsigned int SIZE = 109;

var_table gen_table()
{
  int i;
  var_table vt;
  vt = (var_table)malloc(sizeof(struct v_table));
  table tb = (table)malloc(sizeof(entry) * SIZE);
  for(i = 0; i < SIZE; i++) {
    tb[i] = NULL;
  }
  vt->tb = tb;
  vt->parent = NULL;
  vt->child = NULL;
  vt->sibling = NULL;
  return vt;
}
int hash(char * id)
{
  char *p;
  int h;
  for(p = id; *p; p++) {
    h += (int)*p * (int)*p;
  }
  return h;
}
entry new_entry(variable var, entry next)
{
  entry en = (entry)malloc(sizeof(struct en));
  en->var = var;
  en->next = next;
  return en;
}
void insert(var_table vt, variable var)
{
  table tb = vt->tb;
  int index = hash(var->name) % SIZE;
  tb[index] = new_entry(var, tb[index]);
}
entry lookup(var_table vt, char * id)
{
  table tb;
  int h = hash(id);
  int index = h % SIZE;
  entry en;
  // printf("global:%s\n", id);
  // printf("global:%d\n", h);
  // printf("global:%d\n", index);
  // printf("global:%d\n", SIZE);
  while(vt) {
    tb = vt->tb;
    for(en = tb[index]; en; en = en->next) {
      if(!strcmp(id, en->var->name)) {
        return en;
      }
    }
    vt = vt->parent;
  }
  return NULL;
}
entry lookup_in_cur_environment(var_table vt, char * id)
{
  table tb;
  int h = hash(id);
  int index = h % SIZE;
  // printf("local:%s\n", id);
  // printf("local:%d\n", h);
  // printf("local:%d\n", index);
  // printf("local:%d\n", SIZE);
  entry en;
  tb = vt->tb;
  for(en = tb[index]; en; en = en->next) {
    //printf("CHECKVAR:%s\n", en->var->name);
    if(!strcmp(id, en->var->name)) {
      //printf("succeed\n");
      return en;
    }
  }
  //printf("not find\n");
  return NULL;
}

void add_child_table(var_table vt, var_table c)
{
  var_table ptr = vt->child;
  c->parent = vt;
  if(!ptr) {
    vt->child = c;
    return;
  }
  for(; ; ptr = ptr->sibling) {
    if(!ptr->sibling) {
      ptr->sibling = c;
      break;
    }
  }
}
