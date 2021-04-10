#include <stdio.h>

int map[2188][2188];
int n = 0;
int answer[3] = { 0, 0, 0 };

void solution(int startX, int startY, int endX, int endY);

int main()
{
	scanf("%d", &n);
	for (int a = 1; a <= n; a++)
	{
		for (int b = 1; b <= n; b++)
		{
			scanf("%d", &map[a][b]);
		}
	}
	solution(1, 1, n, n);
	printf("%d\n%d\n%d", answer[0], answer[1], answer[2]);
}

void solution(int startX, int startY, int endX, int endY) 
{
	int start = map[startX][startY];
	int size = (endX - startX + 1) / 3;
	int size_two = size * 2;

	for (int i = startX; i <= endX; i++) 
	{
		for (int j = startY; j <= endY; j++) 
		{
			if (start != map[i][j]) 
			{
				solution(startX, startY, endX - size_two, endY - size_two);
				solution(startX, startY + size, endX - size_two, endY - size);
				solution(startX, startY + size_two, endX - size_two, endY);

				solution(startX + size, startY, endX - size, endY - size_two);
				solution(startX + size, startY + size, endX - size, endY - size);
				solution(startX + size, startY + size_two, endX - size, endY);

				solution(startX + size_two, startY, endX, endY - size_two);
				solution(startX + size_two, startY + size, endX, endY - size);
				solution(startX + size_two, startY + size_two, endX, endY);
				
				return;
			}
		}
	}

	if (start == -1)
		answer[0]++;
	else if (start == 0)
		answer[1]++;
	else
		answer[2]++;
}