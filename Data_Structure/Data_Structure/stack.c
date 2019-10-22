#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
StackType* InitStack()
{
	StackType* s = (StackType*)malloc(sizeof(StackType));
	s->top = -1;
	return s;
}

void DestroyStack(StackType* s)
{
	free(s);
}

int StackEmpty(StackType* s)
{
	return (s->top == -1);
}

int Push(StackType* s, ElemType e)
{
	if (s->top == MAX_SIZE - 1) return FAILED;
	s->data[++s->top] = e;
	return SUCCESS;
}

int Pop(StackType* s, ElemType* e)
{
	if (s->top == -1) return FAILED;
	*e = s->data[s->top--];
	return SUCCESS;

}

int GetTop(StackType* s, ElemType* e)
{
	if (s->top == -1) return FAILED;
	*e = s->data[s->top];
	return SUCCESS;
}

int JudgeSym(ElemType * str)
{
	StackType* s = InitStack();
	ElemType a ;
	ElemType* e=&a;
	for (int i = 0; str[i] != 0; i++)
		Push(s, str[i]);
	for (int i = 0; str[i] != 0; i++)
	{
		Pop(s, e);
		if (str[i] != (*e))
		{
			DestroyStack(s);
			return FAILED;
		}
	}
	DestroyStack(s);
	return SUCCESS;

}

void Trans(ElemType* exp, ElemType postExp[])
{
	SqStack* pExp = InitStack();
 	char e = '0';
	int i = 0;
	while (*exp != '\0')
	{
		switch (*exp)
		{
		case '(':
			Push(pExp, *exp);
			exp++;
			break;
		case ')':
			Pop(pExp, &e);
			while (e != '(')
			{
				postExp[i++] = e;
				Pop(pExp,& e);				
			}
			exp++;
			break;
		case '+':
		case '-' :
			while (!StackEmpty(pExp))
			{
				GetTop(pExp, &e);
				if (e != '(')
				{
					Pop(pExp, &postExp[i]);
					i++;
				}					
				else
					break;
			} 
			Push(pExp, *exp);
			exp++;
			break;
		case '*':
		case '/':
			while (!StackEmpty(pExp))
			{
				GetTop(pExp, &e); 
				if (e == '*' || e == '/')
				{
					Pop(pExp, &postExp[i]);
					i++;
				}
				else
					break;				
			}
			Push(pExp, *exp);
			exp++;
			break;
		default:
			while ((*exp >= '0') && (*exp <= '9'))
			{
				postExp[i++] = *exp;
				exp++;
			}
			postExp[i++] = '#';
			break;
		}
	}
	while (!StackEmpty(pExp))
	{
		Pop(pExp, &postExp[i]);
		i++;
	}
	postExp[i++] = '\0';
	DestroyStack(pExp);
}

void CompValue(char * postExp)
{
	double a, b, c, d;
	//这里使用的栈要将ElemType设置成double型，
	//因为要进行数值计算
	SqStack* Opnd = InitStack();
	;
	//
	while (*postExp != '\0')
	{
		switch ( *postExp)
		{
		case '+':
			Pop(Opnd, &a);
			Pop(Opnd, &b);
			c = b + a;
			Push(Opnd, c);
			break;
		case '-':
			Pop(Opnd, &a);
			Pop(Opnd, &b);
			c = b - a;
			Push(Opnd, c);
			break;
		case '*':
			Pop(Opnd, &a);
			Pop(Opnd, &b);
			c = b * a;
			Push(Opnd, c);
			break;
		case '/':
			Pop(Opnd, &a);
			Pop(Opnd, &b);
			if (a != '/')
			{
				c = b / a;
				Push(Opnd, c);
				break;
			}
			else
			{
				printf("error !");
				exit(0);
			}
			break;
		default:
			d = 0;
			while (*postExp >= '0' && *postExp <= '9')
			{
				d = 10 * d + (*postExp - '0');
				postExp++;
			}
			Push(Opnd, d);		
			break;
		}
		postExp++;
	}
	GetTop(Opnd, &a);
	return a;
	return a;
}
