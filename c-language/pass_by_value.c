#include <stdio.h>

void Increase(int counter)
{
    counter++;
    printf("함수 내부: counter = %d\n", counter);
}

int main(void)
{
    int i = 10; // RAM에 i라는 이름의 변수, 초기값 10
    Increase(i); // i의 값만 복사되어 전달됨. 즉, counter에 i 복사
    printf("함수 종료 후: i = %d\n", i); // i는 여전히 10. 변경 X
    return 0;
}

// pass by value 값 전달: 변수의 값만 복사해서 함수로 전달

// 값에 의한 전달이란, 함수를 호출할 때 원본 변수의 값을 복사해서 함수의 매개변수에 넘기는 방식이다.
// 함수 내부에서는 복사된 값만 사용되며, 원래 변수에는 영향을 주지 않는다.