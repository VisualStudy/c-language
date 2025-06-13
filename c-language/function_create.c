#include <stdio.h>

int MultiplyByTwo(int num);

int main(void)
{
    int x; // 초기화하지 않으면 쓰레기값!
    x = 5; // 함수 호출 전 반드시 초기화해야 정확한 결과 얻음

    // 함수 호출: 정의된 MultiplyByTwo 함수 사용
    int result = MultiplyByTwo(x); // 매개 변수에 x 대입 즉, 함수 안 num은 x가 됨. x = 5이므로 num = 5

    printf("함수 호출 결과: %d\n", result); // 10 출력 예상

    return 0;
}

// 함수 정의
int MultiplyByTwo(int num)
{
    // 매개변수 num은 호출할 때 x의 복사본을 받는다: 5 * 2
    return num * 2; // 반환값 존재: 반환형 int 존재하므로..!
}