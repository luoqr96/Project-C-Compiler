#include "common.h"
#include "var_table.h"
variable new_variable(char * name, v_type t, dimension d, unsigned int o)
{
  variable var = (variable)malloc(sizeof(struct var));
  var->name = name;
  var->var_type = t;
  var->dim = d;
  var->order = 0;
  return var;
}
dimension new_dimension(int n)
{
  dimension d = (dimension)malloc(sizeof(struct dim));
  d->n = n;
  d->next = NULL;
  return d;
}
dimension update_dimension(dimension h, int n)
{
  dimension d = new_dimension(n);
  dimension p = h;
  while(1) {
    if(!p->next) {
      p->next = d;
      break;
    }
    p = p->next;
  }
  return h;
}
parameter new_parameter(variable var)
{
  parameter p = (parameter)malloc(sizeof(struct param));
  p->var = var;
  p->next = NULL;
  return p;
}
parameter update_parameter(parameter h, variable var)
{
  parameter p = h;
  while(1) {
    if(!p->next) {
      p->next = new_parameter(var);
      break;
    }
    p = p->next;
  }
  return h;
}
expression new_const_expression(e_type tp1, v_type tp2)
{
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->exp_type = tp1;
  expr->return_type = tp2;
  expr->exp1 = NULL;
  expr->exp2 = NULL;
  expr->dim = NULL;
  expr->get_address_able = 0;
  return expr;
}
expression new_var_expression(variable var, e_type tp)
{
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->exp_type = tp;
  expr->var = var;
  expr->exp1 = NULL;
  expr->exp2 = NULL;
  expr->dim = var->dim;
  expr->get_address_able = 1;
  return expr;
}
v_type get_binary_opr_type(OP op, expression exp1, expression exp2)
{
  v_type tp_exp1, tp_exp2, ret;
  if(op == ADD || op == SUB
    || op == MUL || op == DIV) {
      switch (exp1->return_type) {
        case TYPE_BOOL: tp_exp1 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp1 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp1 = TYPE_INT; break;
        case TYPE_FLOAT: tp_exp1 = TYPE_FLOAT; break;
        case TYPE_DOUBLE: tp_exp1 = TYPE_DOUBLE; break;
        default: return TYPE_ERROR;
      }
      switch (exp2->return_type) {
        case TYPE_BOOL: tp_exp2 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp2 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp2 = TYPE_INT; break;
        case TYPE_FLOAT: tp_exp2 = TYPE_FLOAT; break;
        case TYPE_DOUBLE: tp_exp2 = TYPE_DOUBLE; break;
        default: return TYPE_ERROR;
      }
      ret = tp_exp1 > tp_exp2 ? tp_exp1 : tp_exp2;
    }
  else if(op ==  MOD || op == AND || op == OR
    || op == XOR || op == LS || op == RS) {
      switch (exp1->return_type) {
        case TYPE_BOOL: tp_exp1 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp1 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp1 = TYPE_INT; break;
        default: return TYPE_ERROR;
      }
      switch (exp2->return_type) {
        case TYPE_BOOL: tp_exp2 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp2 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp2 = TYPE_INT; break;
        default: return TYPE_ERROR;
      }
      ret = tp_exp1 > tp_exp2 ? tp_exp1 : tp_exp2;
  }
  else if(op == GE || op == G || op == LE || op == L
    || op == EQ || op == NE || op == LOGICAL_OR
    || op == LOGICAL_AND) {
    if(exp1->return_type == TYPE_VOID || exp2->return_type == TYPE_VOID) {
      return TYPE_ERROR;
    }
    ret = TYPE_BOOL;
  }
  else if (op == COMMA) {
    ret = exp1->return_type;
  }
  else {
    return TYPE_ERROR;
  }
  return ret;
}
expression new_binary_expression(OP op, expression exp1, expression exp2)
{
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->op = op;
  expr->exp_type = BINARY;
  expr->exp1 = exp1;
  expr->exp2 = exp2;
  expr->return_type = get_binary_opr_type(op, exp1, exp2);
  return expr;
}
v_type get_unary_opr_type(OP op, expression exp)
{
  v_type ret, t = exp->return_type;
  if(op == LOGICAL_INV) {
    if(t == TYPE_VOID) {
      return TYPE_ERROR;
    }
    else {
      ret = TYPE_BOOL;
    }
  }
  else if(op == GET_ADDR) {
    if(t == TYPE_POINTER) {

    }
  }
  return ret;
}
expression new_unary_expression(OP op, expression exp)
{
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->op = op;
  expr->exp_type = UNARY;
  expr->exp1 = exp;
  expr->return_type = get_unary_opr_type(op, exp);
  return expr;
}
