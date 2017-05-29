#include "common.h"
#include <string.h>
extern void yyerror(char *s);
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
function check_function(func_list list, char * name, expression expr)
{
  v_type *type;
  func_list p = list;
  parameter param;
  expression exp = expr;
  int i = 0, j;
  while(1) {
    if(p && p->f) {
      if(!strcmp(name, p->f->name)) {
        param = p->f->param;
        if((!param && expr) || (param && !expr)) {
            yyerror("函数参数个数不匹配！");
            return NULL;
        }
        else if(!param && !expr) {
            return p->f;
        }
        type = (v_type *)malloc(sizeof(v_type) * param->n);
        while(param) {
          type[i++] = param->var->return_type;
          param = param->next;
        }
        for(j = i - 1; j >= 0; j--) {
           if(j == 0) {
               if(exp->return_type != type[0]) {
                   yyerror("函数参数类型不匹配！");
                   free(type);
                   return NULL;
               }
                else if(exp->op == COMMA) {
                   yyerror("函数参数个数不匹配！");
                   free(type);
                   return NULL;
               }
               else {
                   free(type);
                   return p->f;
               }
          }
          else if(exp->op != COMMA) {
            yyerror("函数参数个数不匹配！");
            free(type);
            return NULL;
          }
          else {
            v_type t = exp->exp2->return_type;
            if(t == TYPE_BOOL || t == TYPE_INT || t == TYPE_FLOAT || t == TYPE_DOUBLE || t == TYPE_CHAR) {
              if(type[i] == TYPE_BOOL || type[i] == TYPE_INT || type[i] == TYPE_FLOAT || type[i] == TYPE_DOUBLE || type[i] == TYPE_CHAR) {

              }
              else {
                yyerror("函数参数类型不匹配！");
                free(type);
                return NULL;
              }
            }
            else if(t != type[i]) {
              yyerror("函数参数类型不匹配！");
              free(type);
              return NULL;
            }

          }

          exp = exp->exp1;
        }
      }
    }
    else {
      break;
    }
    p = p->next;
  }
  yyerror("未定义函数！");
  return NULL;
}
