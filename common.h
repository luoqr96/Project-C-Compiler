#include <stdlib.h>
#ifndef _COMMON_H
#define _COMMON_H
typedef enum {
  TYPE_BOOL, TYPE_CHAR, TYPE_INT, TYPE_FLOAT,  TYPE_DOUBLE, TYPE_STRING,
  TYPE_POINTER_BOOL, TYPE_POINTER_CHAR, TYPE_POINTER_INT, TYPE_POINTER_FLOAT, TYPE_POINTER_DOUBLE,
  TYPE_ARRAY_BOOL, TYPE_ARRAY_CHAR, TYPE_ARRAY_INT, TYPE_ARRAY_FLOAT, TYPE_ARRAY_DOUBLE,
  TYPE_VOID, TYPE_ADDRESS, TYPE_ERROR
} v_type;
typedef enum {
  ADD, SUB, MUL, DIV, MOD, AND, OR, XOR, LS, RS, GE, G, LE, L, EQ, NE,
  LOGICAL_AND, LOGICAL_OR, LOGICAL_INV, COMMA, GET_ADDR, GET_VAL, GET_MEM,
  SIGN_MINUS, SIGN_PLUS, BITWISE_NEG, INCRE, DECRE, ASSIGN, OR_ASSIGN, AND_ASSIGN,
  ADD_ASSIGN, SUB_ASSIGN, XOR_ASSIGN, DIV_ASSIGN, MUL_ASSIGN, MOD_ASSIGN, LS_ASSIGN, RS_ASSIGN
} OP;
typedef enum {
  VARIABLE, CONST_CHAR, CONST_STR, CONST_INT, CONST_FLOAT, UNARY, BINARY, INCRE_LEFT,
  DECRE_RIGHT, INCRE_RIGHT, DECRE_LEFT, ASSIGNMENT, MEM, CALL
} e_type;


typedef struct en * entry;
typedef entry * table;
typedef struct f_list * func_list;
typedef struct v_table * var_table;
typedef struct dim * dimension;
typedef struct cpd_stmt * compound_statement;
typedef struct func * function;
typedef struct var * variable;
typedef struct param * parameter;
typedef struct exp * expression;
typedef struct v_init * var_init;
typedef struct stmt * statement;
typedef struct pgm * program;
struct f_list {
  function f;
  func_list next;
};
struct en {
  variable var;
  entry next;
};
struct v_table {
  table tb;
  var_table parent;
  var_table child;
  var_table sibling;
};
struct dim {
  int n;
  struct dim * next ;
};
struct var {
  v_type var_type;
  v_type return_type;
  char * name;
  dimension dim;     //for array
  unsigned int order;         //for pointer
};
struct param {
  int n;
  variable var;
  parameter next;
};
struct exp {
  OP op;
  e_type exp_type;
  v_type additional_type;
  v_type return_type;
  variable var;
  function f;
  _Bool get_address_able;
  _Bool is_const;
  // char const_char;
  // char * const_str;
  // float const_float;
  // int const_int;
  int order;

  expression exp1;
  expression exp2;
};
struct v_init {
  variable var;
  expression exp;
};

struct stmt {
  compound_statement p_cpd_stmt;
  _Bool isInit;
  var_init init;
  expression exp;
  statement * next;
};
struct cpd_stmt {
  compound_statement p_cpd_stmt;
  var_table local_tb;
  statement stmt;
};
struct func {
  char * name;
  parameter param;
  compound_statement cpd_stmt;
  v_type return_type;
};
struct pgm {
  _Bool isInit;
  var_init init;
  function func;
  program * next;
};

#endif
