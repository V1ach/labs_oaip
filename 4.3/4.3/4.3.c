#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

int main()
{
	srand(time(NULL));
	int n, m, choice, i, j, arr[100][100], maximum = -INFINITY, tmp;
	printf("Введите количество строк и столбцов матрицы:\n");
	scanf_s("%d%d", &n, &m);
	printf(">> 1 - Ручной ввод (ввод по числу на строку)\n>> 2 - Случайные числа\n");
	scanf_s("%d", &choice);
	if (choice == 1) {
		printf("Введите %d элементов\n", m * n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf_s("%d", &arr[i][j]);
			}
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				printf("[%d][%d] = %d\t", i, j, arr[i][j]);
			}
			printf("\n");
		}
	}

	else if (choice == 2) {
		 for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				arr[i][j] = rand() % 10;
				printf("[%d][%d] = %d\t", i, j, arr[i][j]);
			}
			printf("\n");
		}
	}
	m = m % 2 ? m / 2 + 1 : m / 2;
	tmp = 0;
	for (j = 0; j < m; j++)
	{
		for (i = tmp; i < n; i++)
		{
			if (arr[i][j] % 2 && arr[i][j] > maximum)
			{
				maximum = arr[i][j];
			}
		}
		tmp++;
		n--;
	}
	printf("\n%d", maximum);
	_getch();
}