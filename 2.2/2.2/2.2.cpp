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

int value = 0;

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

    unsigned int s[3], p[3], i = 0, j = 0;
    while (result = try_input_u32(">> Введите десятичное целое без знака (ESC = выход): ", i) == 1 && i)
    {

        s[0] = s[1] = s[2] = 0;
        p[0] = p[1] = p[2] = 1;
        printf("\n>> %sЧисла: %s", RED, RESET);

        for (j = 1; j <= i; j++)
        {
            printf("%d ", j * j * j);
            if (j % 2)
            {
                s[0] += j * j * j;
                p[0] *= j * j * j;
            }
            if (j % 2 == 0)
            {
                s[1] += j * j * j;
                p[1] *= j * j * j;
            }
        }
        printf("\n\n> Сумма нечетных = %d \n> Произведение нечетных = %d", s[0], p[0]);
        printf("\n> Сумма четных = %d \n> Произведение четных = %d\n\n", s[1], p[1]);
    }
}