#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN) 
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data; // numOfData를 배열의 위치를 나타내는 방식으로 사용. 
										 //ex) numOfData = 0이면 0번째 위치에 아무것도 없다는 뜻으로 다음 위치가 1임을 암시함. 
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++; // 값을 하나씩 증가.
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos]; // 반환을 위해 삭제할 값 미리 백업

	for(i=rpos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1]; // 삭제한 자리를 매꾸기 위해 한칸씩 뒤로 이동

	(plist->numOfData)--; // 데이터 숫자 1 감소
	(plist->curPosition)--; // 삭제 데이터의 바로 앞의 데이터로 커서 변경. 삭제 데이터의 뒤 데이터는 아직 커서를 이동하지 않은 상태가 되어야 함.
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}