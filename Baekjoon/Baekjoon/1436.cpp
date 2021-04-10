#include <stdio.h>

int main()
{
	int cnt = 1, N = 0, now = 667;
	int x = 0;
	scanf("%d", &N);

	while (cnt < N)
	{
		x = now;
		while (x > 100)
		{
			if (x % 1000 != 666)
			{
				x /= 10;
			}
			else
			{
				cnt++;
				break;
			}
		}
		now++;
	}
	printf("%d", now-1);
}