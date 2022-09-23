#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{

	int value;
	Node* next;//노드를 가리키기 때문에 노드 타입을 갖는다.

};


Node* head;

Node* InsertNode(Node* Target, Node* aNode)
{
	//Target은 현재 노드
	//aNode는 추가할 노드
	
	Node* New = (Node*)malloc(sizeof(Node));
	*New = *aNode;

	New->next = Target->next;
	Target->next = New;

	return New;

}

void main() 
{

	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	Node* Now; //구조체를 가리키는 포인터
	Node Temp; // 생성된 구조체

	Now = head;

	for (int i = 0; i < 6; i++)
	{
		Temp.value =  i+ 1;
		Now = InsertNode(Now, &Temp);
		printf("%d\n", Now->value);
	}

	for (Now = head->next; Now; Now = Now->next)
	{

		printf("%d\t", Now->value);

	}
	
	
	
}