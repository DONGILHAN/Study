#include<stdio.h>

#define SZ 26

int vectX[4] = { 0, 0, 1, -1 };
int vectY[4] = { 1, -1, 0, 0 };

int map[SZ][SZ];
int house_size;
int house_cnt = 0;

// ������ ������ �迭 = ���� �� �ִ� ������ �ִ� ���� = n * (n/2) + 1
int house[SZ*(SZ / 2) + 1];

void swap(int* arr, int left, int right) {
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void bubble_sort(int* arr) {
	for (int i = 0; i < house_cnt; i++) {
		for (int j = 0; j < house_cnt - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
		}
	}
}

void do_dfs(int x, int y, int key) {
	// key : ���� ������ �ǹ�.. ������ ��ȣ �� ���� ���� ������ ������ �ȴ�.
	map[x][y] = key;

	int nextX; int nextY;
	for (int i = 0; i < 4; i++) {
		nextX = x + vectX[i];
		nextY = y + vectY[i];

		if (nextX >= 0 && nextY >= 0 && nextX < house_size && nextY < house_size) {
			//printf("map[%d][%d] = %d\n", nextX, nextY, map[nextX][nextY]);
			if (map[nextX][nextY] == 1) {
				// ��ǥ�� ���� �ȿ� ������ (x, y) ���� (nextX, nextY)���� ���� ���� �ִ� ���
				do_dfs(nextX, nextY, key);
			}
		}
	}
}

void solution() {
	for (int i = 0; i < house_size; i++) {
		for (int j = 0; j < house_size; j++) {
			if (map[i][j] == 1) {
				house_cnt++;
				do_dfs(i, j, house_cnt + 1);
			}
		}
	}

	for (int i = 0; i < house_size; i++) {
		for (int j = 0; j < house_size; j++) {
			if (map[i][j] > 1) {
				house[map[i][j] - 2] ++;
			}
		}
	}
}

int main() {
	scanf("%d", &house_size);
	for (int i = 0; i < house_size; i++) {
		for (int j = 0; j < house_size; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	solution();
	printf("%d\n", house_cnt);
	bubble_sort(house);
	for (int i = 0; i < house_cnt; i++) {
		printf("%d\n", house[i]);
	}
}