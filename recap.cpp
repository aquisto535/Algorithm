#include <stdio.h>

// 재귀함수(배열의 위치를 인자로 넣는다 = first, last, targer) 
// => 배열의 위치를 통해 원하는 값을 얻어냄
// => 이 때 조건의 실행 함수를 재귀함수로 넣는다.
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