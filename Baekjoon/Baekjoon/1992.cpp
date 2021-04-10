#include <stdio.h>

char map[65][65];
int n = 0;
void solution(int startX, int startY, int endX, int endY);

int main()
{
	scanf("%d", &n);

	for (int a = 0; a < n; a++)
	{
		scanf("%s", &map[a]);
	}
	solution(0, 0, n-1, n-1);
}

void solution(int startX, int startY, int endX, int endY)
{
	int start = int(map[startX][startY]) - 48 ;
	int size = (endX - startX + 1) / 2;

	for (int a = startX; a <= endX; a++)
	{
		for (int b = startY; b <= endY; b++)
		{
			if (start != (int(map[a][b]) - 48))
			{
				printf("(");
				solution(startX, startY, endX - size, endY - size);
				solution(startX, startY + size, endX - size, endY);
				solution(startX + size, startY, endX, endY - size);
				solution(startX + size, startY + size, endX, endY);
				printf(")");

				return;
			}
		}
	}
	if (start == 0)
		printf("0");
	else
		printf("1");
}