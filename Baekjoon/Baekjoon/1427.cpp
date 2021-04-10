#include <stdio.h>

int main()
{
	int N = 0;
	int x[10] = { 0, };
	int y[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
	int now = 9;
	int t = 10;
	scanf("%d", &N);
	while (N / y[t-1] == 0)
	{
		t--;
	}
	for (int a = 0; a < 10; a++)
	{
		x[a] = N % 10;
		N /= 10;
	}
	while (now >= 0)
	{
		for (int a = 0; a < t; a++)
		{
			if (x[a] == now)
				printf("%d",x[a]);
		}
		now--;
	}
}