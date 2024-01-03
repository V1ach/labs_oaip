#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void input(int** arr, int n);
void output(int** arr, int n);

void main()
{
	int** arr;
	int n, i, j, k;

	printf(">> Введите количество строк и столбцов матрицы:\n");
	scanf_s("%d", &n);
	arr = (int**)malloc(sizeof(int*) * n);
	for (j = 0; j < n; j++)
		arr[j] = (int*)malloc(sizeof(int) * n);

	input(arr, n);
	output(arr, n, n);
	int c;
	for (int i = 0; i < n; i++)
	{
		for (c = n - i - 1; c < n - 1; c++)
			arr[i][c] = arr[i][c + 1];
		arr[i] = realloc(arr[i], sizeof(int) * (n - 1));
	}

	output(arr, n, n - 1);
	for (int j = 0; j < n; j++)
		free(arr[j]);
	free(arr);
	_getch();
}

void input(int** arr, int n)
{
	int choice, i, j;

	srand(time(NULL));
	printf(">> 1 - Случайные числа\n>> 2 - Ручной ввод (ввод по числу на строку)\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				*(*(arr + i) + j) = rand() % 20 - 2;
		break;
	case 2:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf_s("%d", *(arr + i) + j);
		break;
	}
}

void output(int** arr, int n, int cols)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("> a[%d][%d]= %d\t", i + 1, j + 1, *(*(arr + i) + j));
		printf("\n");
	}
}