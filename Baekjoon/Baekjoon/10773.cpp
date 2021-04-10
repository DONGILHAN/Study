#include <stdio.h>

int main()
{
	int K = 0, b = 0;
	int stack[100000] = { 0, };
	int now = 0;
	int result = 0;
	scanf("%d", &K);
	for (int x = 0; x < K; x++)
	{
		scanf("%d", &b);
		if (b > 0)
		{
			result += b;
			stack[now] = b;
			now++;
		}
		else
		{
			if (now > 0)
			{
				now--;
				result -= stack[now];
			}
		}
	}
	printf("%d", result);
}