#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int arr[100][100], k = -1, row, col, ResSuNotNull = 0, su = 0, v = 0;

    printf(">> Введите размер матрицы (строки и столбцы): ");
    scanf_s("%d", &row);
    scanf_s("%d", &col);

    printf(">> Выберите ввод элементов: \n\n>> 1 - случайные числа\n>> 2 - ввод с клавиатуры\n");
    srand(time(0));
    scanf_s("%d", &v);
    switch (v)
    {
    case 1:
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                arr[i][j] = rand() % 20 - 2;
        break;
    case 2:
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                scanf_s("%d", &arr[i][j]);
            }
    }

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++)
        {
            printf("> a[%d][%d]= %d\t", i + 1, j + 1, arr[i][j]);
        }
    printf("\n");
    }

    int count = 0;
    for (int i = 0; i < row; i++) {
        count = 0;
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 0) {
                count++;
            }
        }
        if (count == col) {
            k = i;
            break;
        }
    }

    if (k != -1)
    {
        printf(" Номер строки со всеми нулевыми элементами: %d\n ", (k + 1));
        for (int j = 0; j < row; j++)
            arr[j][k] = arr[j][k] / 2;
    }
    _getch();
}