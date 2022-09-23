#include<stdio.h>

void finder(int num, int *arr) 
{
	for (int i = 0; i < num - 1; i++)
	{
		
		for (int j = 1; j < num - 1; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = 0;
				temp = arr[j - 1];
				arr[j - 1] = arr[i];
				arr[i] = temp;
				//서로 바꿈. 함수화 가능성 있음.
				
			}
			
		}
		
	}
	

	//결과:winapi

	

	//정수화 후 함수로 바꾸기.
	for (int i = 0; i < num; i++)
	{
		printf("정렬 후 숫자열 : %d\n", arr[i]);
	}

}


void main() {

	int arr[] = { 143, 134, 137, 132, 140, 134 };

	
	int num = sizeof(arr) / sizeof(int);

	for (int i = 0; i < num; i++)
	{
		printf("정렬 전 숫자열 : %d\n", arr[i]);
	}
	
	printf("\n");


	finder(num, arr);

}