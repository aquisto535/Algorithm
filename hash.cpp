#include<stdio.h>
#include<string.h>

//
#define BK 10
#define SL 2

int hashtable[BK][SL];

int Hash(int key) {

	int rest = key % 10;

	return rest;
}// ��ġ�� ���


void insertValue(int key) {
	int bucket = Hash(key);
	printf("bucket = %d\n", bucket);

	for (int i = 0; i < SL; i++)
	{
		if (hashtable[bucket][i] == 0)
		{
			hashtable[bucket][i] = key;//��ġ�� ������ ����.
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

	printf("Ű�� 5�� �Է��ϼ��� : ");

	for ( int i = 0; i < 5; i++)
	{
		printf("%d��° ���� �Է��ϼ��� : ",  i + 1);
		scanf_s("%d", &data);

		insertValue(data);
	

		
	
	}

	printf("�˻��� Ű�� �Է��ϼ��� : \n");
	scanf_s("%d", &data);
//
	bool search =  findValue(data);

	if (search) {

		printf("�˻��Ǿ����ϴ�");
	}
	else
	{
		printf("�˻����� �ʾҽ��ϴ�");
	}


}
// �ؽ��� ������: �浹 ������ ��Ÿ�� �� ����. ���� ����, ���� Ž��, ���ؽ� ���� �ذ����� �ִ�.\



//<< ���� ����: ������ ������ ���������� �����ϴ� ���>>
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
//}// ��ġ�� ���
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
//	memset(hashtable, 0, sizeof(hashtable));//�޸𸮸� �ʱ�ȭ���ִ� �Լ�.
//
//	printf("Ű�� 5�� �Է��ϼ��� : ");
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d��° ���� �Է��ϼ��� : ", i + 1);
//		scanf_s("%d", &data);
//
//		insertValue(data);
//
//	}
//
//	printf("�˻��� Ű�� �Է��ϼ��� : \n");
//	scanf_s("%d", &data);
//	
//	bool search = findValue(data);
//
//	if (search) {
//
//		printf("�˻��Ǿ����ϴ�");
//	}
//	else
//	{
//		printf("�˻����� �ʾҽ��ϴ�");
//	}
//	
//
//}
