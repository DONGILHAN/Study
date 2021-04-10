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
		// ���Ұ� 1���� ��� 
		return; 
	} 
	
	int pivot = start; 
	int i = pivot + 1; // ���� ��� ���� 
	int j = end; // ������ ��� ���� 
	int temp; 
	while(i <= j)
	{ 
		// �����Ͱ� ������������ �ݺ� 
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
			// ������ 
			temp = data[j]; 
			data[j] = data[pivot]; 
			data[pivot] = temp; 
		}
		else
		{ 
			// i��°�� j��°�� ���� 
			temp = data[i]; 
			data[i] = data[j]; 
			data[j] = temp; 
		} 
	} 
	
	// ���� ��� 
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