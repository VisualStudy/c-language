#include <stdio.h>

int main(void)
{
    int x;
    x = 97;
    char y;
    y = 'a';
    int i;

    //char str[4] = {"a, b, c, \0"}; // 문자열은 char 배열로
    //char str[3] = {"abcdef"};      // 오버플로
    /*char str[4] = {"abc\0"};
    char str[4] = {"abc"};
    char str[7] = {"abcd e"};
    char str[100] = {"여유롭게 100 정도"};*/
    char str[] = {"라바라타 이스터페리움"}; // 파싱 과정에게 맡기기
    char ztr[100];

    for (i = 0; str[i] != '\0'; i++)
    {
        ztr[i] = str[i];
    }
    ztr[i] = '\0';
    printf("%s\n", ztr);

    printf("97을 문자로: %c\n", x);
    printf("문자 a를 숫자로: %d\n", y);
    
    return 0;
}