#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    float a = 0, b = 0, c = 0, discriminant = 0;
    bool check = 0;

    printf("Решение неравенств типа: ax2+bx+c<0\n\n");

    printf("Введите коэффициенты a, b и c: \n");
    scanf_s("%f%f%f", &a, &b, &c);

    discriminant = b * b - 4 * a * c;
    float x = -b / (2 * a);
    float x1 = (-b - sqrt(discriminant)) / (2 * a);
    float x2 = (-b + sqrt(discriminant)) / (2 * a);

    if (a > 0) {
        printf("Ветви неравенства направлены вверх.\n");
        check = 1;
    }
    else if (a < 0) {
        printf("Ветви неравенства направлены вниз.\n");
        check = 0;
    }

    if (a == 0) {
        printf("Error: коэффициент А не может быть равен 0!\n");
    }
    else if (discriminant > 0 && check == 1) {
        printf("Неравенство имеет решение: от %f и до %f.\n", x1, x2);
    }
    else if (discriminant > 0 && check == 0) {
        printf("Неравенство имеет решение: от -∞ до %f и от %f до +∞.\n", x1, x2);
    }
    else if (discriminant == 0 && check == 0) {
        printf("Неравенство имеет решение: от -∞ до %f и от %f до +∞.\n", x, x);
    }
    else {
        printf("Неравенство не имеет решения.\n");
    }
    _getch();
}