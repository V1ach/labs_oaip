#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

int main()
{
    const int n = 3;
    int i, j, sum = 0, v = 0, maxsum = 0;
    int a[n][n], proizv[n], s[2 * n];;
    printf(">> Выберите ввод элементов: \n\n>> 1 - случайные числа\n>> 2 - ввод с клавиатуры\n");
    scanf_s("%i", &v);
    srand(time(0));
    switch (v)
    {
    case 1:
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                a[i][j] = rand() % 20 - 2;
        break;
    case 2:
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                printf("> a[%i][%i]= ", i + 1, j + 1);
                scanf_s("%i", &a[i][j]);
            }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        proizv[i] = 1;
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > 0) proizv[i] *= a[i][j]; else proizv[i] = 0;
        }
        if (proizv[i] > 0) printf(">> Произведение элементов строки %d равно: %d\n", i + 1, proizv[i]);
    }


    for (j = 0; j < (2 * n); j++) s[j] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j + i < n; j++)
        {
            s[j] += a[i][i + j];
            s[n + j] += a[i + j][i];
        }
    }
    for (j = 0; j < n; j++) printf("%d\n", s[j]);
    for (j = n + 1; j < (2 * n); j++) printf("%d\n", s[j]);
    maxsum = -1000;
    for (j = 1; j < n; j++)
        if (maxsum < s[j])
            maxsum = s[j];
    printf(">> Максимальная сумма равна: %d\n", maxsum);

    _getch();
}