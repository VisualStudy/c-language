#include <stdio.h>

void PrintLocal();

int main(void)
{
    PrintLocal();
    PrintLocal(); // 두 번째 호출 -> 지역 변수는 새로 생성됨

    return 0;
}

void PrintLocal()
{
    int local = 1; // 함수 호출 시마다 새로 생성됨
    printf("지역 변수 local의 값 = %d (주소: %p)\n", local, &local);
}