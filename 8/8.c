#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void create(char** arr, char** argv, int argc)
{
	for (int i = 0; i < argc - 1; i++)
		arr[i] = malloc(sizeof(char) * 10);
	int i = 0, j = 0, c = 0;
	while (j < argc - 1)
	{
		if (i >= 10)
			arr[j] = realloc(arr[j], sizeof(char) * (i + 1));
		if (argv[1][c] == '\0')
		{
			arr[j][i] = '\0';
			j++;
			i = 0;
			c++;
		}
		else
		{
			arr[j][i] = argv[1][c];
			i++;
			c++;
		}
	}
}

int length(char** arr, int s)
{
	int i = 0;
	while (arr[s][i] != '\0' && arr[s][i] != '\n')
		i++;
	return i;
}

void sort(char** arr, int left, int right)
{
	if (left > right) return;
	char* tmp;
	int mid = (left + right) / 2;
	int p = length(arr, mid);
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (length(arr, i) > p) i++;
		while (length(arr, j) < p) j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++, j--;
		}
	}
	sort(arr, left, j);
	sort(arr, i, right);
}

void show(char** arr, int size)
{
	for (int i = 0; i < size; i++)
		puts(arr[i]);
	printf("\n");
}

void clear(char** arr, int size)
{
	for (int i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
}

void main(int argc, char** argv)
{
	char** arr = malloc(sizeof(int*) * (argc - 1));
	create(arr, argv, argc);
	printf("> Изначальный строки:\n");
	show(arr, argc - 1);
	printf("\n> Полученные на выходе строки:\n");
	sort(arr, 0, argc - 2);
	show(arr, argc - 1);
	clear(arr, argc - 1);
	_getch();
}
