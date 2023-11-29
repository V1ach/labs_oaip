#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    float edge = 0, volume = 0, lateralSurfaceArea = 0;

    printf("Введите ребро куба: ");
    scanf_s("%f", &edge);

    volume = pow(edge, 3);
    lateralSurfaceArea = 4 * pow(edge, 2);

    printf("%s%.3f%s%.3f%s", "\nОбъем куба равен: ", volume, "\nПлощадь боковой поверхности равна: ", lateralSurfaceArea,"\n");

    _getch();
}