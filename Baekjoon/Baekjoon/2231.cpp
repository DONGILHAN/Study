#include <stdio.h>

int main()
{
	int N = 0;
	int a = 6;
	int X[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
	int sum = 0;
	int now = 0;
	scanf("%d", &N);
	while (N / X[a] == 0) 
	{
		a--;
	}
	for (int b = 0; b < N; b++)
	{
		for (int c = 0; c <= a; c++)
		{
			sum += ((b / X[c]) - ((b / X[c+1]) * 10));
		}
		sum += b;
		if (sum == N)
		{
			now = b;
			break;
		}
		else
			sum = 0;
	}
	printf("%d", now);
}