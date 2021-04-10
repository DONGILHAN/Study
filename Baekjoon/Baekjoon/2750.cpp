/*
#include <stdio.h>
#include <stdlib.h>
int compare(const void* first,const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else 0;
}


int main()
{
	int N = 0;
	int arr[20];
	scanf("%d", &N);
	
	for (int a = 0; a < N; a++)
	{
		scanf("%d", &arr[a]);
	}
	qsort(arr, N, sizeof(int), compare);
	for (int a = 0; a < N; a++) printf("%d\n", arr[a]);
}
*/

#include <stdio.h>

void quick_sort(int *data, int start, int end) {
	if (start >= end) 
	{
		// 원소가 1개인 경우 
		return; 
	} 
	
	int pivot = start; 
	int i = pivot + 1; // 왼쪽 출발 지점 
	int j = end; // 오른쪽 출발 지점 
	int temp; 
	while(i <= j)
	{ 
		// 포인터가 엇갈릴때까지 반복 
		while(i <= end && data[i] <= data[pivot])
		{
			i++; 
		} 
		while(j > start && data[j] >= data[pivot])
		{ 
			j--; 
		} 
		if(i > j)
		{ 
			// 엇갈림 
			temp = data[j]; 
			data[j] = data[pivot]; 
			data[pivot] = temp; 
		}
		else
		{ 
			// i번째와 j번째를 스왑 
			temp = data[i]; 
			data[i] = data[j]; 
			data[j] = temp; 
		} 
	} 
	
	// 분할 계산 
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end); 
}

int main()
{
	int N = 0;
	int arr[1000000] = { 0, };
	scanf("%d", &N);
	for (int a = 0; a < N; a++)
	{
		scanf("%d", &arr[a]);
	}
	quick_sort(arr, 0, N-1);
	for (int a = 0; a < N; a++)
	{
		printf("%d\n", arr[a]);
	}
}