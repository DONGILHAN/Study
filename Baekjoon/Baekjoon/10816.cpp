#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	vector<int> ans;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		auto upper = upper_bound(v.begin(), v.end(), num);
		auto lower = lower_bound(v.begin(), v.end(), num);
		ans.push_back(upper - lower);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

/*
#include <stdio.h>
#include <stdlib.h>

int M = 0, N = 0;

typedef struct
{
	int x;
} point;

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else 0;
}

int main()
{
	int f = 0, m = 0, l = 0;
	int tmpf = 0, tmpm = 0, tmpl = 0;
	int result = 0, now = 0;
	scanf("%d", &N);
	point* arr = (point*)malloc(sizeof(point)*N);
	for (int a = 0; a < N; a++)
		scanf("%d", &arr[a].x);
	qsort(arr, N, sizeof(int), compare);

	scanf("%d", &M);
	point* arr2 = (point*)malloc(sizeof(point)*M);
	for (int a = 0; a < M; a++)
		scanf("%d", &arr2[a].x);

	for (int a = 0; a < M; a++)
	{
		f = 0;
		m = N - 1;
		l = N - 1;
		result = 0;
		if ((arr2[a].x > arr[l].x) || (arr2[a].x < arr[f].x))
			printf("0 ");
		else
		{
			while (f != l)
			{
				m = (f + l) / 2;
				if (arr2[a].x == arr[m].x)
				{
					tmpf = f;
					tmpl = m;
					tmpm = (tmpf + tmpl) / 2;
					while ( 1 )
					{
						if (((arr2[a].x != arr[tmpm].x) && (arr2[a].x == arr[tmpm + 1].x)))
						{
							result += (m - tmpm);
							break;
						}
						else if (((arr2[a].x == arr[tmpm].x) && (arr2[a].x != arr[tmpm - 1].x)))
						{
							result+= (m - tmpm + 1);
							break;
						}
						else if (arr2[a].x < arr[tmpm].x)
						{
							tmpf = m;
							tmpm = (tmpf + tmpl) / 2;
						}
						else
						{
							if ((arr2[a].x == arr[tmpm].x) && (arr2[a].x == arr[tmpm - 1].x) && ((tmpl - tmpf == 2)))
							{
								result += (tmpm - m + 1);
								break;
							}
							tmpl = m;
							tmpm = (tmpf + tmpl) / 2;
						}
					}
					tmpf = m;
					tmpl = l;
					tmpm = (tmpf + tmpl) / 2;
					while (1)
					{
						if (((arr2[a].x == arr[tmpm].x) && (arr2[a].x != arr[tmpm + 1].x)))
						{
							result += (tmpm - m);
							break;
						}
						else if (((arr2[a].x != arr[tmpm].x) && (arr2[a].x == arr[tmpm - 1].x)))
						{
							result += (tmpm - m - 1);
							break;
						}
						else if (arr2[a].x > arr[tmpm].x)
						{
							tmpf = m;
							tmpm = (tmpf + tmpl) / 2;
						}
						else
						{
							if ((arr2[a].x == arr[tmpm].x) && (arr2[a].x == arr[tmpm + 1].x) && ((tmpl - tmpf == 2)))
							{
								result += (tmpm - m + 1);
								break;
							}
							tmpl = m;
							tmpm = (tmpf + tmpl) / 2;
						}
					}
					printf("%d ", result);
					break;
				}

				else if (arr2[a].x > arr[m].x)
				{
					f = m;
					if ((l - f) == 1)
					{
						if (arr[f].x == arr2[a].x || arr[l].x == arr2[a].x)
							printf("1 ");
						else
							printf("0 ");
						break;
					}
				}
				else
				{
					l = m;
					if ((l - f) == 1)
					{
						if (arr[f].x == arr2[a].x || arr[l].x == arr2[a].x)
							printf("1 ");
						else
							printf("0 ");
						break;
					}
				}
			}
		}
		
	}
}
*/