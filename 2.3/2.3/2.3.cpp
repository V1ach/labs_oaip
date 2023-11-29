#include <stdlib.h>
#include <stdio.h>    
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>

#define VK_ESCAPE    27
#define VK_RETURN    13
#define VK_BACKSPACE  8
#define BUF_SIZE_U32 11

#define STR_MAXU32   "4294967295" // максимум unsigned 

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m" //цвета текста

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

int main(int argc, char** argv)
{
    system("chcp 65001 & cls");
    bool result;

    double sum = 1;
    int j, s;
    unsigned int radians;
    float rad, k = 2, factorial = 1, x = 1;

    printf("%s> Нахожение cosX  используя разложнение в ряд Тейлора.%s\n\n", YELLOW, RESET);

    while (result = try_input_u32(">> Введите десятичное целое без знака (ESC = выход): ", radians) == 1 && radians) 
    {
        rad = radians * 0.017545;
        for (j = 0; j < 3; j++)
        {
            factorial = 1;
            s = 1;
            for (s; s <= k; s++)
            {
                factorial = factorial * s;
            }
            if (j % 2 == 0)
            {
                sum = sum - (pow(rad, k) / factorial);
            }
            else
            {
                sum = sum + (pow(rad, k) / factorial);
            }
            k += 2;
        }
        printf("\n> Косинус X равен: %.2lf\n", sum);
        return 0;
    }
} 