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
				//���� �ٲ�. �Լ�ȭ ���ɼ� ����.
				
			}
			
		}
		
	}
	

	//���:winapi

	

	//����ȭ �� �Լ��� �ٲٱ�.
	for (int i = 0; i < num; i++)
	{
		printf("���� �� ���ڿ� : %d\n", arr[i]);
	}

}


void main() {

	int arr[] = { 143, 134, 137, 132, 140, 134 };

	
	int num = sizeof(arr) / sizeof(int);

	for (int i = 0; i < num; i++)
	{
		printf("���� �� ���ڿ� : %d\n", arr[i]);
	}
	
	printf("\n");


	finder(num, arr);

}