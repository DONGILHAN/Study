/*
#include <iostream>

using namespace std;

int matrix[10][10] = { 0, };
int zero = 0;

void solution(int a, int b);
void row_change(int a, int b);
void col_change(int a, int b);
void small_change(int a, int b, int tmpa, int tmpb);

int main()
{
	for (int a = 1; a < 10; a++)
	{
		for (int b = 1; b < 10; b++)
		{
			cin >> matrix[a][b];
			if (matrix[a][b] == 0)
				zero++;
		}
	}

	while (zero != 0)
	{
		for (int a = 1; a < 10; a++)
		{
			for (int b = 1; b < 10; b++)
			{
				if (matrix[a][b] == 0)
					solution(a, b);
			}_
		}
	}
	for (int a = 1; a < 10; a++)
	{
		for (int b = 1; b < 10; b++)
			cout << matrix[a][b] << " ";
		cout << "\n";
	}
}

void solution(int a, int b)
{
	int x = 0;
	for (int i = 1; i < 10; i++)
	{
		if (matrix[a][i] == 0)
			x++;
	}
	if (x == 1)
	{
		zero--;
		row_change(a, b);
		return;
	}
	else
	{
		x = 0;
		for (int i = 1; i < 10; i++)
		{
			if (matrix[i][b] == 0)
				x++;
		}
		if (x == 1)
		{
			zero--;
			col_change(a, b);
			return;
		}
		else
		{
			x = 0;
			int tmpa = ((a - 1) / 3) * 3;
			int tmpb = ((b - 1) / 3) * 3;
			for (int i = tmpa + 1; i < tmpa + 4; i++)
			{
				for (int j = tmpb + 1; j < tmpb + 4; j++)
				{
					if (matrix[i][j] == 0)
						x++;
				}
			}
			if (x == 1)
			{
				zero--;
				small_change(a, b, tmpa + 1, tmpb + 1);
				return;
			}
		}
	}
}

void small_change(int a, int b, int tmpa, int tmpb)
{
	int num[10] = { 0, };
	for (int i = tmpa; i < tmpa + 3; i++)
	{
		for (int j = tmpb; j < tmpb + 3; j++)
			num[matrix[i][j]] = 1;
	}
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 0)
		{
			matrix[a][b] = i;
			return;
		}
	}
}

void row_change(int a, int b)
{
	int num[10] = { 0, };
	for (int i = 1; i < 10; i++)
		num[matrix[a][i]] = 1;
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 0)
		{
			matrix[a][b] = i;
			return;
		}
	}
}

void col_change(int a, int b)
{
	int num[10] = { 0, };
	for (int i = 1; i < 10; i++)
		num[matrix[i][b]] = 1;
	for (int i = 1; i < 10; i++)
	{
		if (num[i] == 0)
		{
			matrix[a][b] = i;
			return;
		}
	}
}
*/