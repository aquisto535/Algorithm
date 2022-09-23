#include<stdio.h>
#include<stdlib.h>


int* stack;
int size;
int top;

bool Push(int data) 
{	
	if (top < size - 1)
	{
		top++;
		stack[top] = data;
		return true;

	}
	else
	{
		return false;
	}
}

int pop()
{
	if (top >= 0)
	{
		return stack[top-- ];
	}
	else
	{
		return -1;
	}


}

void main() 
{	
	size = 265;
	stack = (int*)malloc(size*sizeof(int));
	top = -1;


	Push(7);
	Push(0);
	Push(2);
	Push(6);


	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	//스택의 작동방식을 보여줌. first in last out;
	
	free(stack);

}