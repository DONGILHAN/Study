#include <stdio.h>
int P = 1000000007;

long long solution(long long n, long long k);

int main()
{
	int N = 1;
	int K = 1;
	int J = 1;
	int result = 1;
	long long A = 1, B = 1, C = 1;
	scanf("%d %d", &N, &K);

	if (K < (N / 2))
	{
		J = K;
		K = N - J;
	}
	else
	{
		J = N - K;
	}
	for (int c = N; c > N - J; c--)
	{
		A = (A * c) % P;
	}
	for (int d = 1; d <= J; d++)
	{
		B = (B * d) % P;
	}
	C = solution(B, P-2);
	result = (A*C) % P;
	printf("%d", result);
}


long long solution(long long a, long long b)
{
	if (b == 0)
		return 1;
	else if (b == 1)
		return a;
	else if (b % 2 == 0)
	{
		long long temp = solution(a, b / 2);
		return temp * temp % P;
	}
	else
		return a*solution(a, b - 1) % P;
}