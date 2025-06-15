#include <stdio.h>

int main(void)
{
    int x = 97;
    int y = 65;
    int z = x - y; // 소문자와 대문자 차이

    printf("%c\n", x);
    printf("%d\n", x);
    printf("%c\n", y);
    printf("%d\n", y);
    printf("\n===============\n\n");
    printf("%c\n", x - z);
    printf("%c\n", y + z);


    return 0;
}