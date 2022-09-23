#include<stdio.h>
#include<string.h>

void swap(char *pMin, char *pStr ) {

	char temp;
	temp = *pMin;
	*pMin = *pStr;
	*pStr = temp;
}

void SelectionSort(char *str, int num) {

	int minidx = 0; //최소값을 가지고 있는 요소의 인덱스
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

	printf("정렬 전의 문자열 : %s\n", str);

	int num = strlen(str);
	

	//선택정렬 알고리즘
	
	SelectionSort(str, num);


	printf("정렬 후의 문자열 : %s\n", str);
}