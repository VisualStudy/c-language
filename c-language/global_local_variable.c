#include <stdio.h>

int Global = 100; // 전역 변수

void TestScope()
{
    int Local = 50; // TestScope 함수 내 지역 변수
    printf("TestScope 함수 내:\n");
    printf("전역 변수 Global = %d \n", Global);
    printf("지역 변수 Local = %d \n", Local);
}

int main(void)
{
    int Local = 10; //메인 함수의 지역 변수
    printf("메인 함수 내: \n");
    printf("전역 변수 Global = %d \n", Global);
    printf("지역 변수 Local = %d \n", Local);

    TestScope();

    return 0;
}