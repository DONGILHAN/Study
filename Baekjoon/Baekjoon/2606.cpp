#include <stdio.h>
#define MAX_VERTICES 101
int DFS_V[MAX_VERTICES] = { 0, }; //DFS를 실행하면서 방문한 정점을 표시하기 위한 배열
int graph[MAX_VERTICES][MAX_VERTICES] = { 0, };
int dfs(int v, int vertices);
int X = 0;

int main() 
{
	int vertices, edges, i, j;
	int vertex = 1;
	scanf("%d", &vertices);
	scanf("%d", &edges);

	while (edges--) 
	{
		scanf("%d %d", &i, &j);
		graph[i][j] = 1;
		graph[j][i] = 1;
	}

	printf("%d", dfs(vertex, vertices)-1);

	return 0;
}

int dfs(int v, int vertices) 
{
	int w;
	DFS_V[v] = 1;
	X++;
	for (w = 1; w <= vertices; w++) 
	{
		if (graph[v][w] == 1 && DFS_V[w] == 0) 
		{
			dfs(w, vertices);
		}
	}
	return (X);
}

