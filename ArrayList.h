#ifndef __ARRAY_LIST_H__ // 헤더 파일의 중복사용을 막기 위함.
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100
typedef int LData;


typedef struct __ArrayList
{
	LData arr[LIST_LEN]; // 리스트의 저장소인 배열
	int numOfData;       // 저장된 데이터의 수
	int curPosition;	 // 배열의 데이터 참조 위치를 기록. 출력 시 사용.
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List;

void ListInit(List* plist);

void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata); // 포인터 변수는 새로 값을 대입받기 위해 사용.

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