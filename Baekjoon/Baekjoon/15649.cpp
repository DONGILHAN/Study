#include <iostream>

using namespace std;

int N, M;
bool check_dfs[9] = { 0, };
int list[9] = { 0, };

void dfs(int cnt);

int main()
{
	cin >> N >> M;

	dfs(0);
}

void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int a = 0; a < M; a++)
			cout << list[a] << " ";
		cout << "\n";
		return;
	}

	for (int a = 1; a <= N; a++)
	{
		if (!check_dfs[a])
		{
			check_dfs[a] = true;
			list[cnt] = a;
			dfs(cnt + 1);
			check_dfs[a] = false;
		}
	}
}