#include <iostream> 
#include <algorithm> 
using namespace std; 

int home[200001];

int solution(int N, int C)
{
	int last = home[N-1];
	int first = 1; 
	int answer = 0;
	while(first <= last)
	{ 
		int cnt = 1;
		int mid = (first + last) / 2;
		int start = home[0];
		for (int i = 1; i < N; i++)
		{
			if (home[i] - start >= mid)
			{
				start = home[i];
				cnt++;
			}
		}
		if (cnt >= C)
		{
			answer = mid;
			first = mid + 1;
		}
		else
			last = mid - 1;
	}
	return answer;
}

int main()
{
	int N = 0, C = 0;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> home[i];

	sort(home, home + N);

	cout << solution(N, C);
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

int N = 0, C = 0;
int high, mid, low;
int now = 0;

int main()
{
	cin >> N >> C;
	int *router = new int[N];
	for (int a = 0; a < N; a++)
	{
		cin >> router[a];
	}
	sort(router, router + N);

	low = 1;
	high = router[N - 1] - router[0];
	mid = (low + high) / 2;
	if (high == 1)
		cout << "1";
	else
	{
		while (low <= high)
		{
			mid = (low + high) / 2;
			int x = 0;
			now = 0;
			for (int a = 1; a < N; a++)
			{
				if (router[a] - router[x] >= mid)
				{
					x = a;
					now++;
				}
			}
			if (now >= C)
				low = mid + 1;
			else
				high = mid - 1;
		}
		cout << mid;
	}
}
*/