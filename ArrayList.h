#ifndef __ARRAY_LIST_H__ // ��� ������ �ߺ������ ���� ����.
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList�� ���� ****/
#define LIST_LEN	100
typedef int LData;


typedef struct __ArrayList
{
	LData arr[LIST_LEN]; // ����Ʈ�� ������� �迭
	int numOfData;       // ����� �������� ��
	int curPosition;	 // �迭�� ������ ���� ��ġ�� ���. ��� �� ���.
} ArrayList;


/*** ArrayList�� ���õ� ����� ****/
typedef ArrayList List;

void ListInit(List* plist);

void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata); // ������ ������ ���� ���� ���Թޱ� ���� ���.

int LNext(List* plist, LData* pdata);

LData LRemove(List* plist)
{
	int pos = plist->curPosition;
	int val = plist->arr[pos];

	for (int i = 0; i < plist->numOfData - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}
	
	(plist->curPosition)--;
	(plist->numOfData)--;

}

int LCount(List* plist);


#endif