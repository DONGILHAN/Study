#include <iostream>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
int low = 0, mid = 0;
int high = 0;
long long result = 0;

int main()
{
	cin >> N >> M;
	int *tree = new int[N];
	cin >> tree[0];
	for (int a = 1; a < N; a++)
	{
		cin >> tree[a];
	}
	sort(tree, tree+N);
	
	high = tree[N-1];
	mid = (high + low) / 2;
	while (low <= high)
	{
		result = 0;
		for (int a = N-1; a >=0; a--)
		{
			if ((tree[a] - mid) <= 0)
				break;
			else
				result += (tree[a] - mid);
		}
		if (result == M)
			break;
		else if (result > M)
		{
			low = mid + 1;
			mid = (high + low) / 2;
		}
		else
		{
			high = mid - 1;
			mid = (high + low) / 2;
		}
	}
	cout << mid;

}