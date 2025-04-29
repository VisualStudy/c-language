#include <stdio.h>

int function_local(int i)
{
    printf("코레가 지역변수 데스: %d\n", i);
}

int main(void)
{
    int i = 100; // 메인 함수의 지역 변수 i는 100이란 값을 지님

    printf("디스 이스 메인즈 아이: %d\n", i);
    printf("벗...\n");
    function_local(10);

    return 0;
}