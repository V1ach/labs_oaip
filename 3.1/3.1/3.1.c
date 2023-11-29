#include <stdlib.h>
#include <stdio.h>    
#include <conio.h>
#include <math.h>
#include <time.h>

int main()
{
    int c = 0, var = 0, i = 0, k = 0, s = 0, n = 0, massiv[100], x = 0, j = 0, count = 0;
    srand(time(NULL));

    printf(">> Введите количество элементов массива: ");
    while (scanf_s("%d", &n) == 0 || getchar() != '\n' || (n < 0 && n > 9))
    {
        printf("> Невеный ввод!\n");
        rewind(stdin);
    }

    printf(">> 1 - Ручной ввод (ввод по числу на строку) \n>> 2 - Случайные числа\n");

    while (scanf_s("%d", &c) == 0 || getchar() != '\n' || (c != 1 && c != 2))
    {
        printf("> Невеный ввод!\n");
        rewind(stdin);
    }

    if (c == 1)
    {
        printf(">> Введите элементы массива: ");
        for (i = 0; i < n; i++)
            while (scanf_s("%d", &massiv[i]) == 0 || getchar() != '\n' || (massiv[i] < 0 && massiv[i] > 9))
            {
                printf("> Невеный ввод!\n");
                rewind(stdin);
            }
    }

    if (c == 2)
    {
        for (i = 0; i < n; i++)
        {
            massiv[i] = rand() % 10;
        }
    }

    for (i = 0; i < n; i++)
        printf("\n> %d элемент массива равен: %d", i, massiv[i]);

    for (i = 0; i < n; i++)
    {
        if (massiv[i] == 0)
            k++;
    }

    printf("\n\n> Кол-во элементов массива равных нулю: %d", k);

    j = massiv[0];

    for (i = 0; i < n; i++)
    {
        if (massiv[i] < j) {
            j = massiv[i];
            x = i + 1;
        }
    }
    for (i = x; i < n; i++)
        s += massiv[i];

    printf("\n> Сумма элементов массива расположенных после минимального элемента: %d\n", s);

    _getch();
}