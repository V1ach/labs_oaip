#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void main()
{
	srand(time(NULL));
	int arr[100], n, length, choice, tmp;
	printf(">> Введите длину массива:\n");
	while (scanf_s("%d", &length) == 0 || getchar() != '\n' || length < 2) {
		printf("> Неверное значение\n");
		rewind(stdin);
	}
	printf(">> 1 - Ручной ввод (ввод по числу на строку) \n>> 2 - Случайные числа\n");
	while (scanf_s("%d", &choice) == 0 || getchar() != '\n' || (choice != 1 && choice != 2)) {
		printf("> Неверное значение\n");
		rewind(stdin);
	}
	if (choice == 1)
	{
		for (int i = 0; i < length; i++) {
			while (scanf_s("%d", &arr[i]) == 0 || getchar() != '\n') {
				printf("> Неверное значение\n");
				rewind(stdin);
			}
		}
	}
	else {
		for (int i = 0; i < length; i++) {
			arr[i] = rand() % 10;
		}
	}
	printf(">> Введите значение сдвига:\n");
	while (scanf_s("%d", &n) == 0 || getchar() != '\n' || n < 1) {
		printf("> Неверное значение\n");
		rewind(stdin);
	}
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	while (n != 0) {
		for (int i = 0; i < length - 2; i += 2) {
			tmp = arr[i];
			arr[i] = arr[i + 2];
			arr[i + 2] = tmp;
		}
		n--;
	}
	printf("\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	_getch();
}
