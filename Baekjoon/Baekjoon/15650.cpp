#include <iostream>

using namespace std;

bool check_dfs[9];
int list[9] = { 0, };
int N, M;

void dfs(int cnt, int last);

int main()
{
	cin >> N >> M;

	dfs(0, 1);
}

void dfs(int cnt, int last)
{
	if (cnt == M)
	{
		for (int a = 0; a < M; a++)
			cout << list[a] << " ";
		cout << "\n";
		return;
	}

	for (int a = last; a <= N; a++)
	{
		if (!check_dfs[a])
		{
			check_dfs[a] = true;
			list[cnt] = a;
			dfs(cnt + 1, a+1);
			check_dfs[a] = false;
		}
	}
}