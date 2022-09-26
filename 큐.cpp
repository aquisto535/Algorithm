#include<stdio.h>
#include<stdlib.h>

int* Queue;
int head, tail;
int QSize;

void initQueue(int size) {

	QSize = size;
	Queue = (int*)malloc(QSize * sizeof(int));
	head = tail = 0;
}


int insert(int data)
{	
	if ((tail + 1) == head) 
	{
		return 0;
	}

	Queue[tail] = data;
	tail = tail + 1;

	return 1;

}

int Delete()
{

	int data = Queue[head];
	head = head + 1;
	return data;
}

void freeQueue()
{
	free(Queue);

}


void main() 
{
	initQueue(10);

	insert(1);
	insert(2);
	insert(3);
	insert(4);

	printf("%d\n", Delete());
	printf("%d\n", Delete());
	printf("%d\n", Delete());


	freeQueue();


}