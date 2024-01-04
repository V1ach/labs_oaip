#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX_LENGTH 100 
#define MAX_SIZE 100

void task1();
void task2();
void task3();
int menu();
void RandomString(char* str, int length);

int main()
{
    while (1)
    {
        switch (menu()) 
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            break;
        }
        return 0;

    }
    _getch();
    return 0;
}

int menu() 
{
    int ch;
    do 
    {
        printf(">> Введите число, чтобы продолжить\n\n> Лабораторная 7\n> 1. Задание 1 (удаление лишних пробелов)\n> 2. Задание 2 (вставить первые символы)\n\n");
        printf("> Лабораторная 8\n> 3. Задание 1 (сортировка методом Хоара)\n\n> 4. Выход\n\n" );
        scanf("%d", &ch);
        getchar();
    } 
    while (ch < 1 || ch > 4);
    return ch;
}
int my_strlen(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void my_strcpy(char* dest, const char* src) 
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int my_strcmp(const char* str1, const char* str2) 
{
    while (*str1 != '\0' && *str2 != '\0') 
    {
        if (*str1 != *str2)
            return *str1 - *str2;
        str1++;
        str2++;
    }
    return 0;
}

void my_swap(char* a, char* b) 
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void task1() {
    int i, j;
    int spaceFlag = 0;
    char str[1000];

    int choice;
    printf(">> Выберите метод ввода:\n> 1. Ручной\n> 2. Случайный\n");
    scanf("%d", &choice);


    switch (choice)
    {
    case 1:
    {
        printf(">> Введите строку: ");
        getchar();
        fgets(str, sizeof(str), stdin);
        break;
    }
    case 2: 
    {
        srand(time(NULL));

        int length;
        printf(">> Введите длину случайной строки: ");
        scanf("%d", &length);

        if (length > 0 && length < MAX_LENGTH) 
        {
            char str[MAX_LENGTH];
            RandomString(str, length);
            printf("> Случайная строка: %s\n", str);
            int len = my_strlen(str);
            if (len > 0 && str[len - 1] == '\n')
                str[len - 1] = '\0';

            for (i = 0, j = 0; i < len; i++) 
            {
                if (str[i] == ' ') 
                {
                    if (!spaceFlag) 
                    {
                        str[j++] = ' ';
                        spaceFlag = 1;
                    }
                }
                else 
                {
                    str[j++] = str[i];
                    spaceFlag = 0;
                }
            }
            str[j] = '\0';
            printf("> Результат: %s\n", str);
        }
        break;
    }
    }

    int len = my_strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';


    for (i = 0, j = 0; i < len; i++) 
    {
        if (str[i] == ' ') 
        {
            if (!spaceFlag) 
            {
                str[j++] = ' ';
                spaceFlag = 1;
            }
        }
        else 
        {
            str[j++] = str[i];
            spaceFlag = 0;
        }
    }
    str[j] = '\0';
    printf("> Результат: %s\n", str);
}

void task2() 
{
    char S[1000];
    char S0[1000];
    int a, b;

    printf(">> Введите строку S1: ");
    fgets(S, sizeof(S), stdin);

    printf(">> Введите строку S2: ");
    fgets(S0, sizeof(S0), stdin);

    printf(">> Введите значение a (через): ");
    scanf("%d", &a, sizeof(a));

    printf(">> Введите значение b (сколько): ");
    scanf("%d", &b, sizeof(b));

    getchar();

    int len1 = my_strlen(S);
    int len2 = 0;

    while (len2 < b && S0[len2] != '\0')
        len2++;

    for (int i = len1; i >= a; i--)
        S[i + len2] = S[i];

    for (int i = 0; i < len2; i++)
        S[a + i] = S0[i];

    printf("> Результат: %s\n", S);
}

void task3() 
{
    int n;

    printf(">> Введите количество строк: ");
    scanf("%d", &n, sizeof(n));

    getchar();
    char** arr = (char**)malloc(n * sizeof(char*));
    char buffer[1000];


    for (int i = 0; i < n; i++) 
    {
        printf(">> Введите строку %d: ", i + 1);

        scanf(" %[^\n]s", buffer);

        arr[i] = (char*)malloc((my_strlen(buffer) + 1) * sizeof(char));
        my_strcpy(arr[i], buffer);
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (my_strlen(arr[j]) < my_strlen(arr[j + 1]))
            {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    printf("\n> Отсортированный массив строк по убыванию длины:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

void RandomString(char* str, int length)
{
    const char set[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < length - 1; ++i) 
    {
        int index = rand() % (sizeof(set) - 1);
        str[i] = set[index];
    }

    str[length - 1] = '\0';
}