
#include "common.h"
#include <string.h>
function new_function(char *name, parameter param, compound_statement cpd_stmt, v_type vt)
{
  function f = (function)malloc(sizeof(struct func));
  f->name = name;
  f->param = param;
  f->cpd_stmt = cpd_stmt;
  f->return_type = vt;
  return f;
}

func_list gen_func_list()
{
  func_list list = (func_list)malloc(sizeof(struct f_list));
  list->f = NULL;
  list->next = NULL;
  return list;
}
function insert_func(func_list list, char *name, parameter param, compound_statement cpd_stmt, v_type vt)
{
  func_list t, p = list;
  function f = NULL;
  if(p->f == NULL) {
    f = new_function(name, param, cpd_stmt, vt);
    p->f = f;
  }
  else {
    while(1) {
      if(!strcmp(name, p->f->name)) {
        return NULL;
      }
      else if(!p->next) {
        t = (func_list)malloc(sizeof(struct f_list));
        t->f = (f = new_function(name, param, cpd_stmt, vt));
        t->next = NULL;
        p->next = t;
        break;
      }
      p = p->next;
    }
  }
  return f;
}
