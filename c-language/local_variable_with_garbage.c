#include <stdio.h>

void ShowGarbage()
{
    int x; // 초기화하지 않은 showGarbage 함수 안 지역 변수
    printf("초기화되지 않은 지역 변수 x의 값: %d\n", x);
}

int main(void)
{
    ShowGarbage();
    return 0;
}