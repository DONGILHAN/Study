#include <iostream>
#include <algorithm>

using namespace std;

int N;
int main()
{
	cin >> N;
	int *A = new int[N];
	int answer = 0;
	for (int a = 0; a < N; a++)
		cin >> A[a];
	int now = A[0];
	for (int a = 1; a < N; a++)
	{
		if (A[a] > now)
		{
			now = A[a];
			answer++;
		}
	}
	cout << answer+1;
}