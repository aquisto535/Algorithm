#include <stdio.h>

//int Fibo(int n)
//{
//	if (n == 1)
//		return 0;
//	else if (n == 2)
//		return 1;
//	else
//		return Fibo(n - 1) + Fibo(n - 2);
//
//}

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;

	if (first >last) 
		return -1; // 반드시 탈출 조건을 명시해야 한다!!
	

	mid = (first + last) / 2;
	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		return BSearchRecur(ar, first, mid - 1, target);  // 앞부분을 대상으로 재탐색
	else
		return BSearchRecur(ar, mid + 1, last, target);  // 뒷부분을 대상으로 재탐색

}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 1);
	if (idx == -1)
	{
		printf("탐색 실패\n");
	}
	else 
	{
		printf("타겟 저장 인덱스: %d \n", idx);
	}
	

	return 0;
}