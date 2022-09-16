#include<stdio.h>

int BinarySearch(int *pAr, int size, int pkey)// 배열을 받을 때에는 포인터로 받는다!!
	{

	int upp = size - 1;
	int low = 0;
	int mid = 0;

	for (;;)
	{
		mid = (upp + low) / 2;

		if (pAr[mid] == pkey)
		{
			printf("찾았습니다.");
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

		printf("못 찼았다.");
	}
	else
	{
		printf("찾는 값은 %d번째에 있다. \n", ret + 1);
	}
}