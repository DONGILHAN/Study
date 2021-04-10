#include <iostream>
#include <algorithm>

using namespace std;

long long N, k;

long long solution(long long value);

int main()
{
	cin >> N >> k;
	long long first = 1;
	long long end = N * N;
	long long answer;
	while (first <= end)
	{
		long long mid = (first + end) / 2;
		if (solution(mid) < k)
			first = mid + 1;
		else
		{
			answer = mid;
			end = mid - 1;
		}
	}
	cout << answer;
}

long long solution(long long value)
{
	long long sum = 0;
	for (int a = 1; a < N + 1; a++)
		sum += min(N, value / a);
	return sum;
}