#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ct.h"

NODE* new_node()
{
	NODE* tmp = (NODE*)(malloc(sizeof(NODE)));
	tmp->type = H_INIT;
	tmp->name = NULL;
	tmp->complete = 0;
	tmp->val = 0;
	tmp->prnt = NULL;
	tmp->chd1 = NULL;
	tmp->chd2 = NULL;
	return tmp;
}

void reset_tree(NODE* root)
{
	switch(root->type)
	{
	case H_NUM:
		root->complete = 1;
		return;
	case H_SYM:
		root->complete = 0;
		return;
	case H_ABS:
	case H_SIN:
	case H_COS:
	case H_TAN:
	case H_COT:
	case H_SEC:
	case H_CSC:
	case H_SQRT:
	case H_CEIL:
	case H_FLOOR:
		reset_tree(root->chd1);
		root->complete = 0;
		break;
	case H_LOG:
	case H_ADD:
	case H_SUB:
	case H_MUL:
	case H_DIV:
	case H_POW:
		reset_tree(root->chd1);
		reset_tree(root->chd2);
		root->complete = 0;
		break;
	default:
		break;
	}
}

void del_tree(NODE* root)
{
	if (root->chd1 != NULL)
	{
		del_node(root->chd1);
		root->chd1 = NULL;
	}
	if (root->chd2 != NULL)
	{
		del_node(root->chd2);
		root->chd2 = NULL;
	}
	if (root->name != NULL)
	{
		free(root->name);
		root->name = NULL;
	}
	free(root);
}

double calculate(NODE* root)
{
	if (root->complete > 0)
		return root->val;
	root->complete = 1;
	switch(root->type)
	{
	case H_ABS:
		root->val = fabs(calculate(root->chd1));
		return root->val;
	case H_SIN:
		root->val = sin(calculate(root->chd1));
		return root->val;
	case H_COS:
		root->val = cos(calculate(root->chd1));
		return root->val;
	case H_TAN:
		root->val = sin(calculate(root->chd1)) / cos(calculate(root->chd1));
		return root->val;
	case H_COT:
		root->val = cos(calculate(root->chd1)) / sin(calculate(root->chd1));
		return root->val;
	case H_SEC:
		root->val = 1. / cos(calculate(root->chd1));
		return root->val;
	case H_CSC:
		root->val = 1. / sin(calculate(root->chd1));
		return root->val;
	case H_SQRT:
		root->val = sqrt(calculate(root->chd1));
		return root->val;
	case H_CEIL:
		root->val = ceil(calculate(root->chd1));
		return root->val;
	case H_FLOOR:
		root->val = floor(calculate(root->chd1));
		return root->val;
	case H_LOG:
		root->val = log(calculate(root->chd1)) / log(calculate(root->chd2));
		return root->val;
	case H_ADD:
		root->val = calculate(root->chd1) + calculate(root->chd2);
		return root->val;
	case H_SUB:
		root->val = calculate(root->chd1) - calculate(root->chd2);
		return root->val;
	case H_MUL:
		root->val = calculate(root->chd1) * calculate(root->chd2);
		return root->val;
	case H_DIV:
		root->val = calculate(root->chd1) / calculate(root->chd2);
		return root->val;
	case H_POW:
		root->val = pow(calculate(root->chd1), calculate(root->chd2));
		return root->val;
	default:
		printf("Warning! CT calculation error detected!\n");
		return root->val;
	}
	return 0;
}

void set_op(NODE* root, int op)
{
	root->type = op;
	root->name = NULL;
	tmp->complete = 0;
	root->val = 0;
	root->prnt = NULL;
	root->chd1 = NULL;
	root->chd2 = NULL;
}

void set_sym(NODE* root, char* name)
{
	int tmpl = strlen(name);
	root->type = op;
	root->name = (char*)(malloc(sizeof(char)*(tmpl+1)));
	strcpy(root->name, name);
	tmp->complete = 0;
	root->val = 0;
	root->prnt = NULL;
	root->chd1 = NULL;
	root->chd2 = NULL;	
}

void set_num(NODE* root, double num)
{
	root->type = op;
	root->name = NULL;
	tmp->complete = 1;
	root->val = num;
	root->prnt = NULL;
	root->chd1 = NULL;
	root->chd2 = NULL;
}
