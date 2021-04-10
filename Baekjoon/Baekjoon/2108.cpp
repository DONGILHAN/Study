#include <stdio.h>
#include <math.h>

int main()
{
	int N = 0;
	int now = 0;
	int arr2[8001] = { 0, };
	double avg = 0;
	int mid = 0, c = 0;;
	int min = 0, max = 0;
	int fre = 0, flag = 0, yes = 0;
	scanf("%d", &N);
	for (int a = 0; a < N; a++)
	{
		scanf("%d", &now);
		avg += now;
		arr2[now + 4000]++;
	}

	avg /= N;
	round(avg);
	
	c = 0;
	while (arr2[c] == 0)
	{
		c++;
	}
	min = c - 4000;
	c = 8000;
	while (arr2[c] == 0)
	{
		c--;
	}
	max = c - 4000;
	c = 0;
	while (mid <= (N / 2))
	{

		mid += arr2[c];
		c++;
	}
	for (int a = 8000; a >=0 ; a--)
	{
		if (arr2[a] > fre)
			fre = arr2[a];
	}
	for (int a = 0; a < 8001; a++)
	{
		if (arr2[a] == fre)
		{
			yes = a;
			flag++;
			if (flag == 2)
				break;
		}
	}
	
	printf("%.0f\n%d\n%d\n%d", avg, c - 4001, yes-4000, max-min );
}