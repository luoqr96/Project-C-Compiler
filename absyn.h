#include "common.h"
#include "var_table.h"
extern void yyerror(char *s);
variable new_variable(char * name, v_type t, dimension d, unsigned int o)
{
  variable var = (variable)malloc(sizeof(struct var));
  var->name = name;
  var->var_type = t;
  //printf("%d\n", t);
  //printf("%d\n", TYPE_DOUBLE);
  if(t == TYPE_ARRAY || t == TYPE_POINTER) {
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
  expr->is_const = 1;
  return expr;
}
expression new_var_expression(variable var)
{
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->exp_type = VARIABLE;
  expr->var = var;
  expr->return_type = var->return_type;
  expr->exp1 = NULL;
  expr->exp2 = NULL;
  expr->dim = var->dim;
  expr->get_address_able = 1;
  expr->is_const = 0;
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
        case TYPE_ADDRESS: tp_exp1 = TYPE_ADDRESS; break;
        default: yyerror("Illegal type!"); return TYPE_ERROR;
      }
      switch (exp2->return_type) {
        case TYPE_BOOL: tp_exp2 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp2 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp2 = TYPE_INT; break;
        case TYPE_FLOAT: tp_exp2 = TYPE_FLOAT; break;
        case TYPE_DOUBLE: tp_exp2 = TYPE_DOUBLE; break;
        case TYPE_ADDRESS: tp_exp2 = TYPE_ADDRESS; break;
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
        default: yyerror("Illegal type!"); return TYPE_ERROR;
      }
      switch (exp2->return_type) {
        case TYPE_BOOL: tp_exp2 = TYPE_BOOL; break;
        case TYPE_CHAR: tp_exp2 = TYPE_CHAR; break;
        case TYPE_INT: tp_exp2 = TYPE_INT; break;
        default: yyerror("Illegal type!"); return TYPE_ERROR;
      }
      ret = tp_exp1 > tp_exp2 ? tp_exp1 : tp_exp2;
  }
  else if(op == GE || op == G || op == LE || op == L
    || op == EQ || op == NE || op == LOGICAL_OR
    || op == LOGICAL_AND) {
    if(exp1->return_type == TYPE_VOID || exp2->return_type == TYPE_VOID) {
      yyerror("Illegal type!");
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
  expr->is_const = 1;
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
  else if(op == GET_ADDR) {
    //????
  }
  else if(op == GET_VAL) {
    //????
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
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->op = op;
  expr->exp_type = UNARY;
  expr->exp1 = exp;
  expr->exp2 = NULL;
  expr->return_type = get_unary_opr_type(op, exp);
  exp->is_const = (op == SIGN_PLUS || op == SIGN_MINUS);
  return expr;
}
expression new_self_expression(OP op, expression exp, e_type tp)
{
  expression expr;
  expr = (expression)malloc(sizeof(struct exp));
  expr->op = op;
  expr->exp_type = tp;
  if(exp->is_const) {
    yyerror("不可修改的值!");
  }
  expr->return_type = exp->return_type;
  expr->exp1 = exp;
  exp->is_const = 1;
  return expr;
}

expression new_assign_expression(OP op, expression exp1, expression exp2)
{
  expression expr;
  v_type tp1 = exp1->return_type;
  v_type tp2 = exp2->return_type;
  expr = (expression)malloc(sizeof(struct exp));
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
        if(tp2 == TYPE_DOUBLE || tp2 == TYPE_FLOAT) {
          yyerror("右值类型必须为整型！");
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
  expr->is_const = 1;

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
