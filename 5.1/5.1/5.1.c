#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void enter(int* a, int val)
{
    printf("Введите размер массива: ");
    while (scanf_s("%d", a) == 0 || getchar() != '\n' || *a < val)
    {
        printf("Неверный ввод!\n");
        rewind(stdin);
    }
}

float* input(float* arr, int n)
{
    int choice;

    printf(">> 1 - Ручной ввод (ввод по числу на строку)\n>> 2 - Случайные числа\n");
    while (scanf_s("%d", &choice) == 0 || getchar() != '\n' || (choice != 1 && choice != 2))
    {
        printf("> Неверный ввод!\n");
        rewind(stdin);
    }

    if (choice == 1)
        for (int i = 0; i < n; i++) 
        {
            printf("\nВведите вещественное число для элемента %d: ", i);
            while (scanf_s("%f", &arr[i]) == 0 || getchar() != '\n')
            {
                printf("> Неверный ввод!\n");
                rewind(stdin);
            }
        }

    else if (choice == 2)
        for (int i = 0; i < n; i++)
            arr[i] = (rand() % 10) * 1.0123;
    return arr;
}

void output(float* arr, int n)
{
    printf("\nМассив после удаления целых чисел: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
}

void main()
{
    srand(time(NULL));
    int n;
    float* arr;
    enter(&n, 2);
    arr = malloc(sizeof(float) * n);
    arr = input(arr, n);

    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == (int)arr[i])
        {
            count++;
            for (int c = i; c < n - 1; c++)
                arr[c] = arr[c + 1];
            i--;
            n--;
        }
    }

    arr = realloc(arr, sizeof(float) * n);
    output(arr, n);
    free(arr);
    _getch();
}