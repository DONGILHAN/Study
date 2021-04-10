#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0, now = 0;
	int x = 0, y = 0;
	while (1)
	{
		char* stc = (char*)malloc(sizeof(char) * 101);
		i = 0;
		x = 0;
		y = 0;
		now = 0;
		int stack[101] = { 0, };
		while (1)
		{
			scanf("%c", stc + i);
			if (*(stc + i) == '\n')
				break;
			i++;
		}
		for (int a = 0; a < i; a++)
		{
			if (*(stc + a) == '(')
			{
				x++;
				stack[now] = 1;
				now++;
			}
			else if (*(stc + a) == ')')
			{
				if (x == 0)
				{
					//printf("no\n");
					x = -1;
					break;
				}
				else if (stack[now - 1] != 1)
				{
					//printf("no\n");
					x = -1;
					break;
				}
				else
				{
					x--;
					now--;
					stack[now] = 0;
				}
			}
			else if (*(stc + a) == '[')
			{
				y++;
				stack[now] = 2;
				now++;
			}
			else if (*(stc + a) == ']')
			{
				if (y == 0)
				{
					//printf("no\n");
					y=-1;
					break;
				}
				else if (stack[now - 1] != 2)
				{
					//printf("no\n");
					x = -1;
					break;
				}
				else
				{
					y--;
					now--;
					stack[now] = 0;
				}
			}
		}
		if (*stc == '.')
			break;
		if (x == 0 && y == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}