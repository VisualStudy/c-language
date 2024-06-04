#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    int _ = 0;
    int i = 0;
    int sum = 0;

    printf("<2·Î ³ª´« ¸ò ±¸ÇÏ±â> °ª ÀÔ·Â :  ");
    _ = scanf("%d", &i);

    sum = i / 2;
    printf("\n%d", sum);

    return 0;
}