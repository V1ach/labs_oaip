#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    int number1 = 0, number2 = 0, number3 = 0;

    printf("Введите числа для проверки на четность: \n\n");
    scanf_s("%i%i%i", &number1, &number2, &number3);

    if (number1 % 2 == 0)
        printf("\nЧисло 1 четное.");
    else if (number2 % 2 == 0)
        printf("\nЧисло 2 четное.");
    else if (number3 % 2 == 0)
        printf("\nЧисло 3 четное.");
    else
        printf("\nВсе числа нечетные.\n");

    _getch();
}