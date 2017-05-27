%{
#include <stdlib.h>
#include "absyn.h"
int yylex();
void yyerror(char *s);
extern int col;
extern int row;
var_table global_table;
var_table temp_table;
var_table parent_table;
%}
%union {
	int const_int;
	float const_float;
	char const_char;
  char *const_str;
	char *id;
	union { v_type tp; int order; } t;
	expression exp;
	v_type tp;
	variable var;
	parameter p;
	OP op;
}
%type <t> SIMPLE_TYPE POINTER_TYPE TYPE
%type <var> DECLARATION_ARRAY DECLARATION
%type <p> PARAMETER
%token <id> IDENTIFIER
%type <exp> IDENTIFIER_EXPRESSION EXPRESSION CONSTANT_EXPRESSION ASSIGNMENT_EXPRESSION
%type <exp> SELF_OPERATION BINARY_OPERATION UNARY_OPERATION ARRAY_OPERATION CALL_FUNCTION
%token <tp> BOOL CHAR FLOAT INT  DOUBLE VOID
%token <const_float> CONSTANT_FLOAT
%token <const_str> CONSTANT_STRING
%token <const_int> CONSTANT_INTEGER
%token <const_char> CONSTANT_CHARACTER
%token OP_RS OP_LS OP_OR OP_EQ OP_AND OP_NE OP_GE OP_LE OP_PTR OP_INCRE OP_DECRE
%token ASSIGN_ADD ASSIGN_SUB ASSIGN_RS ASSIGN_MUL ASSIGN_LS ASSIGN_DIV ASSIGN_OR ASSIGN_XOR ASSIGN_AND ASSIGN_MOD
%token CONST IF ELSE FOR BREAK CONTINUE STRUCT WHILE COMMENT RETURN
%left ','
%right '=' ASSIGN_ADD ASSIGN_SUB ASSIGN_RS ASSIGN_MUL ASSIGN_LS ASSIGN_DIV ASSIGN_OR ASSIGN_XOR ASSIGN_AND ASSIGN_MOD
%left OP_OR
%left OP_AND
%left '^'
%left '|'
%left '&'
%left OP_NE
%left OP_EQ
%left OP_LE OP_GE '<' '>'
%left OP_LS OP_RS
%left '+' '-'
%left '*' '/' '%'
%right BIT_NEG INV GET_ADDRESS GET_VALUE PREFIX_INCRE PREFIX_DECRE POS NEG
%left OP_INCRE OP_DECRE
%left '[' ']'
%nonassoc IFX
%nonassoc ELSE
%%

CODE_TEXT
    : PROGRAM        {  }
    ;
PROGRAM
    : FUNCTION
		| PROGRAM FUNCTION
		| INITIALIZATION_STATEMENT
		| PROGRAM INITIALIZATION_STATEMENT
    ;
FUNCTION
    : TYPE IDENTIFIER '(' PARAMETER ')' ';'
    | TYPE IDENTIFIER '(' VOID ')' ';'
    | TYPE IDENTIFIER '('  ')' ';'
    | TYPE IDENTIFIER '(' PARAMETER ')' COMPOUND_STATEMENT    {  }
    | TYPE IDENTIFIER '(' VOID ')' COMPOUND_STATEMENT    {  }
    | TYPE IDENTIFIER '('  ')' COMPOUND_STATEMENT    {  }
    ;

DECLARATION
    : TYPE IDENTIFIER				{ $$ = new_variable($2, $1.tp, NULL, 0); }
		| DECLARATION_ARRAY			{ $$ = $1; }
    ;
DECLARATION_ARRAY
		: TYPE IDENTIFIER '[' ']'						{ $$ = new_variable($2, $1.tp, new_dimension(0), $1.order); }
		| TYPE IDENTIFIER '[' CONSTANT_INTEGER ']'						{ $$ = new_variable($2, $1.tp, new_dimension($4), $1.order); }
		| DECLARATION_ARRAY '[' ']'					{ update_dimension($1->dim, 0); $$ = $1; }
		| DECLARATION_ARRAY '[' CONSTANT_INTEGER ']'					{ update_dimension($1->dim, $3); $$ = $1; }
		;
TYPE
    : SIMPLE_TYPE				{ $$ = $1; }
    | POINTER_TYPE			{ $$ = $1; }
    ;

SIMPLE_TYPE
		: BOOL					{ $$.tp = $1; $$.order = 0; }
    | CHAR					{ $$.tp = $1; $$.order = 0; }
		| INT						{ $$.tp = $1; $$.order = 0; }
    | FLOAT					{ $$.tp = $1; $$.order = 0; }
    | DOUBLE				{ $$.tp = $1; $$.order = 0; }
		| VOID					{ $$.tp = $1; $$.order = 0; }
    ;

POINTER_TYPE
    : SIMPLE_TYPE '*'				{ $$ = $1; $$.order = 1; }
    | POINTER_TYPE '*'			{ $$ = $1; $$.order++; }
    ;

PARAMETER
    : DECLARATION						{ $$ = new_parameter($1); }
    | PARAMETER ',' DECLARATION				{ $$ = update_parameter($1, $3); }
    ;

COMPOUND_STATEMENT
		: LPAREN RPAREN
		| LPAREN STATEMENT_LIST RPAREN
		;
LPAREN
		: '{'			{ parent_table = temp_table; temp_table = gen_table(); add_child_table(parent_table, temp_table); }
		;
RPAREN
		: '}'			{ temp_table = temp_table->parent; }
		;
STATEMENT_LIST
    : STATEMENT
		| STATEMENT_LIST ';'
    | STATEMENT_LIST STATEMENT
		| COMPOUND_STATEMENT
		| STATEMENT_LIST COMPOUND_STATEMENT
    ;
IF_STATEMENT
		: IF '(' EXPRESSION ')' STATEMENT																		%prec IFX  { printf("1\n"); }
		| IF '(' EXPRESSION ')' STATEMENT ELSE STATEMENT										%prec IFX	 { printf("2\n"); }
		| IF '(' EXPRESSION ')' COMPOUND_STATEMENT ELSE STATEMENT						%prec IFX  { printf("3\n"); }
		| IF '(' EXPRESSION ')' STATEMENT ELSE COMPOUND_STATEMENT						%prec IFX  { printf("4\n"); }
		| IF '(' EXPRESSION ')' COMPOUND_STATEMENT													%prec IFX  { printf("5\n"); }
		| IF '(' EXPRESSION ')' COMPOUND_STATEMENT ELSE COMPOUND_STATEMENT  %prec IFX  { printf("6\n"); }
		| IF '(' EXPRESSION ')' ';'																					%prec IFX  { printf("7\n"); }
		;
WHILE_STATEMENT
		: WHILE '(' EXPRESSION ')' COMPOUND_STATEMENT
		| WHILE '(' EXPRESSION ')' ';'
		| WHILE '(' EXPRESSION ')' STATEMENT
		;
FOR_STATEMENT
		: FOR '(' FOR_EXP ')' COMPOUND_STATEMENT
		| FOR '(' FOR_EXP ')' ';'
		| FOR '(' FOR_EXP ')' STATEMENT
		;
FOR_EXP
		: FOR_EXP1 FOR_EXP1
		| FOR_EXP1 FOR_EXP1 EXPRESSION
		;
FOR_EXP1
		: STATEMENT
		| ';'
		;

RETURN_STATEMENT
		: RETURN ';'
		| RETURN EXPRESSION ';'
		;

STATEMENT
    : EXPRESSION ';'
		| IF_STATEMENT
		| INITIALIZATION_STATEMENT
		| WHILE_STATEMENT
		| FOR_STATEMENT
		| RETURN_STATEMENT
		| BREAK ';'
		| CONTINUE ';'
    ;

INITIALIZATION_STATEMENT
		: DECLARATION ';'
		| DECLARATION '=' EXPRESSION ';'
		;


EXPRESSION
    : IDENTIFIER_EXPRESSION		{ $$ = $1; }
    | CONSTANT_EXPRESSION		{ $$ = $1; }
    /*| ASSIGNMENT_EXPRESSION		{ $$ = $1; }*/
    | SELF_OPERATION		{ $$ = $1; }
    | BINARY_OPERATION		{ $$ = $1; }
    | UNARY_OPERATION		{ $$ = $1; }
		| ARRAY_OPERATION		{ $$ = $1; }
		| '(' EXPRESSION ')'		{ $$ = $2; }
		/*| CALL_FUNCTION		{ $$ = $1; }*/
    ;
CALL_FUNCTION
		: IDENTIFIER '(' EXPRESSION ')'
		;
ARRAY_OPERATION
		: EXPRESSION '[' EXPRESSION ']'
		;
CONSTANT_EXPRESSION
    : CONSTANT_FLOAT				{ $$ = new_const_expression(CONST_FLOAT, TYPE_FLOAT); }
    | CONSTANT_INTEGER			{ $$ = new_const_expression(CONST_INT, TYPE_INT); }
    | CONSTANT_STRING				{ $$ = new_const_expression(CONST_STR, TYPE_STRING); }
    | CONSTANT_CHARACTER		{ $$ = new_const_expression(CONST_CHAR, TYPE_CHAR); }
    ;
IDENTIFIER_EXPRESSION
    : IDENTIFIER			{
													entry en = lookup(temp_table, $1);
													if(en) {
														$$ = new_var_expression(en->var, VARIABLE);
													}
													else {
														yyerror("Uninitialized variable!");
													}
			/*check table first*/ /* $$ = new_simple_expression(VARIABLE, TYPE_ERROR); */
											}
    ;
ASSIGNMENT_EXPRESSION
    : EXPRESSION '=' EXPRESSION
    | EXPRESSION ASSIGN_OR EXPRESSION
    | EXPRESSION ASSIGN_AND EXPRESSION
    | EXPRESSION ASSIGN_XOR EXPRESSION
    | EXPRESSION ASSIGN_ADD EXPRESSION
    | EXPRESSION ASSIGN_SUB EXPRESSION
    | EXPRESSION ASSIGN_MUL EXPRESSION
    | EXPRESSION ASSIGN_LS EXPRESSION
    | EXPRESSION ASSIGN_RS EXPRESSION
    | EXPRESSION ASSIGN_MOD EXPRESSION
    | EXPRESSION ASSIGN_DIV EXPRESSION
    ;

UNARY_OPERATION
    : '~' EXPRESSION    %prec BIT_NEG					{ $$ = new_unary_expression(BITWISE_NEG, $2); }
    | '!' EXPRESSION    %prec INV							{ $$ = new_unary_expression(LOGICAL_INV, $2); }
    | '&' EXPRESSION    %prec GET_ADDRESS			{ $$ = new_unary_expression(GET_ADDR, $2); }
    | '*' EXPRESSION    %prec GET_VALUE				{ $$ = new_unary_expression(GET_VAL, $2); }
    | '-' EXPRESSION    %prec NEG							{ $$ = new_unary_expression(SIGN_MINUS, $2); }
    | '+' EXPRESSION    %prec POS							{ $$ = new_unary_expression(SIGN_PLUS, $2); }
    ;
SELF_OPERATION
    : OP_INCRE EXPRESSION    %prec PREFIX_INCRE			{ $$ = new_self_expression(INCRE, $2, INCRE_LEFT); }
    | OP_DECRE EXPRESSION    %prec PREFIX_DECRE			{ $$ = new_self_expression(DECRE, $2, DECRE_LEFT); }
    | EXPRESSION OP_INCRE			{ $$ = new_self_expression(INCRE, $1, INCRE_RIGHT); }
    | EXPRESSION OP_DECRE			{ $$ = new_self_expression(DECRE, $1, DECRE_RIGHT); }
    ;
BINARY_OPERATION
    : EXPRESSION '+' EXPRESSION		{ $$ = new_binary_expression(ADD, $1, $3); }
    | EXPRESSION '-' EXPRESSION		{ $$ = new_binary_expression(SUB, $1, $3); }
    | EXPRESSION '*' EXPRESSION		{ $$ = new_binary_expression(MUL, $1, $3); }
    | EXPRESSION '/' EXPRESSION		{ $$ = new_binary_expression(DIV, $1, $3); }
    | EXPRESSION '%' EXPRESSION		{ $$ = new_binary_expression(MOD, $1, $3); }
    | EXPRESSION '^' EXPRESSION		{ $$ = new_binary_expression(XOR, $1, $3); }
    | EXPRESSION '&' EXPRESSION		{ $$ = new_binary_expression(AND, $1, $3); }
    | EXPRESSION '|' EXPRESSION		{ $$ = new_binary_expression(OR, $1, $3); }
		| EXPRESSION ',' EXPRESSION		{ $$ = new_binary_expression(COMMA, $1, $3); }
		| EXPRESSION '<' EXPRESSION		{ $$ = new_binary_expression(L, $1, $3); }
		| EXPRESSION '>' EXPRESSION		{ $$ = new_binary_expression(G, $1, $3); }
    | EXPRESSION OP_LS EXPRESSION		{ $$ = new_binary_expression(LS, $1, $3); }
    | EXPRESSION OP_RS EXPRESSION		{ $$ = new_binary_expression(RS, $1, $3); }
		| EXPRESSION OP_AND EXPRESSION		{ $$ = new_binary_expression(LOGICAL_AND, $1, $3); }
		| EXPRESSION OP_OR EXPRESSION		{ $$ = new_binary_expression(LOGICAL_OR, $1, $3); }
		| EXPRESSION OP_EQ EXPRESSION		{ $$ = new_binary_expression(EQ, $1, $3); }
		| EXPRESSION OP_GE EXPRESSION		{ $$ = new_binary_expression(GE, $1, $3); }
		| EXPRESSION OP_LE EXPRESSION		{ $$ = new_binary_expression(LE, $1, $3); }
		| EXPRESSION OP_NE EXPRESSION		{ $$ = new_binary_expression(NE, $1, $3); }
    ;

%%
void yyerror(char *s)
{
  fprintf(stderr, "line%d column%d %s\n", row, col, s);
  //printf("Error: %s\n", emseg);
}


int main(int argc, char *argv[])
{
	global_table = gen_table();
	temp_table = global_table;
	parent_table = NULL;
  yyin = fopen(argv[1], "r");
  yyparse();
  fclose(yyin);
  return 0;
}
