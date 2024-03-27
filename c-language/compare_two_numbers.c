#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    int _ = 0;

    printf("first num:  "); _ = scanf("%d", &num1);
    printf("second num:  "); _ = scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("%d > %d.\n", num1, num2);
    }
    else if (num1 < num2)
    {
        printf("%d < %d.\n", num1, num2);
    }
    else
    {
        printf("%d = %d.\n", num1, num2);
    }
    
    return 0;
}