#ifndef CT_H
#define CT_H

// Initialized
#define H_INIT	0
// Symbol/number
#define H_NUM	1
#define H_SYM	2
// Unary operations (functions)
#define H_ABS	11
#define H_SIN	12
#define H_COS	13
#define H_TAN	14
#define H_COT	15
#define H_SEC	16
#define H_CSC	17
#define H_SQRT	18
#define H_CEIL	19
#define H_FLOOR	20
// Binary operations (functions)
#define H_LOG	1001
#define H_ADD	1002
#define H_SUB	1003
#define H_MUL	1004
#define H_DIV	1005
#define H_POW	1006

typedef struct H__NODE__H
{
	int type;
	char* name;
	int complete;
	int val;
	H__NODE__H* chd1;
	H__NODE__H* chd2;
	H__NODE__H* prnt;
} NODE;

NODE* new_node();
void reset_tree(NODE* root);
void del_tree(NODE* root);

double calculate(NODE* root);
void set_op(NODE* root, int op);
void set_sym(NODE* root, char* name);
void set_num(NODE* root, double num);

#endif CT_H
