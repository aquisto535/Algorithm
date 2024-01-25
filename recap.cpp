#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;

}USERDATA;

USERDATA pHead = { 0, "_DummyHead_" };


void addNode(int age, const char* name, const char* phone)
{
	USERDATA* User = (USERDATA*)calloc(1, sizeof(USERDATA)); // �⺻������ �ּ� �� ������. *�����ڰ� ���� ������ ������ �ּҰ��� �޴´�!!!
	User->age = age;
	strcpy_s(User->name, name);
	strcpy_s(User->phone, phone);
	User->pNext = NULL;

	USERDATA* pTmp = &pHead;
	while (pTmp->pNext != NULL)
		pTmp = pTmp->pNext;

	pTmp->pNext = User;

	


	
}

USERDATA* FindNode(const char* name)
{
	USERDATA* pTmp = &pHead;
	while (pTmp != NULL)
	{
		if (strcmp(name, pTmp->name) == 0)
		{
			printf("���� : %d, �̸� : %s, ����ó : %s, �޸� �ּ� %p\n", pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
			return pTmp;
		}
			
		
		pTmp = pTmp->pNext;
	}

	return NULL;
}

USERDATA* SearchToName(USERDATA* pPrev, const char* name)
{
	USERDATA* pCurrent = pHead.pNext;
	USERDATA* pPrev = NULL;

	while (pCurrent != NULL)
	{
		if (strcmp(name, pCurrent->name) == 0)
		{
			//printf("���� : %d, �̸� : %s, ����ó : %s, �޸� �ּ� %p\n", pCurrent->age, pCurrent->name, pCurrent->phone, pCurrent->pNext);
			return pCurrent;
			
		}

		pPrev = pCurrent; //���� ��� �� ��� 
		pCurrent = pCurrent->pNext;
	}

	printf("\"%s\" Not Found", name);
	return NULL;
}

void RemoveNode(USERDATA* pPrev)
{
	USERDATA* pRemove = NULL;
	if (pPrev == NULL) //����尡 ����Ű�� ��带 ����� ���
	{
		if (pHead == NULL) // ��尡 �ƿ� ���� ���
			return; 
		else //ù��° ��� ����
		{
			pRemove = pHead;
			pHead = pRemove->pNext;
			printf("RemoveNode(): %s\n", pRemove->name);
			free(pRemove);
		}

		return;

	}
	
	pRemove = pPrev->pNext; // ���� ���
	pPrev->pNext = pRemove->pNext; //���� ��尡 ����Ű�� ���� ���
	free(pRemove);



}



void printList()
{
	USERDATA* pTmp = pHead; //c++ begin, end ����
	while (pTmp != NULL)
	{
		printf("���� : %d, �̸� : %s, ����ó : %s, �޸� �ּ� %p\n", pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);

		pTmp = pTmp->pNext;
	}
	putchar('\n');

}



void releaseNode()
{
	USERDATA* pTmp = pHead;
	USERDATA* pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;
		free(pDelete);

		//printf("���� : %d, �̸� : %s, ����ó : %s, �޸� �ּ� %p\n", pTmp->age, pTmp->phone, pTmp->phone, pTmp->pNext);

	}

	pHead = NULL;

}

void TestStep01()
{
	puts("TestStep01()---------------------");
	addNode(11, "abc123", "010-3333-3333");
	addNode(11, "bbc123", "010-4444-4444");
	addNode(21, "tmjung", "010-2222-2222");
	printList();

	USERDATA* pPrev = NULL;
	if (SearchToName(&pPrev, "abc123") != NULL) // ������ ������ ���� ���ϰ� �Ϸ��� ���������� ������ ���ؾ߸� �Ѵ�!!
		RemoveNode(pPrev);

	releaseNode();
	putchar('\n');
}

void TestStep02()
{
	puts("TestStep02()---------------------");
	addNode(11, "abc123", "010-3333-3333");
	addNode(11, "bbc123", "010-4444-4444");
	addNode(21, "tmjung", "010-2222-2222");
	printList();

	USERDATA* pPrev = NULL;
	if (SearchToName(&pPrev, "bbc123") != NULL) // ������ ������ ���� ���ϰ� �Ϸ��� ���������� ������ ���ؾ߸� �Ѵ�!!
		RemoveNode(pPrev);

	releaseNode();
	putchar('\n');
}


void TestStep03()
{
	puts("TestStep03()---------------------");
	addNode(11, "abc123", "010-3333-3333");
	addNode(11, "bbc123", "010-4444-4444");
	addNode(21, "tmjung", "010-2222-2222");
	printList();

	USERDATA* pPrev = NULL;
	if (SearchToName(&pPrev, "tmjung") != NULL) // ������ ������ ���� ���ϰ� �Ϸ��� ���������� ������ ���ؾ߸� �Ѵ�!!
		RemoveNode(pPrev);

	releaseNode();
	putchar('\n');
}




int main()
{
	

	



	addNode(21, "tmjung", "010-2222-2222");

	printList();

	addNode(11, "abc123", "010-3333-3333");
	addNode(11, "bbc123", "010-4444-4444");

	if (SearchToName(&pPrev, "tmjung") != NULL) // ������ ������ ���� ���ϰ� �Ϸ��� ���������� ������ ���ؾ߸� �Ѵ�!!
		RemoveNode(pPrev);
	addNode(11, "ccc123", "010-5555-5555");

	printList();

	//FindNode("wjdxoals");
	//FindNode("tmjung");
	//FindNode("abc123");
	//FindNode("bbc123");
	//FindNode("ccc123");
	//FindNode("KIM"); //���� �����͵� �׽�Ʈ �ʿ�

	releaseNode();

	return 0;
}



