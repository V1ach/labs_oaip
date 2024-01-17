#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void input(int** array, int size) 
{
    printf(">> Введите элементы массива:\n");
    for (int i = 0; i < size; i++)
        scanf_s("%d", &(*array)[i]);
}

void random(int** array, int size) 
{
    srand(time(NULL));
    printf("> Случайно сгенерированный массив:\n");
    for (int i = 0; i < size; i++) {
        (*array)[i] = rand() % 100 -20;
        printf("%d ", (*array)[i]);
    }
    printf("\n");
}

void output(int* array, int size) 
{
    printf("\n");
    printf("> Массив:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void shellSort(int* array, int size) 
{
    int gap = size / 2;
    while (gap > 0) 
    {
        for (int i = gap; i < size; i++) 
        {
            int temp = array[i];
            int j = i;
            while (j >= gap && array[j - gap] > temp) 
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
        gap /= 2;
    }
}

int main() 
{
    int size, choice;
    printf(">> Введите размер массива: ");
    scanf_s("%d", &size);

    int* array = (int*)malloc(size * sizeof(int));

    printf("\n");
    printf(">> Выберите способ ввода элементов массива:\n");
    printf(">> 1. Ввод с клавиатуры\n");
    printf(">> 2. Случайная генерация\n");
    scanf_s("%d", &choice);

    switch (choice) 
    {
    case 1:
        input(&array, size);
        break;
    case 2:
        random(&array, size);
        break;
    default:
        printf("> Некорректный ввод\n");
        free(array);
    }

    output(array, size);

    int positiveIndex = -1;
    for (int i = 0; i < size; i++) 
        if (array[i] > 0) {
            positiveIndex = i;
            break;
        }

    if (positiveIndex != -1)
        shellSort(&array[positiveIndex + 1], size - (positiveIndex + 1));

    printf("> Результат сортировки:\n");
    output(array, size);

    free(array);

    _getch();
}