#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ct.h"

void reset_stack_state() { stack_state = CT_NTH; }
int get_stack_state() { return stack_state; }

struct CT_NODE* new_node()
{
	struct CT_NODE* tmp_node = (struct CT_NODE*)(malloc(sizeof(struct CT_NODE)));
	tmp_node->type = CT_INIT;
	tmp_node->name = NULL;
	tmp_node->val = 0;
	tmp_node->nxt = NULL;
	tmp_node->prv = NULL;
	return tmp_node;
}

void del_node(struct CT_NODE* node)
{
	if (node->name != NULL)
		free(node->name);
	free(node);
}

void stack_build()
{
	stack_bottom = new_node();
	stack_top = stack_bottom;
}

void stack_clean()
{
	stack_top = stack_bottom;
	struct CT_NODE* tmp_node = stack_top->nxt;
	struct CT_NODE* nxt_node = stack_top->nxt;
	stack_top->nxt = NULL;
	while(tmp_node != NULL)
	{
		nxt_node = tmp_node->nxt;
		del_node(tmp_node);
		tmp_node = nxt_node;
	}
}

void stack_destroy()
{
	stack_clean();
	del_node(stack_bottom);
	stack_bottom = NULL;
	stack_top = NULL;
}

struct CT_NODE* get_stack_top()
{
	if (is_stack_empty() > 0)
		return stack_top;
	return NULL;
}

struct CT_NODE* get_stack_bottom()
{
	return stack_bottom;
}

int is_stack_empty()
{
	if (stack_top == stack_bottom)
		return 0;
	return 1;
}

void stack_push_op(int op_type)
{
	struct CT_NODE* tmp_node = new_node();
	tmp_node->type = op_type;
	tmp_node->prv = stack_top;
	stack_top->nxt = tmp_node;
	stack_top = tmp_node;
}

void stack_push_num(double num_val)
{
	struct CT_NODE* tmp_node = new_node();
	tmp_node->type = CT_NUM;
	tmp_node->val = num_val;
	tmp_node->prv = stack_top;
	stack_top->nxt = tmp_node;
	stack_top = tmp_node;
}

void stack_push_sym(char* sym_name)
{
	char* cpy_sym_name = (char*)(malloc(sizeof(char)*(strlen(sym_name)+2)));
	struct CT_NODE* tmp_node = new_node();
	strcpy(cpy_sym_name, sym_name);
	tmp_node->type = CT_SYM;
	tmp_node->name = cpy_sym_name;
	tmp_node->prv = stack_top;
	stack_top->nxt = tmp_node;
	stack_top = tmp_node;
}

struct CT_NODE* stack_pop()
{
	struct CT_NODE* tmp_node = stack_top;
	stack_top = tmp_node->prv;
	return tmp_node;
}

int stack_assign(struct CT_NODE* node, char* name, double val, int state)
{
	if (node == NULL)
		return state;
	if (node->type == CT_SYM && strcmp(node->name, name) == 0)
	{
		node->val = val;
		state++;
	}
	state = stack_assign(node->nxt, name, val, state);
	return state;
}

double stack_calc(int first_flag)
{
	double ret = 0, op1 = 0, op2 = 0;
	if (stack_top == stack_bottom)
	{
		stack_state = CT_ERR;
		printf(">> <ERROR STATE>\n");
		return ret;
	}
	switch(stack_top->type)
	{
	case CT_NUM:
		ret = stack_top->val;
		printf(">> NUM = %lf\n", stack_top->val);
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		break;
	case CT_SYM:
		ret = stack_top->val;
		printf(">> SYM(%s) = %lf\n", stack_top->name, stack_top->val);
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		break;
	case CT_POS:
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		ret = stack_calc(0);
		printf(">> POS = %lf\n", ret);
		break;
	case CT_NEG:
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		ret = -stack_calc(0);
		printf(">> NEG = %lf\n", ret);
		break;
	case CT_ADD:
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		ret = stack_calc(0)+stack_calc(0);
		printf(">> ADD = %lf\n", ret);
		break;
	case CT_SUB:
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		op2 = stack_calc(0);
		op1 = stack_calc(0);
		ret = op1 - op2;
		printf(">> SUB = %lf\n", ret);
		break;
	case CT_MUL:
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		ret = stack_calc(0)*stack_calc(0);
		printf(">> MUL = %lf\n", ret);
		break;
	case CT_DIV:
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		op2 = stack_calc(0);
		op1 = stack_calc(0);
		ret = op1 / op2;
		printf(">> DIV = %lf\n", ret);
		break;
	case CT_POW:
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		op2 = stack_calc(0);
		op1 = stack_calc(0);
		ret = pow(op1, op2);
		printf(">> POW = %lf\n", ret);
		break;
	default:
		stack_top = stack_top->prv;
		del_node(stack_top->nxt);
		stack_top->nxt = NULL;
		stack_state = CT_ERR;
		printf(">> <ERROR STATE>\n");
		break;
	}
	if (first_flag > 0)
		printf(">> RES = %lf\n", ret);
	return ret;
}

void stack_print()
{
	struct CT_NODE* tmp_node = stack_bottom->nxt;
	printf(">> STACK| ");
	while(tmp_node != NULL)
	{
		switch(tmp_node->type)
		{
		case CT_NUM: printf("%lf ", tmp_node->val); break;
		case CT_SYM: printf("%s(%lf) ", tmp_node->name, tmp_node->val); break;
		case CT_ADD: printf("+ "); break;
		case CT_SUB: printf("- "); break;
		case CT_MUL: printf("* "); break;
		case CT_DIV: printf("/ "); break;
		case CT_POW: printf("^ "); break;
		case CT_POS: printf("<POS> "); break;
		case CT_NEG: printf("<NEG> "); break;
		default: printf("<ERR> "); break;
		}
		tmp_node = tmp_node->nxt;
	}
	printf("|TOP\n");
}
