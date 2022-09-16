#include<stdio.h>
#include<string.h>


#define BK 10
#define SL 3

int hashtable[BK][SL];

int Hash(int key) {

	int rest = key % 10;

	return rest;
}// 위치값 출력


void insertValue(int key) {
	int bucket = Hash(key);
	printf("bucket = %d\n", bucket);

	for (int i = 0; i < SL; i++)
	{
		if (hashtable[bucket][i] == 0)
		{
			hashtable[bucket][i] = key;//위치에 데이터 저장.
			break;
		}
	}
	
}

bool findValue(int key)
{
	int bucket = Hash(key);
	for ( int i = 0;  i < SL; i++)
	{
		if (hashtable[bucket][i] == key) {


			return true;
		}
		
	}
	return false;
}

void main() {

	int data = 0;

	memset(hashtable, 0, sizeof(hashtable));

	printf("키를 5개 입력하세요 : ");

	for ( int i = 0; i < 5; i++)
	{
		printf("%d번째 값을 입력하세요 : ",  i + 1);
		scanf_s("%d", &data);

		insertValue(data);
	

		
	
	}

	printf("검색할 키를 입력하세요 : \n");
	scanf_s("%d", &data);

	bool search =  findValue(data);

	if (search) {

		printf("검색되었습니다");
	}
	else
	{
		printf("검색되지 않았습니다");
	}


}
// 해싱의 문제점: 충돌 문제가 나타날 수 있음. 다중 슬롯, 선형 탐색, 재해시 등의 해결방법이 있다.