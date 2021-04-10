#include <iostream>

using namespace std;

int N, M;
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
		list[cnt] = a;
		dfs(cnt + 1);
	}
}