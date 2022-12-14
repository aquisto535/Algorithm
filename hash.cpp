#include<stdio.h>
#include<string.h>

//
#define BK 10
#define SL 2

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
 
		if (hashtable[bucket][i] != 0) {

			hashtable[bucket + 1][i] = key;
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

		if (hashtable[bucket + 1][i] == key) {


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
//
	bool search =  findValue(data);

	if (search) {

		printf("검색되었습니다");
	}
	else
	{
		printf("검색되지 않았습니다");
	}


}
// 해싱의 문제점: 충돌 문제가 나타날 수 있음. 다중 슬롯, 선형 탐색, 재해시 등의 해결방법이 있다.\



//<< 동적 슬롯: 슬롯의 개수를 가변적으로 관리하는 방법>>
//#define BK 10
//#define SL	1
//
//int hashtable[BK][SL];
//
//int Hash(int key) {
//
//	int rest = key % 10;
//
//	return rest;
//}// 위치값 출력
//
//
//void insertValue(int key) {
//	int bucket = Hash(key);
//
//	while (hashtable[bucket][0] != 0)
//	{
//		bucket = bucket + 1;
//	}
//	hashtable[bucket][0] = key;
//}
//
//bool findValue(int key)
//{
//	int bucket = Hash(key);
//	while (hashtable[bucket][0] != 0)
//	{
//		if (hashtable[bucket][0] == key)
//			return true;
//		bucket = bucket + 1;
//	}
//	return false;
//}
//
//void main() {
//
//	int data = 0;
//
//	memset(hashtable, 0, sizeof(hashtable));//메모리를 초기화해주는 함수.
//
//	printf("키를 5개 입력하세요 : ");
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d번째 값을 입력하세요 : ", i + 1);
//		scanf_s("%d", &data);
//
//		insertValue(data);
//
//	}
//
//	printf("검색할 키를 입력하세요 : \n");
//	scanf_s("%d", &data);
//	
//	bool search = findValue(data);
//
//	if (search) {
//
//		printf("검색되었습니다");
//	}
//	else
//	{
//		printf("검색되지 않았습니다");
//	}
//	
//
//}
