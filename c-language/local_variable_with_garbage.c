#include <stdio.h>

void ShowGarbage();

int main(void)
{
    ShowGarbage();
    return 0;
}

void ShowGarbage()
{
    int x; // 초기화하지 않은 ShowGarbage 함수 안 지역 변수
    printf("초기화되지 않은 지역 변수 x의 값: %d\n", x);
}