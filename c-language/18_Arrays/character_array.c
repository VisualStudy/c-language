#include <stdio.h>

int main(void)
{
    char characters[] = { 'a','b','c','d','\0' }; // 문자 배열
    puts(characters); // null 종결 문자를 포함한 문자 배열 출력

    return 0;
}