#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void input(int* a, int val)
{
	while (scanf_s("%d", a) == 0 || getchar() != '\n' || *a < val)
	{
		printf("> Неверный ввод!\n");
		rewind(stdin);
	}
}

void create(int** arr, int* arr_l, int lines)
{
	srand(time(NULL));
	printf(">> Введите кол-во элементов на линии: \n");
	for (int i = 0; i < lines; i++)
	{
		int temp;
		input(&temp, 1);
		arr[i] = malloc(sizeof(int) * (temp + 1));
		arr_l[i] = temp;
	}
	int tmp = 0;
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < arr_l[tmp]; j++)
		{
			arr[i][j] = rand() % 10;
		}
		arr[i][arr_l[tmp]] = -100;
		tmp++;
	}
}

void print_arr(int** arr, int* arr_l, int lines)
{
	printf("\n");
	int tmp = 0;
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < arr_l[tmp] + 1; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
		tmp++;
	}
	printf("\n");
}

void dublicate(int** arr, int* arr_l, int lines)
{
	int tmp = 0;
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < arr_l[tmp]; j++)
		{
			if (i % 2 == 0 && arr[i][j] % 2)
			{
				arr_l[tmp]++;
				arr[i] = realloc(arr[i], sizeof(int) * (arr_l[tmp] + 1));
				for (int c = arr_l[tmp]; c > j; c--)
				{
					arr[i][c] = arr[i][c - 1];
				}
				j++;
			}
		}
		tmp++;
	}
}

void main()
{
	int** arr;
	int lines;
	printf(">> Введите кол-во линий:\n");
	input(&lines, 1);
	arr = malloc(sizeof(int*) * lines);
	int* arr_l = malloc(sizeof(int) * lines);
	create(arr, arr_l, lines);
	print_arr(arr, arr_l, lines);
	dublicate(arr, arr_l, lines);
	print_arr(arr, arr_l, lines);
	_getch();
}