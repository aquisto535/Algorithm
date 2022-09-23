#include<stdio.h>
#include<string.h>

void swap(char *pMin, char *pStr ) {

	char temp;
	temp = *pMin;
	*pMin = *pStr;
	*pStr = temp;
}

void SelectionSort(char *str, int num) {

	int minidx = 0; //�ּҰ��� ������ �ִ� ����� �ε���
	int i, j;

	for ( i = 0; i < num - 1; i++)
	{
		for ( j = i + 1, minidx = i; j < num; j++)
		{
			if (str[minidx] > str[j])
			{
				minidx = j;

			}
		}

		if (minidx != i)
		{
			swap(&str[minidx], &str[i]);

		}
	}
}

void main() 
{
	char str[] = "winapi";

	printf("���� ���� ���ڿ� : %s\n", str);

	int num = strlen(str);
	

	//�������� �˰���
	
	SelectionSort(str, num);


	printf("���� ���� ���ڿ� : %s\n", str);
}