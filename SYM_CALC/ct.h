#ifndef CT_H
#define CT_H

#include <stdio.h>
#include <stdlib.h>

// Initialized
#define CT_INIT	0
// Symbol/number
#define CT_NUM	1
#define CT_SYM	2
// Unary arithmetic operations
#define CT_POS	101
#define CT_NEG	102
// Binary arithmetic operations
#define CT_ADD	1001
#define CT_SUB	1002
#define CT_MUL	1003
#define CT_DIV	1004
#define CT_POW	1005

// State
#define CT_ERR	-1	// Something wrong
#define CT_NTH	0	// Nothing wrong

int stack_state = CT_NTH;

void reset_stack_state();
int get_stack_state();

struct CT_NODE
{
	int type;
	char* name;
	double val;
	struct CT_NODE* nxt;
	struct CT_NODE* prv;
};

struct CT_NODE* stack_bottom = NULL;
struct CT_NODE* stack_top = NULL;

struct CT_NODE* new_node();
void del_node(struct CT_NODE*);

void stack_build();
void stack_clean();
void stack_destroy();
struct CT_NODE* get_stack_top();
struct CT_NODE* get_stack_bottom();
int is_stack_empty();

void stack_push_op(int);
void stack_push_num(double);
void stack_push_sym(char*);

struct CT_NODE* stack_pop();

void stack_print();
int stack_assign(struct CT_NODE*, char*, double, int);
double stack_calc(int);

#endif
