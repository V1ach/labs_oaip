#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void input(int** arr, int n, int m);
void output(int** arr, int n, int m);

void main()
{
	int** arr;
	int n, m, i, j;

	printf("Введите количество строк и столбцов матрицы:\n");
	scanf_s("%d%d", &n, &m);
	arr = (int**)malloc(sizeof(int**) * m);

	for (j = 0; j < m; j++)
		arr[j] = (int*)malloc(sizeof(int*) * n);

	input(arr, n, m);

	for (i = 0; i < n; i++)
	{
		if (arr[i][m - 1] != -100)
		{
			printf("Неверный вввод, во всех строках последнее число должно быть -100"); 
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			for (j = 0; j < m; j++)
			{
				if (arr[i][j] % 2 == 1)
				{
					arr[i][j + 1] = arr[i][j];
					j++;
				}
			}
		}
	}

	output(arr, n, m);

	free(arr);
	_getch();
}

void input(int** arr, int n, int m)
{
	int choice, i, j;

	srand(time(NULL));
	printf(">> 1 - Случайные числа\n>> 2 - Ручной ввод (ввод по числу на строку)\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				*(*(arr + i) + j) = rand() % 20 - 2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				printf("> a[%d][%d]= %d\t", i + 1, j + 1, *(*(arr + i) + j));
			printf("\n");
		}
		break;
	case 2:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf_s("%d", *(arr + i) + j);
		break;
	}
}

void output(int** arr, int n, int m)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("> a[%d][%d]= %d\t", i + 1, j + 1, *(*(arr + i) + j));
		printf("\n");
	}

}