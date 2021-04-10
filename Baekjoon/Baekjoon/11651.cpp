#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} point;

point sort[100001];

void merge(point* arr, int first, int mid, int last)
{
	int i, j, k;
	i = first;
	j = mid + 1;
	k = first;

	while (i <= mid && j <= last)
	{
		if (arr[i].x < arr[j].x)
			sort[k++] = arr[i++];
		else if (arr[i].x > arr[j].x)
			sort[k++] = arr[j++];
		else
		{
			if (arr[i].y < arr[j].y)
				sort[k++] = arr[i++];
			else if (arr[i].y > arr[j].y)
				sort[k++] = arr[j++];
		}
	}

	if (i <= mid)
	{
		while (i <= mid)
			sort[k++] = arr[i++];
	}
	else
	{
		while (j <= last)
			sort[k++] = arr[j++];
	}
	for (k = first; k <= last; k++)
		arr[k] = sort[k];
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
	int N;
	scanf("%d", &N);

	point* arr = (point*)malloc(sizeof(point)*N);
	for (int a = 0; a < N; a++)
	{
		scanf("%d %d", &arr[a].y, &arr[a].x);
	}
	mergeSort(arr, 0, N - 1);
	for (int a = 0; a < N; a++)
		printf("%d %d\n", arr[a].y, arr[a].x);
}