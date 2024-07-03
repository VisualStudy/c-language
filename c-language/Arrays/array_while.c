// 배열의 값들을 while 문을 사용하여 반복적으로 출력하는 예제
#include <stdio.h>

int main(void)
{
    char see[] = "C language\n"; // 문자 배열 선언 및 초기화

    int index = 0; // 인덱스 변수 초기화
    while (see[index]); // 현재 인덱스의 문자 출력
    {
        putchar(see[index]); // 현재 인덱스의 문자 출력
        index++; // 인덱스 증가
    }

    return 0;
}