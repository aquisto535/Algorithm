#include <stdio.h>

// ����Լ�(�迭�� ��ġ�� ���ڷ� �ִ´� = first, last, targer) 
// => �迭�� ��ġ�� ���� ���ϴ� ���� ��
// => �� �� ������ ���� �Լ��� ����Լ��� �ִ´�.
//int halfsearch(int ar[], int first, int last, int target)
//{
//	int mid = (first + last) / 2;
//
//	if (first > last)
//		return -1;
// 
// 	if (ar[mid] == target)
//		return mid;
//	else if (target < ar[mid])
//		halfsearch(ar, first, mid - 1, target);
//	else 
//		halfsearch(ar, mid + 1, last, target);
//}
//
//
//int main()
//{
//	int arr[] = {1,3,5,7,9}; 
//
//	halfsearch(arr, 0, sizeof(arr)/sizeof(int) - 1, 1);
//
//
//	return 0;
//}

int halfsearch(int ar[], int first, int last, int target)
{
	int mid = (first + last) / 2;


	if (first > last)
		return -1;


	if (target = mid)
		return 1;
	else if(target < mid)

}



int main()
{
	int arr[] = { 1,3,5,7,9 };



}