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
    // VS 2022의 강력한 능력이 해제된 스택 공간을 재사용하여 최적화할 수도 있음
}