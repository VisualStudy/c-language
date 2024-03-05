#include <stdio.h>

int main(void)
{
    printf("%d\n", 1234);       //[1] 1234: int literal
    printf("%.2f\n", 3.14F);      //[2] 3.14: real number literal
    printf("%c\n", 'A');       //[3] A: letter literal
    printf("%s\n", "HELLO");   //[4] HELLO: string literal

    return 0;
}