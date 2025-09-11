#include <stdio.h>

int main(void)
{
    int x;
    x = 97;
    
    char y;
    y = 'a';

    int str[4] = {"a, b, c, \0"};

    printf("97을 문자로: %c\n", x);
    printf("문자 a를 숫자로: %d\n", y);

    return 0;
}