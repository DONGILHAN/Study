#include <stdio.h>

int main()
{
	int N = 0;
	int x[50] = { 0, };
	int y[50] = { 0, };
	int ans[50] = { 0, };

	scanf("%d", &N);
	for (int a = 0; a < N ; a++)
	{
		scanf("%d %d", &x[a], &y[a]);
	}
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
		{
			if (x[a] < x[b] && y[a] < y[b])
			{
				ans[a]++;
			}
		}
	}
	for (int a = 0; a < N; a++)
	{
		printf("%d ", ans[a]+1);
	}
}