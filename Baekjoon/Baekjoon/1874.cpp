#include <stdio.h>

int main()
{
	int n = 0, now = 0, ansnow = 1;
	int standard[100001] = { 0, };
	int stack[100002] = { 0, };
	int answer[200000] = { 0, };
	int push = 2;
	int pop = 0;
	
	scanf("%d", &n);
	for (int a = 0; a < n; a++)
	{
		scanf("%d", &standard[a]);
	}

	stack[0] = 1;
	answer[0] = 1;
	while (pop < n)
	{
		if (standard[pop] > stack[now])
		{
			stack[now+1] = push;
			answer[ansnow] = 1;
			now++;
			push++;
		}
		else if (standard[pop] == stack[now])
		{
			stack[now] = 0;
			now--;
			answer[ansnow] = 2;
			pop++;
		}
		else
		{
			ansnow = -1;
			break;
		}
		ansnow++;
	}
	if (ansnow > 0)
	{
		for (int a = 0; a < ansnow; a++)
		{
			if (answer[a] == 1)
				printf("+\n");
			else
				printf("-\n");
		}
	}
	else
	{
		printf("NO\n");
	}

}