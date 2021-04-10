#include <stdio.h>

long long A = 0, B = 0, C = 0;

long long solution(long long a, long long b);

int main()
{
	scanf("%d %d %d", &A, &B, &C);

	printf("%d", solution(A, B));

}

long long solution(long long a, long long b)
{
	a %= C;

	if (b == 0)
		return 1;
	else if (b == 1)
		return a;
	else if (b % 2 == 0)
	{
		long long temp = solution(a, b / 2);
		return temp * temp % C;
	}
	else
		return a*solution(a, b-1)%C;
}