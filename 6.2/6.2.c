#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void input(int** matrix, int rows, int cols) 
{
    int choice, i, j;

    srand(time(NULL));
    printf(">> 1 - Случайные числа\n>> 2 - Ручной ввод (ввод по числу на строку)\n");
    scanf_s("%d", &choice);
    switch (choice)
    {
    case 1:
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                *(*(matrix + i) + j) = rand() % 20 - 2;
        break;
    case 2:
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                scanf_s("%d", &matrix[i][j]);
        break;
    }
}

void output(int** matrix, int rows, int cols) 
{
    printf("> Матрица:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int productOfNegatives(int* row, int cols) 
{
    int product = 1;
    for (int i = 0; i < cols; i++)
        if (row[i] < 0)
            product *= row[i];
    return product;
}

void mergeRows(int* row1, int cols1, int* row2, int cols2, int* mergedRow) 
{
    int i = 0, j = 0, k = 0;
    while (i < cols1 && j < cols2)
    {
        if (row1[i] < row2[j])
            mergedRow[k++] = row1[i++];
        else
            mergedRow[k++] = row2[j++];
    }
    while (i < cols1)
        mergedRow[k++] = row1[i++];
    while (j < cols2)
        mergedRow[k++] = row2[j++];
}

void mergeSortRows(int** matrix, int rows, int cols) 
{
    if (rows <= 1)
        return;

    int mid = rows / 2;
    int** leftMatrix = (int**)malloc(mid * sizeof(int*));
    int** rightMatrix = (int**)malloc((rows - mid) * sizeof(int*));

    for (int i = 0; i < mid; i++)
        leftMatrix[i] = matrix[i];

    for (int i = mid; i < rows; i++)
        rightMatrix[i - mid] = matrix[i];

    mergeSortRows(leftMatrix, mid, cols);
    mergeSortRows(rightMatrix, rows - mid, cols);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < (rows - mid))
    {
        if (productOfNegatives(leftMatrix[i], cols) <= productOfNegatives(rightMatrix[j], cols))
            matrix[k++] = leftMatrix[i++];
        else
            matrix[k++] = rightMatrix[j++];
    }

    while (i < mid)
        matrix[k++] = leftMatrix[i++];

    while (j < (rows - mid))
        matrix[k++] = rightMatrix[j++];

    free(leftMatrix);
    free(rightMatrix);
}

int main() 
{
    int rows, cols;
    printf(">> Введите количество строк и столбцов матрицы: ");
    scanf_s("%d%d", &rows, &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols * sizeof(int));

    input(matrix, rows, cols);
    output(matrix, rows, cols);

    mergeSortRows(matrix, rows, cols);

    printf("> Результат сортировки:\n");
    output(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    _getch();
    return 0;
}