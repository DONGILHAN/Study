#include<iostream>
using namespace std;

int K, N, ans;
int line[10001];
int  maxi = 0;
long long mid, high, low;

int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
		if (maxi < line[i]) maxi = line[i];
	}
	low = 1;
	high = maxi;
	ans = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += line[i] / mid;

		if (cnt >= N) {
			low = mid + 1;
			if (ans < mid) ans = mid;
		}
		else {// (cnt < N)
			high = mid - 1;
		}
	}

	cout << ans;
}


/*
#include <stdio.h>
#include <stdlib.h>

int N = 0, K = 0;
int first = 0, middle = 0, last = 0;
int ans = 0;

int bsearch(int f, int m, int l, int *leng);

int main()
{
	scanf("%d %d", &N, &K);
	int *length = (int *)malloc(sizeof(int) * N);

	for (int a = 0; a < N; a++)
	{
		scanf("%d", &length[a]);
		last += length[a];
	}
	first = 1;
	last = (last / N)+1;
	middle = ((first + last) / 2)+1;
	ans = bsearch(first, middle, last, length);
	printf("%d", ans);
}

int bsearch(int f, int m, int l, int *leng)
{
	int result = 0;
	int temp = 0;
	for (int a = 0; a < N; a++)
	{
		result += leng[a] / m;
	}
	if (result < K)
	{
		l = m;
		m = ((f + l) / 2) + 1;
		ans = bsearch(f, m, l, leng);
	}
	else if (result > K)
	{
		f = m;
		m = ((f + l) / 2 + 1);
		ans = bsearch(f, m, l, leng);
	}
	else
	{
		for (int a = 0; a < N; a++)
		{
			temp += leng[a] / (m + 1);
		}
		if (temp == result)
		{
			f = m;
			m = ((f + l) / 2 + 1);
			ans = bsearch(f, m, l, leng);
		}
		else
			return m;
	}
}
*/