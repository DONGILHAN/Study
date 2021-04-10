#include <stdio.h>

int main()
{
	int N = 0, M = 0;
	int list[100];
	int x = 0, y = 1, z = 2;
	int sum = 0;
	scanf("%d %d", &N, &M);
	int now = 0;
	for (int a = 0; a < N; a++)
	{
		scanf("%d", &list[a]);
	}
	while (x < (N - 2))
	{
		while (y < (N - 1))
		{
			while (z < N)
			{
				sum = list[x] + list[y] + list[z];
				if (sum <= M)
				{
					if (sum >= now)
						now = sum;
				}
				z++;
			}
			y++;
			z = y + 1;
		}
		x++;
		y = x + 1;
		z = y + 1;
	}
	printf("%d", now);
}