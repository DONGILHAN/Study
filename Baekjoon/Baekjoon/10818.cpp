#include <stdio.h>

int main()
{
	int x = 0;
	int max = -100000;
	int min = 100000;
	int num = 0;
	scanf("%d", &num);
	for (int a = 0; a < num; a++)
	{
		scanf("%d", &x);
		if (x >= max)
			max = x;
		if (x <= min)
			min = x;		
	}
	printf("%d %d", min, max);

}