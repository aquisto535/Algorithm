#include<stdio.h>
#include<string.h>


#define BK 10
#define SL 3

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

	printf("Ű�� 5�� �Է��ϼ��� : ");

	for ( int i = 0; i < 5; i++)
	{
		printf("%d��° ���� �Է��ϼ��� : ",  i + 1);
		scanf_s("%d", &data);

		insertValue(data);
	

		
	
	}

	printf("�˻��� Ű�� �Է��ϼ��� : \n");
	scanf_s("%d", &data);

	bool search =  findValue(data);

	if (search) {

		printf("�˻��Ǿ����ϴ�");
	}
	else
	{
		printf("�˻����� �ʾҽ��ϴ�");
	}


}
// �ؽ��� ������: �浹 ������ ��Ÿ�� �� ����. ���� ����, ���� Ž��, ���ؽ� ���� �ذ����� �ִ�.