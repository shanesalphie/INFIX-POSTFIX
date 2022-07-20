#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define n 10
int top;

char infix[n],postfix[n];

void push (char x)
{
	top++;
	postfix[top]=x;
}

char pop()
{
	if(top== -1)
	{
		return 1;
	}
	else
	{
		return postfix[top--];
	}
}

int priority(char x)
{
	if (x == '(')
	{
	return 0;	
	}
	if(x== '+' ||  x== '-')
		{
	return 1;
	}
	if (x== '*' || x== '/')
	{
	return 2;
	}
	return 0;
}


int main()
{
	char *e,x;
	printf("Enter the expression in infix form:");
	scanf("%s",infix);
	printf("\n");
	e=infix;
	while (*e!= '\0')
	{
		if (isalnum(*e))
		{
			printf("%c",*e);
		}
		else if (*e == '(')
		{
			push(*e);
		}
		else if (*e == ')')
		{
			while ((x== pop()) != '(')
			{
						printf("%c",x);
			}
		}
		else
		{
			while (priority(postfix[top]) >= priority (*e))
			{
				printf("%c",pop());
			}
			push(*e);
		}
		e++;
		}
		while(top != -1)
		{
			printf("%c",pop());
			}
		printf("\n");
		return 0;
}
