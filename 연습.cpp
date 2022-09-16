#include<stdio.h>

int finder(int lower, int middle, int upper, int*arr, int key) {

	

	

	for ( int i = 0; i < upper; i++)
	{
		if (arr[i] == key)
		{
			return 1;
		}
		

		if (arr[i] > middle)
		{
			lower = middle + 1;
		}
		else
		{
			upper = middle - 1;
		} 

		


	}
	return 0;


}



void main() {

	int arr[] = { 2,6,13,19,21,21,23,29,35,48,62,89,90,95,99,102,109,208,629 };
	int key = 2;
	

	int lower = 0;
	int upper = sizeof(arr)/sizeof(int);
	int middle = lower + upper / 2;
	int result = 0;



	result = finder(lower, middle, upper, arr, key);
	
	printf("%d", result);

}