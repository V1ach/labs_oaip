#include <stdio.h>
#include <conio.h>
#include <time.h>

void main()
{
	int i, arr1[31], arr2[31], c, result[31], a = 0;
	srand(time(NULL));

	printf(">> 1 - Ручной ввод (ввод по числу на строку) \n>> 2 - Случайные числа\n");

	while (scanf_s("%d", &c) == 0 || getchar() != '\n' || (c != 1 && c != 2))
	{
		printf("> Невеный ввод!\n");
		rewind(stdin);
	}

	if (c == 1)
	{
		printf("> Введите первое число:\n");
		for (i = 1; i < 31; i++)
		{
			while (scanf_s("%d", &arr1[i]) == 0 || getchar() != '\n' || arr1[i] < 0 || arr1[i] > 9)
			{
				printf("> Невеный ввод!\n");
				rewind(stdin);
			}
		}

		printf("\n> Введите второе число:\n");
		for (i = 1; i < 31; i++)
		{
			while (scanf_s("%d", &arr2[i]) == 0 || getchar() != '\n' || arr2[i] < 0 || arr2[i] > 9)
			{
				printf("> Невеный ввод!\n");
				rewind(stdin);
			}
		}
	}

	if (c == 2)
	{
		for (i = 1; i < 31; i++)
		{
			arr1[i] = rand() % 10;
		}
		for (i = 1; i < 31; i++)
		{
			arr2[i] = rand() % 10;
		}
	}

	printf("\n> Первый массив: ");
	for (i = 1; i < 31; i++)
	{
		printf("%d", arr1[i]);
	}

	printf("\n> Второй массив: ");
	for (i = 1; i < 31; i++)
	{
		printf("%d", arr2[i]);
	}
	for (i = 30; i > 0; i--)
	{
		if (arr1[i] + arr2[i] + a < 10)
		{
			result[i] = arr1[i] + arr2[i] + a;
			a = 0;
		}
		else
		{
			result[i] = (arr1[i] + arr2[i] + a) % 10;
			a = 1;
		}
	}

	printf("\n");
	if (arr1[1] + arr2[1] + a > 10)
	{
		result[0] = 1;
		i = 0;
	}
	else
	{
		i = 1;
	}
	printf("\n> Результат:	 ");
	for (i; i < 31; i++)
	{
		printf("%d", result[i]);
	}
	
	printf("\n");

	_getch();
}