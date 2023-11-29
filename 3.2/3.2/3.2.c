#include <stdlib.h>
#include <stdio.h>    
#include <conio.h>
#include <math.h>
#include <time.h>

int main()
{
    int c = 0, var = 0, i = 0, k = 0, s = 0, n = 0, massiv[100], x = 0, j = 0, count = 0, sdvig = 0, tmp = 0;
    srand(time(NULL));

    printf(">> Введите количество элементов массива: ");
    while (scanf_s("%d", &n) == 0 || getchar() != '\n' || (n < 0 && n > 9))
    {
        printf("> Невеный ввод!\n");
        rewind(stdin);
    }

    printf(">> 1 - Ручной ввод (ввод по числу на строку)\n>> 2 - Случайные числа\n");
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

        printf(">> Введите значение сдвига: ");
        scanf_s("%d", &sdvig);
    }

    if (c == 2)
    {
        for (i = 0; i < n; i++)
        {
            massiv[i] = rand() % 10;
        }
        for (i = 1; i < 10; i++)
        {
            sdvig = rand() % 10;
        }
    }

    for (i = 0; i < n; i++)
        printf("\n> %d элемент массива равен: %d", i+1, massiv[i]);

    printf("\n\n> Заданное значение сдвига равно: %d\n\n\n", sdvig);
    sdvig *= 2;

    for (i = 0; i < n / 2 - 1; i++) 
    {
        if (i % 2 == 0)
        {
            tmp = massiv[i];
            if (i - sdvig >= 0)
            {
                massiv[i] = massiv[i - sdvig];
                massiv[i - sdvig] = tmp;
            }
            else
            {
                massiv[i] = massiv[n - sdvig + i];
                massiv[n - sdvig + i] = tmp;
            }
            
        }
    }

    for (i = 0; i < n; i++) 
        printf("> %d элемент нового массива равен: %d\n", i+1, massiv[i]);

    _getch();
}