#include <stdio.h>

int main(void)
{
    int x;
    x = 97;
    
    char y;
    y = 'a';

    char str[4] = {"a, b, c, \0"}; // 문자열은 char 배열로
    char str[3] = {"abcdef"};      // 오버플로
    char str[4] = {"abc\0"};
    char str[4] = {"abc"};

    printf("97을 문자로: %c\n", x);
    printf("문자 a를 숫자로: %d\n", y);

    return 0;
}