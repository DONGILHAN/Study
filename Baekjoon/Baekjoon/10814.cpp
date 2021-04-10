#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int age;
	char name[101];
}member;

int main()
{
	int N = 0;
	int cnt = 0;
	int agecnt = 0;
	scanf("%d", &N);

	member* mem;
	mem = (member*)malloc(sizeof(member)*N);
	for (int a = 0; a < N; a++)
	{
		scanf("%d %s", &mem[a].age, mem[a].name);
	}
	while (cnt < N)
	{
		for (int a = 0; a < N; a++)
		{
			if (mem[a].age == agecnt)
			{
				printf("%d %s\n", mem[a].age, mem[a].name);
				cnt++;
			}
		}
		agecnt++;

	}
}