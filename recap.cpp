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

USERDATA* g_pHeadNode = NULL;

void AddNewNode(int age, const char *	pszName, const char * pszPhone) //변화를 주지 않는 변수라면 const를 써주는 것이 좋다!
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName );
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL; 

	if (g_pHeadNode == NULL)
	{
		g_pHeadNode = pNewNode;	 
	}
	else
	{
		pNewNode->pNext = g_pHeadNode; //null 값 대입
		g_pHeadNode = pNewNode;
	
	}


}

void  ReleaseList()
{
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete;

	while (pTmp != NULL)
	{
		//pTmp = pTmp->pNext; //
		//USERDATA*  pSave = pTmp->pNext;
		//free(pTmp); 
		//pTmp = pSave;

		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("[%p], %d,%s,%s, [%p]\n", pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext); // 테스트 코드

		free(pDelete);

	}

	g_pHeadNode = NULL;

}

void PrintList() //기능 하나당 하나의 함수를 만들어 놓으면 전체 흐름을 파악해두기 좋다!
{
	//Print list
	USERDATA* pTmp = g_pHeadNode;

	while (pTmp != NULL)
	{
		printf("[%p], %d,%s,%s, [%p]\n", pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}

}

int main() 
{
	//Input
	AddNewNode(10, "tmjung", "010-2826-0961");
	AddNewNode(10, "test1", "010-1111-1111");
	AddNewNode(10, "test2", "010-2222-2222");

	PrintList();

	ReleaseList();
	return 0;
}
