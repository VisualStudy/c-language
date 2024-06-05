// function_demo.c
#include <stdio.h>

//[1] show 함수 선언
void show(void)
{
    printf("Hello World\n");
}

//[!] main 함수
int main(void)
{
    show(); //[2] show 함수 호출

    return 0;
}