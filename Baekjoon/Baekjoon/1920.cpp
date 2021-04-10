#include <stdio.h>
#include <stdlib.h>



typedef struct
{
	int x;
} point;

int N = 0, M = 0;
point Nnum[100000] = { 0, };
int Mnum[100000] = { 0, };

void merge(point* arr, int first, int mid, int last)
{
	int i, j, k;
	i = first;
	j = mid + 1;
	k = first;

	while (i <= mid && j <= last)
	{
		if (arr[i].x < arr[j].x)
			Nnum[k++] = arr[i++];
		else
			Nnum[k++] = arr[j++];
	}

	if (i <= mid)
	{
		while (i <= mid)
			Nnum[k++] = arr[i++];
	}
	else
	{
		while (j <= last)
			Nnum[k++] = arr[j++];
	}
	for (k = first; k <= last; k++)
		arr[k] = Nnum[k];
}



void mergeSort(point* arr, int first, int last)
{
	int mid;
	if (first < last)
	{
		mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}

int main()
{
	int f, m, l;
	scanf("%d", &N);

	point* arr = (point*)malloc(sizeof(point)*N);
	for (int a = 0; a < N; a++)
		scanf("%d", &arr[a].x);
	scanf("%d", &M);
	for (int a = 0; a < M; a++)
		scanf("%d", &Mnum[a]);
	mergeSort(arr, 0, N - 1);

	for (int a = 0; a < M; a++)
	{
		f = 0;
		m = N - 1;
		l = N - 1;
		if ((Mnum[a] > arr[l].x) || (Mnum[a] < arr[f].x))
			printf("0 ");
		else
		{
			while (f != l)
			{
				m = (f + l) / 2;
				if (Mnum[a] == arr[m].x)
				{
					printf("1 ");
					break;
				}

				else if (Mnum[a] > arr[m].x)
				{
					f = m;
					if ((l - f) == 1)
					{
						if (arr[f].x == Mnum[a] || arr[l].x == Mnum[a])
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
						if (arr[f].x == Mnum[a] || arr[l].x == Mnum[a])
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

