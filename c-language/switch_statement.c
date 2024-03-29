#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int choice = 0;
    int _ = 0;

    printf("가장 좋아하는 프로그래밍 언어는?\n");
    printf("1. C\t");
    printf("2. C++\t");
    printf("3. C#\t");
    printf("4. Java\n");

    _ = scanf("%d", &choice); _ = getchar();

    switch (choice)
    {
        case 1:
            printf("C language\n");
            break;
        case 2:
            printf("Cpp\n");
            break;
        case 3:
            printf("C#\n");
            break;
        case 4:
            printf("Java\n");
            break;
        default:
            printf("Python\n");
            break;
    }

    return 0;
}