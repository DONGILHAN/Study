#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int len;
	char str[51];
}word;

int compare(const void *a, const void *b)
{
	word real_a = *(word*)a;
	word real_b = *(word*)b;
	int len_a = strlen(real_a.str);
	int len_b = strlen(real_b.str);

	if (len_a != len_b)
		return (len_a - len_b);
	return strcmp(real_a.str, real_b.str);
}

int main()
{
	word* words;
	word tmp;
	int flag = 0, real_n = 0;

	char strtmp[51] = { 0 };
	int N = 0;
	scanf("%d", &N);

	words = (word*)malloc(sizeof(word)*N);

	for (int a = 0; a < N; a++)
	{
		scanf("%s", strtmp);
		for (int b = 0; b < a; b++)
		{
			if (strcmp(words[b].str, strtmp) == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			strcpy(words[real_n].str, strtmp);
			words[real_n].len = strlen(strtmp);
			real_n++;
		}
		flag = 0;
	}
	qsort(words, real_n, sizeof(word), compare);
	for (int a = 0; a < real_n; a++)
	{
		printf("%s\n", words[a].str);
	}
	free(words);
	return 0;
}