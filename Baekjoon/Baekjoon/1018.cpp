#include <stdio.h>

int main()
{
	int N = 0, M = 0;
	char x[50];
	int changeOne[50][50] = { 0, };
	int changeTwo[50][50] = { 0, };
	int result = 100;
	int cnt = 0, cnt2 = 0;

	scanf("%d %d", &N, &M);
	for (int a = 0; a < N; a++) {
		scanf("%s", x);
		for (int b = 0; b < M; b++)
		{
			if ((a + b) % 2 == 0)
			{
				if (x[b] == 'W')
					changeOne[a][b] = 1;
				else if (x[b] == 'B')
					changeTwo[a][b] = 1;
			}
			else
			{
				if (x[b] == 'W')
					changeTwo[a][b] = 1;
				else if (x[b] == 'B')
					changeOne[a][b] = 1;
			}
		}
	}
	
	for (int c = 0; c <= N - 8; c++)
	{
		for (int d = 0; d <= M - 8; d++)
		{
			for (int X = c; X < c + 8; X++)
			{
				for (int Y = d; Y < d + 8; Y++)
				{
					cnt += changeOne[X][Y];
					cnt2 += changeTwo[X][Y];
				}
			}
			if (cnt > cnt2)
				cnt = cnt2;
			if (result > cnt)
			{
				result = cnt;
			}
			cnt = 0;
			cnt2 = 0;
		}
	}
	printf("%d", result);
}