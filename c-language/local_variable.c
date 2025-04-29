#include <stdio.h>

void PrintNumber(void);

int main(void)
{
    int num = 20; // main 함수의 지역 변수
    printf("main 안에서 num = %d\n", num);

    PrintNumber();

    printf("main 안에서 num = %d\n", num);

    return 0;
}

void PrintNumber(void)
{
    int num = 10;  // 지역 변수
    printf("print_number 안에서 num = %d\n", num);
}