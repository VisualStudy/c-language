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