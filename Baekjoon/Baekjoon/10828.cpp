#include <stdio.h>
#include <string.h>

int main(void)
{
	int N, M = 0;
	scanf("%d", &N);
	int stack[100000] = { 0, };
	int now=0;
	char x[6];
	for (int a = 0; a < N; a++)
	{
		scanf("%s", &x);
		if (!strcmp(x, "push"))
		{
			scanf("%d", &M);
			stack[now] = M;
			now++;
		}
		else if (!strcmp(x, "pop"))
		{
			if (now == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", stack[now - 1]);
				now--;
			}
		}
		else if (!strcmp(x, "size"))
		{
			printf("%d\n", now);
		}
		else if (!strcmp(x, "top"))
		{
			if (now == 0)
				printf("-1\n");
			else
				printf("%d\n", stack[now-1]);
		}
		else
		{
			if (now == 0)
				printf("1\n");
			else
				printf("0\n");
		}
	}
}