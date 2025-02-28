//[?] 1차원 배열 만들기
#include <stdio.h>

int main(void)
{
    //[1] 배열 선언: 크기가 2인 배열을 선언합니다.
    int numbers[2];

    //[2] 배열 초기화: 배열에 값을 할당합니다.
    numbers[0] = 3840;
    numbers[1] = 2160;

    //[3] 배열 사용: 배열에 저장된 값을 사용합니다.
    printf("%d * %d\n", numbers[0], numbers[1]);

    return 0;
}