#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "russian");

    int k = 0, a, b, c;

    printf("Введите первое число\n");
    scanf_s("%d", &a);
    printf("Введите второе число\n");
    scanf_s("%d", &b);
    printf("Введите третье число\n");
    scanf_s("%d", &c);

    switch (k)
    {
    case 1:
        if (a = -b);
        printf("a и b взаимно противоположные\n");
        break;

    case 2:
        if (a = -c);
        printf("a и c взаимно противоположные\n");
        break;

    case 3:
        if (b = -a);
        printf("a и b взаимно противоположные\n");
        break;

    case 4:
        if (b = -c);
        printf("b и c взаимно противоположные\n");
        break;

    case 5:
        if (c = -a);
        printf("a и c взаимно противоположные\n");
        break;

    case 6:
        if (c = -b);
        printf("a и c взаимно противоположные\n");
        break;

    default:
        printf("Ни одна из пар не является взаимно противоположной\n");
    }
}