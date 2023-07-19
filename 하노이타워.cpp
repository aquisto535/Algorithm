#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to )
{
	if (num == 1)
	{
		printf("원반 1을 %c에서 %c로 이동\n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d를 %c에서 %c로 이동\n", num, from, to);
		HanoiTowerMove(num -1, by, from, to);
	}

}

int main()
{
	//막대A의 원반 3개를 막대B를 경유하여 막대 C로 옮기기

	HanoiTowerMove(3, 'A', 'B', 'C');

	return 0;
}