#include <stdio.h>

int value = 100; // 전역 변수

void ShowValue()
{
    int value = 50; // 지역 변수 (이름이 전역 변수와 같음)
    printf("함수 내부에서 value = %d\n", value); // 지역 변수가 출력됨
}

int main(void)
{
    ShowValue();
    // 만약 메인 함수 안에 지역 변수 value를 추가한다면 지역 변수가 승. 그러나 지금은 변수가 없으므로 전역 변수가 출력됨.
    printf("main에서 전역 변수 value = %d\n", value); //전역 변수 출력

    return 0;
}