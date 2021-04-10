#include <stdio.h>
int main()
{
	int N = 0;
	scanf("%d", &N);
	int x = 0;

	int arr[10001] = { 0, };
	for (int a = 0; a < N; a++)
	{
		scanf("%d", &x);
		arr[x] += 1;
	}
	for (int a = 0; a < 10001; a++)
	{
		for (int b=0; b<arr[a];b++)
			printf("%d\n", a);
	}
}