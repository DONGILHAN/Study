#include <stdio.h>

long long matrix[6][6];
long long temp[6][6] = { { 1,0,0,0,0,0 },{ 0,1,0,0,0,0 },{ 0,0,1,0,0,0 },{ 0,0,0,1,0,0 },{ 0,0,0,0,1,0 },{ 0,0,0,0,0,1 } };
long long temp2[6][6] = { { 1,0,0,0,0,0 },{ 0,1,0,0,0,0 },{ 0,0,1,0,0,0 },{ 0,0,0,1,0,0 },{ 0,0,0,0,1,0 },{ 0,0,0,0,0,1 } };
long long result[6][6]= { { 1,0,0,0,0,0 },{ 0,1,0,0,0,0 },{ 0,0,1,0,0,0 },{ 0,0,0,1,0,0 },{ 0,0,0,0,1,0 },{ 0,0,0,0,0,1 } };
long long result2[6][6] = { { 1,0,0,0,0,0 },{ 0,1,0,0,0,0 },{ 0,0,1,0,0,0 },{ 0,0,0,1,0,0 },{ 0,0,0,0,1,0 },{ 0,0,0,0,0,1 } };
long long tempnow = 0, resultnow = 0;
long long A = 0;
long long B = 0;
long long binary[38] = { 0, };
long long position = 0, position2 = 1;
int main()
{
	scanf("%lld %lld", &A, &B);
	for (int a = 1; a <= A; a++)
	{
		for (int b = 1; b <= A; b++)
		{
			scanf("%lld", &temp[a][b]);
			matrix[a][b] = temp[a][b];
		}
	}
	while (B>0)
	{
		binary[position] = B % 2;
		B = B / 2;
		position++;
	}
	while (position2 < position)
	{
		if (tempnow % 2 == 0)
		{
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					temp2[a][b] = 0;
				}
			}
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					for (int c = 1; c <= A; c++)
					{
						for (int d = 1; d <= A; d++)
						{
							if (c == d)
								temp2[a][b] += ((temp[a][c] * temp[d][b])) % 1000;
						}
					}
				}
			}
			if (binary[position2] == 1)
			{
				if (resultnow % 2 == 0)
				{
					for (int a = 1; a <= A; a++)
					{
						for (int b = 1; b <= A; b++)
						{
							result2[a][b] = 0;
						}
					}
					for (int a = 1; a <= A; a++)
					{
						for (int b = 1; b <= A; b++)
						{
							for (int c = 1; c <= A; c++)
							{
								for (int d = 1; d <= A; d++)
								{
									if (c == d)
										result2[a][b] += ((result[a][c] * temp2[d][b])) % 1000;
								}
							}
						}
					}
				}
				else
				{
					for (int a = 1; a <= A; a++)
					{
						for (int b = 1; b <= A; b++)
						{
							result[a][b] = 0;
						}
					}
					for (int a = 1; a <= A; a++)
					{
						for (int b = 1; b <= A; b++)
						{
							for (int c = 1; c <= A; c++)
							{
								for (int d = 1; d <= A; d++)
								{
									if (c == d)
										result[a][b] += ((result2[a][c] * temp2[d][b])) % 1000;
								}
							}
						}
					}
				}
				resultnow++;
			}
		}
		else
		{
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					temp[a][b] = 0;
				}
			}
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					for (int c = 1; c <= A; c++)
					{
						for (int d = 1; d <= A; d++)
						{
							if (c == d)
								temp[a][b] += ((temp2[a][c] * temp2[d][b])) % 1000;
						}
					}
				}
			}
			if (binary[position2] == 1)
			{
				if (resultnow % 2 == 0)
				{
					for (int a = 1; a <= A; a++)
					{
						for (int b = 1; b <= A; b++)
						{
							result2[a][b] = 0;
						}
					}
					for (int a = 1; a <= A; a++)
					{
						for (int b = 1; b <= A; b++)
						{
							for (int c = 1; c <= A; c++)
							{
								for (int d = 1; d <= A; d++)
								{
									if (c == d)
										result2[a][b] += ((result[a][c] * temp[d][b])) % 1000;
								}
							}
						}
					}
				}
				else
				{
					for (int a = 1; a <= A; a++)
					{
						for (int b = 1; b <= A; b++)
						{
							result[a][b] = 0;
						}
					}
					for (int a = 1; a <= A; a++)
					{
						for (int b = 1; b <= A; b++)
						{
							for (int c = 1; c <= A; c++)
							{
								for (int d = 1; d <= A; d++)
								{
									if (c == d)
										result[a][b] += ((result2[a][c] * temp[d][b])) % 1000;
								}
							}
						}
					}
				}
				resultnow++;
			}
		}//Á¦°ö


		tempnow++;
		position2++;
	}

	if (binary[0] == 1)
	{
		if (resultnow % 2 == 0)
		{
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					result2[a][b] = 0;
				}
			}
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					for (int c = 1; c <= A; c++)
					{
						for (int d = 1; d <= A; d++)
						{
							if (c == d)
								result2[a][b] += ((result[a][c] * matrix[d][b])) % 1000;
						}
					}
				}
			}
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					printf("%lld ", (result2[a][b])%1000);
				}
				printf("\n");
			}
		}
		else
		{
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					result[a][b] = 0;
				}
			}
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					for (int c = 1; c <= A; c++)
					{
						for (int d = 1; d <= A; d++)
						{
							if (c == d)
								result[a][b] += ((result2[a][c] * matrix[d][b])) % 1000;
						}
					}
				}
			}
						for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					printf("%lld ", (result[a][b])%1000);
				}
				printf("\n");
			}
		}
	}
	else
	{
		if (resultnow % 2 == 0)
		{
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					printf("%lld ", (result[a][b]) % 1000);
				}
				printf("\n");
			}
		}
		else
		{
			for (int a = 1; a <= A; a++)
			{
				for (int b = 1; b <= A; b++)
				{
					printf("%lld ", (result2[a][b]) % 1000);
				}
				printf("\n");
			}
		}
	}
}
