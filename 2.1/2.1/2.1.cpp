#include <stdlib.h>
#include <stdio.h>    
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define VK_ESCAPE    27
#define VK_RETURN    13
#define VK_BACKSPACE  8
#define BUF_SIZE_U32 11

#define STR_MAXU32   "4294967295" // максимум unsigned 

bool in_range(char* buff, const char* max)
{
    int lb = strlen(buff), lm = strlen(max);
    return (lb != lm) ? (lb < lm) : strcmp(max, buff) >= 0;
}

bool try_input_u32(const char* title, unsigned& value)
{
    char key, buffer[BUF_SIZE_U32] = { 0 };
    char* ptr = buffer;
    memset(buffer, 0, sizeof(buffer));

    do
    {
        printf("\r%s%s", title, buffer); // вывод на консоль того, что ввели
        key = _getch(); // жду нажатие клавиш

        // цифра (0...9). добавление к буферу справа и проверка диапазона
        if (key > 0x2F && key < 0x3A)
        {
            *ptr = key; // добавление к буферу справа
            if (in_range(buffer, STR_MAXU32)) ptr++; // проверка диапазона
            else *ptr = 0; // удаление (превышен диапазон)      
        }

        // забой символа (backspace)
        if (key == VK_BACKSPACE && ptr > buffer)
        {
            *--ptr = 0;
            printf("\b ");
        }

        // ввод (enter)
        if (key == VK_RETURN && strlen(buffer))
            return (sscanf_s(buffer, "%u", &value));
    } while (key != VK_ESCAPE);

    return false;
}

int main(int argc, char** argv) {
    system("chcp 65001 & cls");
    bool result;

    unsigned int n = 0, f = 0;
    while (result = try_input_u32(">> Введите десятичное целое без знака (ESC = выход): ", n) == 1 && n) {

        f = 1;

        for (; n > 1; --n)
            f *= n;

        printf("\n>> n! = %d\n", f);

        for (; n * (n + 1) * (n + 2) < f; ++n);

        if (n * (n + 1) * (n + 2) == f)
            printf(">> %d * %d * %d = %d\n\n", n, n + 1, n + 2, f);
        else
            printf(">> Данное число невозможно представить в виде произведения 3-х последовательных чисел.\n\n");
    }

    return 0;
}