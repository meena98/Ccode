#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct stack
{
	char data[50];
	int top;
}stack;
typedef struct stack1
{
	int data[50];
	int top;
}stack1;

void init1(stack *s1)
{
	s1->top = -1;
}

int empty1(stack *s1)
{
	if (s1->top == -1)
		return(1);

	return(0);
}

int full1(stack *s1)
{
	if (s1->top == 50 - 1)
		return(1);

	return(0);
}

void push1(stack *s1, int x)
{
	s1->top = s1->top + 1;
	s1->data[s1->top] = x;
}

int pop1(stack *s1)
{
	int x;
	x = s1->data[s1->top];
	s1->top = s1->top - 1;

	return(x);
}

void init(stack *s)
{
	s->top = -1;
}

int precedence(char x)
{
	if (x == '**')
		return(0);
	if (x == '+' || x == '-')
		return(1);
	if (x == '*' || x == '/' || x == '%')
		return(2);

	return(3);
}

char pop(stack *s)
{
	char temp=0;
	temp = s->data[s->top];
	s->top = s->top - 1;
	return(temp);
}

int empty(stack *s)
{
	if (s->top == -1)
		return(1);

	return(0);
}

int top(stack *p)
{
	return (p->data[p->top]);
}

void push(stack *s, char num)
{
	s->top = s->top + 1;
	s->data[s->top] = num+'\0';
}

int calculate(char token, int op1, int op2)
{
	if (token == '+')
		return(op1 + op2);
	if (token == '-')
		return(op1 - op2);
	if (token == '*')
		return(op1*op2);
	if (token == '/')
		return(op1 / op2);
	if (token == '%')
		return(op1%op2);
}

int evaluate(char postfix[])
{
	stack s1;
	char token;
	int op1, op2, val;
	init1(&s1);
	for (int temp = 0; postfix[temp] != '\0'; temp++)
	{
		token = postfix[temp];
		if (isdigit(token))
			push1(&s1, token - 48);        //x-48 for removing the effect of ASCII
		else
		{
			op2 = pop1(&s1);
			op1 = pop1(&s1);
			val = calculate(token, op1, op2);
			push1(&s1, val);
		}
	}
	val = pop1(&s1);
	return val;
}

int convert(char line[])
{
	char postfix[50];
	stack s;
	char store, token;
	int i, j;    //i-index of infix,j-index of postfix
	init(&s);
	int pos = 0;
	for (int temp = 0;line[temp] != '\0'; temp++)
	{
		if (line[temp]== '\n')
		{
			break;
		}
		token = line[temp];
		if (isalnum(token))
			postfix[pos++] = token;
		else
		{
			while (precedence(token) <= precedence(top(&s)) && !empty(&s))
			{
				token = pop(&s);
				postfix[pos++] = token;
			}
			push(&s, token);
		}
	}
	while (!empty(&s))
	{
		token = pop(&s);
		postfix[pos++] = token;
	}
	postfix[pos] = '\0';
	int result=evaluate(postfix);
	return result;
}
void main()
{
	FILE *file;
	file = fopen("C:\\Users\\lenovo\\Documents\\Visual Studio 2013\\Projects\\pre-summer\\exp1.txt", "r");
	printf("hey");
	char line[100];
	while (fgets(line, 1024, file))
	{
		int res = convert(line);
	}
}
