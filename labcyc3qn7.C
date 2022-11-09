#include <stdio.h>
#include <stdlib.h>
#define bool int


int stack[50];
int top=-1;

void push(char val);

char pop();


bool isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

bool areBracketsBalanced(char exp[])
{
	int i = 0;

	while (exp[i]) {

		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(exp[i]);

		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

			if (top == -1)
				return 0;

			else if (!isMatchingPair(pop(), exp[i]))
				return 0;
		}
		i++;
	}

	if (top == -1)
		return 1; 
	else
		return 0; 
}

int main()
{
	int flag =1;
	char* exp;

	while (flag)
	{
		printf("\nEnter the expression to check:\n");
		scanf("%s" , exp);

		if (areBracketsBalanced(exp))
			printf("The given expression is balanced \n");
		else
			printf("The given expression is not balanced \n");

		printf("\nDo you want to continue?(Yes(1) or No(0))\n");
		scanf("%d" , &flag);
	}
	return 0;
}

void push(char val)
{
    top = top + 1;
    stack[top] = val;
}

char pop(){
    top--;
	return stack[top+1];
}
