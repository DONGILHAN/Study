#include <stdio.h>

int A[101][101];
int B[101][101];
int result[101][101];
int N = 0, M = 0, K = 0;
int main()
{
	scanf("%d %d", &N, &M);
	for (int a = 1; a <= N; a++)
	{
		for (int b = 1; b <= M; b++)
		{
			scanf("%d", &A[a][b]);
		}
	}

	scanf("%d %d", &M, &K);
	for (int a = 1; a <= M; a++)
	{
		for (int b = 1; b <= K; b++)
		{
			scanf("%d", &B[a][b]);
		}
	}

	for (int a = 1; a <= N; a++)
	{
		for (int b = 1; b <= K; b++)
		{
			for (int c = 1; c <= M; c++)
			{
				for (int d = 1; d <= M; d++)
				{
					if (c == d)
						result[a][b] += (A[a][c] * B[d][b]);
				}
			}
		}
	}

	for (int a = 1; a <= N; a++)
	{
		for (int b = 1; b <= K; b++)
		{
			printf("%d ", result[a][b]);
		}
		printf("\n");
	}
}