#include <stdio.h>

int Bsearch(int ar[], int first, int last, int target)
{
	int mid = (first + last) / 2;

	if (first > last)
		return -1;

	if (ar[mid] == target)
		return mid;
	else if (ar[mid] > target)
		return Bsearch(ar,  first, mid - 1, target);
	else
		return Bsearch(ar, mid + 1, last, target);


}


int main()
{
	int arr[] = { 1,3,5,7,9 };

	int idx = Bsearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 3);

	if (idx == - 1)
	{
		printf("Å½»ö ½ÇÆĞ\n");
	}
	else
	{
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);
	}

}