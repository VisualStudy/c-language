#include <stdio.h>

// 함수 선언 ("함수 원형"이라고도 함. prototype)
int add(int a, int b); // 세미콜론 존재

int main(void)
{
    int result = add(3, 7); // 함수 호출 후 반환값을 정수형 변수 result에 저장
    printf("%d\n", result);

    return 0;
}

// 함수 정의 (함수 몸체: body)
int add(int a, int b)
{
    return a + b;
}

// 함수 정의는 함수 선언이 없을 경우 메인 함수 위에서 존재 가능