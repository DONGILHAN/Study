#include <stdio.h>
#include <string.h>

int main()
{
	int T = 0;
	int result = 0;
	char PS[51];
	scanf("%d", &T);
	for (int a = 0; a < T; a++)
	{
		scanf("%s", &PS);
		for (int b = 0; b < strlen(PS); b++)
		{
			if (PS[b] == '(')
				result++;
			else if (PS[b] == ')')
			{
				result--;
				if (result < 0)
					break;
			}
		}
		if (result == 0)
			printf("YES\n");
		else
			printf("NO\n");
		result = 0;
	}
}