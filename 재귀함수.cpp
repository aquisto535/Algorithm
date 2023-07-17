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
		return -1; // �ݵ�� Ż�� ������ ����ؾ� �Ѵ�!!
	

	mid = (first + last) / 2;
	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		return BSearchRecur(ar, first, mid - 1, target);  // �պκ��� ������� ��Ž��
	else
		return BSearchRecur(ar, mid + 1, last, target);  // �޺κ��� ������� ��Ž��

}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 1);
	if (idx == -1)
	{
		printf("Ž�� ����\n");
	}
	else 
	{
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	}
	

	return 0;
}