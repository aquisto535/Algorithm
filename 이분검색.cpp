#include<stdio.h>

int BinarySearch(int *pAr, int size, int pkey)// �迭�� ���� ������ �����ͷ� �޴´�!!
	{

	int upp = size - 1;
	int low = 0;
	int mid = 0;

	for (;;)
	{
		mid = (upp + low) / 2;

		if (pAr[mid] == pkey)
		{
			printf("ã�ҽ��ϴ�.");
			return mid;
		}

		if (pAr[mid] > pkey) {

			upp = mid - 1;
		}
		else
		{
			low = mid + 1;
		}


		if (upp < low) {

			
			return -1;
		}
	}


	
}




void main() {

	int ar[] = { 2,6,13,19,21,21,23,29,35,48,62,89,90,95,99,102,109,208,629 };
	int num = 0;
	int key = 29;
	
	num = sizeof(ar)/sizeof(int);

	int ret = BinarySearch(ar, num, key);


	if (ret == -1) 
	{

		printf("�� á�Ҵ�.");
	}
	else
	{
		printf("ã�� ���� %d��°�� �ִ�. \n", ret + 1);
	}
}