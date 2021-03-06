#include "common.h"
#include "var_table.h"
#include "func_list.h"
extern void yyerror(char *s);
variable new_variable(char * name, v_type t, dimension d, unsigned int o)
{
  variable var = (variable)malloc(sizeof(struct var));
  var->name = name;
  var->var_type = t;
  //printf("%d\n", t);
  //printf("%d\n", TYPE_DOUBLE);
  if(t == TYPE_ARRAY_INT || t == TYPE_ARRAY_BOOL || t == TYPE_ARRAY_CHAR
     || t == TYPE_ARRAY_FLOAT || t == TYPE_ARRAY_DOUBLE
     || t == TYPE_POINTER_INT || t == TYPE_POINTER_BOOL || t == TYPE_POINTER_CHAR
     || t == TYPE_POINTER_FLOAT || t == TYPE_POINTER_DOUBLE) {
    var->return_type = TYPE_ADDRESS;
  }
  else {
    var->return_type = t;
  }
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
  p->n = 1;
  return p;
}
parameter update_parameter(parameter h, variable var)
{
  if(!h || !var) {
    return h;
  }
  parameter p = h;
  while(1) {
    p->n++;
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
  expr->additional_type = tp2;
  expr->return_type = tp2;
  expr->exp1 = NULL;
  expr->exp2 = NULL;
  expr->order = 0;
  expr->get_address_able = 0;
  expr->is_const = 1;
  return expr;
}
expression new_var_expression(variable var)
{
  if(!var) {
    return NULL;
  }
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->exp_type = VARIABLE;
  expr->var = var;
  expr->additional_type = var->var_type;
  expr->return_type = var->return_type;
  expr->exp1 = NULL;
  expr->exp2 = NULL;
  expr->order = var->order;
  expr->get_address_able = 1;
  expr->is_const
  = ((var->var_type == TYPE_ARRAY_INT)
  || (var->var_type == TYPE_ARRAY_BOOL)
  || (var->var_type == TYPE_ARRAY_CHAR)
  || (var->var_type == TYPE_ARRAY_FLOAT)
  || (var->var_type == TYPE_ARRAY_DOUBLE));
  return expr;
}
v_type get_binary_opr_type(OP op, expression exp1, expression exp2)
{
  v_type tp_exp1, tp_exp2, ret;
  if(op == GE || op == G || op == LE || op == L
    || op == EQ || op == NE || op == LOGICAL_OR
    || op == LOGICAL_AND) {
    if(exp1->return_type == TYPE_VOID || exp2->return_type == TYPE_VOID) {
      yyerror("Illegal type!");
      return TYPE_ERROR;
    }
    ret = TYPE_BOOL;
  }
  else if(exp1->return_type == TYPE_ADDRESS) {
    if(exp2->return_type == TYPE_BOOL || exp2->return_type == TYPE_INT || exp2->return_type == TYPE_CHAR) {
      if(op == ADD || op == SUB) {
        ret = TYPE_ADDRESS;
      }
      else {
        ret = TYPE_ERROR;
        yyerror("表达式必须具有算数类型！");
      }
    }
    else {
        ret = TYPE_ERROR;
        yyerror("表达式必须具有算数类型！");
    }
  }
  else if(exp2->return_type == TYPE_ADDRESS) {
    if(exp1->return_type == TYPE_BOOL || exp1->return_type == TYPE_INT || exp1->return_type == TYPE_CHAR) {
      if(op == SUB) {
        ret = TYPE_ADDRESS;
      }
      else {
        ret = TYPE_ERROR;
        yyerror("表达式必须具有算数类型！");
      }
    }
    else {
        ret = TYPE_ERROR;
        yyerror("表达式必须具有算数类型！");
    }
  }
  else if(op == ADD || op == SUB
    || op == MUL || op == DIV) {
      switch (exp1->return_type) {
        case TYPE_BOOL: tp_exp1 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp1 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp1 = TYPE_INT; break;
        case TYPE_FLOAT: tp_exp1 = TYPE_FLOAT; break;
        case TYPE_DOUBLE: tp_exp1 = TYPE_DOUBLE; break;
        default: yyerror("Illegal type!"); return TYPE_ERROR;
      }
      switch (exp2->return_type) {
        case TYPE_BOOL: tp_exp2 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp2 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp2 = TYPE_INT; break;
        case TYPE_FLOAT: tp_exp2 = TYPE_FLOAT; break;
        case TYPE_DOUBLE: tp_exp2 = TYPE_DOUBLE; break;
        default: yyerror("Illegal type!"); return TYPE_ERROR;
      }
      ret = tp_exp1 > tp_exp2 ? tp_exp1 : tp_exp2;
    }
  else if(op ==  MOD || op == AND || op == OR
    || op == XOR || op == LS || op == RS) {
      switch (exp1->return_type) {
        case TYPE_BOOL: tp_exp1 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp1 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp1 = TYPE_INT; break;
        default: yyerror("左值类型必须为整型！"); return TYPE_ERROR;
      }
      switch (exp2->return_type) {
        case TYPE_BOOL: tp_exp2 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp2 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp2 = TYPE_INT; break;
        default: yyerror("右值类型必须为整型！"); return TYPE_ERROR;
      }
      ret = tp_exp1 > tp_exp2 ? tp_exp1 : tp_exp2;
  }
  else {
    return TYPE_ERROR;
  }
  return ret;
}
expression new_binary_expression(OP op, expression exp1, expression exp2)
{
  if(!exp1 || !exp2) {
    return NULL;
  }
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->op = op;
  expr->exp_type = BINARY;
  expr->exp1 = exp1;
  expr->exp2 = exp2;
  if(op == COMMA) {
    expr->return_type = exp1->return_type;
    expr->is_const = exp1->is_const;
    expr->get_address_able = exp1->get_address_able;
    expr->order = exp1->order;
    expr->additional_type = exp1->additional_type;
  }
  else {
    expr->return_type = get_binary_opr_type(op, exp1, exp2);
    expr->is_const = 1;
    expr->get_address_able = 0;
    if(exp1->return_type == TYPE_ADDRESS) {
      expr->order = exp1->order;
      expr->additional_type = exp1->additional_type;
    }
    else if(exp2->return_type == TYPE_ADDRESS) {
      expr->order = exp1->order;
      expr->additional_type = exp2->additional_type;
    }
    else {
      expr->order = 0;
    }
  }

  return expr;
}
expression new_array_expression(expression exp1, expression exp2)
{
  if(!exp1 || !exp2) {
    return NULL;
  }
  expression expr;
  v_type t = exp1->additional_type;
  expr = (expression)malloc(sizeof(struct exp));
  expr->exp_type = MEM;
  expr->op = GET_MEM;
  expr->exp1 = exp1;
  expr->exp2 = exp2;
  if(!exp1->order) {
    expr->return_type = TYPE_ERROR;
    yyerror("表达式必须包含指向对象的指针类型！");
  }
  else {
    expr->order = exp1->order - 1;
    if(expr->order == 0) {
      expr->is_const = 0;
      switch (t) {
        case TYPE_ARRAY_INT: expr->return_type = TYPE_INT; break;
        case TYPE_ARRAY_FLOAT: expr->return_type = TYPE_FLOAT; break;
        case TYPE_ARRAY_CHAR: expr->return_type = TYPE_CHAR; break;
        case TYPE_ARRAY_BOOL: expr->return_type = TYPE_BOOL; break;
        case TYPE_ARRAY_DOUBLE: expr->return_type = TYPE_DOUBLE; break;
        default: expr->return_type = TYPE_ERROR; break;
      }
    }
    else {
      expr->is_const = 1;
      expr->return_type = TYPE_ADDRESS;
      expr->additional_type = exp1->additional_type;
      switch (t) {
        case TYPE_ARRAY_INT: expr->is_const = 1; break;
        case TYPE_ARRAY_FLOAT: expr->is_const = 1; break;
        case TYPE_ARRAY_CHAR: expr->is_const = 1; break;
        case TYPE_ARRAY_BOOL: expr->is_const = 1; break;
        case TYPE_ARRAY_DOUBLE: expr->is_const = 1; break;
        case TYPE_POINTER_INT: expr->is_const = 0; break;
        case TYPE_POINTER_FLOAT: expr->is_const = 0; break;
        case TYPE_POINTER_CHAR: expr->is_const = 0; break;
        case TYPE_POINTER_BOOL: expr->is_const = 0; break;
        case TYPE_POINTER_DOUBLE: expr->is_const = 0; break;
        default: expr->return_type = TYPE_ERROR; break;
      }
    }
  }
  expr->get_address_able = 1;

  return expr;
}
v_type get_unary_opr_type(OP op, expression exp)
{
  v_type ret = TYPE_ERROR, t = exp->return_type;
  if(op == LOGICAL_INV) {
    if(t == TYPE_VOID) {
      yyerror("Illegal type!");
      return TYPE_ERROR;
    }
    else {
      ret = TYPE_BOOL;
    }
  }

  else if(op == SIGN_PLUS || op == SIGN_MINUS) {
    if(t == TYPE_CHAR || t == TYPE_BOOL || t == TYPE_INT || t == TYPE_FLOAT || t == TYPE_DOUBLE) {
      ret = t;
    }
    else {
      ret = TYPE_ERROR;
    }
  }
  else {
    ret = TYPE_ERROR;
  }
  return ret;
}
expression new_unary_expression(OP op, expression exp)
{
  if(!exp) {
    return NULL;
  }
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->op = op;
  expr->exp_type = UNARY;
  expr->additional_type = exp->additional_type;
  expr->exp1 = exp;
  expr->exp2 = NULL;
  if(op == GET_ADDR) {
    expr->get_address_able = 0;
    expr->is_const = 1;
    expr->order = exp->order + 1;
    if(exp->get_address_able) {
      expr->return_type = TYPE_ADDRESS;
      switch(exp->return_type) {
        case TYPE_INT: expr->additional_type = TYPE_POINTER_INT; break;
        case TYPE_BOOL: expr->additional_type = TYPE_POINTER_BOOL; break;
        case TYPE_CHAR: expr->additional_type = TYPE_POINTER_CHAR; break;
        case TYPE_FLOAT: expr->additional_type = TYPE_POINTER_FLOAT; break;
        case TYPE_DOUBLE: expr->additional_type = TYPE_POINTER_DOUBLE; break;
        default: expr->additional_type = exp->return_type; break;
      }
    }
    else {
      yyerror("表达式必须为左值或函数指示符！");
      expr->return_type = TYPE_ERROR;
    }
  }
  else if(op == GET_VAL) {
    expr->get_address_able = 1;
    expr->is_const = 0;
    if(!exp->order) {
      yyerror("\"*\"的操作数必须是指针！");
      expr->return_type = TYPE_ERROR;
    }
    else if(exp->order == 1) {
      expr->order = 0;
      switch(exp->additional_type) {
        case TYPE_ARRAY_INT: expr->return_type = TYPE_INT; break;
        case TYPE_ARRAY_FLOAT: expr->return_type = TYPE_FLOAT; break;
        case TYPE_ARRAY_CHAR: expr->return_type = TYPE_CHAR; break;
        case TYPE_ARRAY_BOOL: expr->return_type = TYPE_BOOL; break;
        case TYPE_ARRAY_DOUBLE: expr->return_type = TYPE_DOUBLE; break;
        case TYPE_POINTER_INT: expr->return_type = TYPE_INT; break;
        case TYPE_POINTER_FLOAT: expr->return_type = TYPE_FLOAT; break;
        case TYPE_POINTER_CHAR: expr->return_type = TYPE_CHAR; break;
        case TYPE_POINTER_BOOL: expr->return_type = TYPE_BOOL; break;
        case TYPE_POINTER_DOUBLE: expr->return_type = TYPE_DOUBLE; break;
        default: expr->return_type = TYPE_ERROR; break;
      }
    }
    else {
      expr->order = exp->order - 1;
      expr->return_type = TYPE_ADDRESS;
    }
  }
  else {
    expr->return_type = get_unary_opr_type(op, exp);
  }
  if(op == SIGN_PLUS || op == SIGN_MINUS || op == LOGICAL_INV) {
    exp->is_const = 1;
  }
  else {

  }
  return expr;
}
expression new_self_expression(OP op, expression exp, e_type tp)
{
  if(!exp) {
    return NULL;
  }
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->op = op;
  expr->exp_type = tp;
  expr->additional_type = exp->additional_type;
  if(exp->is_const) {
    yyerror("不可修改的值!");
  }
  expr->return_type = exp->return_type;
  expr->exp1 = exp;
  expr->exp2 = NULL;
  expr->is_const = 1;
  expr->get_address_able = 0;
  expr->order = exp->order;
  return expr;
}

expression new_assign_expression(OP op, expression exp1, expression exp2)
{
  if(!exp1 || !exp2) {
    return NULL;
  }
  expression expr;
  v_type tp1 = exp1->return_type;
  v_type tp2 = exp2->return_type;
  expr = (expression)malloc(sizeof(struct exp));
  expr->additional_type = exp1->additional_type;
  expr->op = op;
  expr->exp_type = ASSIGNMENT;
  if(exp1->is_const) {
    yyerror("Constant lvalue!");
    expr->return_type = TYPE_ERROR;
  }
  else {
    if(op == ASSIGN) {
      if(tp2 == TYPE_VOID) {
        yyerror("右值类型不能为空！");
      }
      else if(tp1 == TYPE_ADDRESS) {
        if(tp2 != TYPE_ADDRESS) {
          yyerror("右值类型必须为指针类型！");
        }
      }
      else if(tp1 == TYPE_FLOAT || tp1 == TYPE_DOUBLE) {
        if(tp2 == TYPE_ADDRESS) {
          yyerror("右值类型必须为整型！");
        }
      }
      else {

      }
    }
    else if(op == ADD_ASSIGN || op == SUB_ASSIGN || op == MUL_ASSIGN
      || op == DIV_ASSIGN || op == XOR_ASSIGN) {
      if(tp2 == TYPE_VOID) {
        yyerror("右值类型不能为空！");
      }
      else if(tp1 == TYPE_ADDRESS) {
        if(op == ADD_ASSIGN || op == SUB_ASSIGN) {
          if(tp2 == TYPE_DOUBLE || tp2 == TYPE_FLOAT || tp2 == TYPE_ADDRESS) {
            yyerror("右值类型必须为整型！");
          }
        }
        else {
          yyerror("表达式必须包含算数类型");
        }
      }
      else if(tp2 == TYPE_ADDRESS) {
        yyerror("表达式必须包含算数类型");
      }
      else {

      }
    }
    else if(op == MOD_ASSIGN || op == XOR_ASSIGN || op == MOD_ASSIGN
      || op == RS_ASSIGN || op == LS_ASSIGN) {
        if(tp2 == TYPE_VOID) {
          yyerror("右值类型不能为空！");
        }
        else if(tp1 == TYPE_ADDRESS || tp1 == TYPE_FLOAT || tp1 == TYPE_DOUBLE) {
          yyerror("左值必须为整型！");
        }
        else {
          if(tp2 == TYPE_FLOAT || tp2 == TYPE_DOUBLE || tp2 == TYPE_ADDRESS) {
            yyerror("右值必须为整型！");
          }
        }
    }
    else {
      yyerror("Unknow error!");
    }
  }
  expr->return_type = exp1->return_type;
  expr->exp1 = exp1;
  expr->exp2 = exp2;
  expr->is_const = exp1->is_const;
  expr->get_address_able = exp1->get_address_able;
  expr->order = exp1->order;
  return expr;
}
expression new_function_expression(function f)
{
  expression expr;
  if(!f) {
    return NULL;
  }
  expr = (expression)malloc(sizeof(struct exp));
  expr->f = f;
  expr->return_type = f->return_type;
  expr->exp_type = CALL;
  expr->additional_type = f->return_type;
  expr->exp1 = NULL;
  expr->exp2 = NULL;
  expr->is_const = 1;
  expr->get_address_able = 0;
  expr->order = 0;
  return expr;
}

var_init new_var_init(variable var, expression exp)
{
  var_init vi = (var_init)malloc(sizeof(struct v_init));
  vi->var = var;
  vi->exp = exp;
  //printf("Check\n");
  if(exp) {
    if(exp->return_type == TYPE_VOID) {
      yyerror("右值类型不能为空！");
      return NULL;
    }
    else if(var->return_type == TYPE_ADDRESS) {
      if(exp->return_type == TYPE_DOUBLE || exp->return_type == TYPE_FLOAT) {
        yyerror("右值类型必须为整型！");
        return NULL;
      }
    }
    else if(var->return_type == TYPE_FLOAT || var->return_type == TYPE_DOUBLE) {
      //printf("FLOAT\n");
      if(exp->return_type == TYPE_ADDRESS) {
        yyerror("右值类型必须为整型！");
      }
    }
    else {

    }
  }
  return vi;
}
statement new_stmt_init(var_init vi)
{
  statement s = (statement)malloc(sizeof(struct stmt));
  s->isInit = 1;
  s->init = vi;
  s->exp = NULL;
  s->next = NULL;
  return s;
}
