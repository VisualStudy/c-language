#include <stdio.h>

int main(void)
{
    int i = 3;
    //[1] 공문(Empty) : {}안에 아무런 구문이 없는 문장
    if (i % 2 == 0)
    {
        // Empty : 실행 안됨.
    }
    
    //[2] 단문(SingleLine) : {}안에 단일 문장(실행문)
    if (i % 3 == 0)
    {
        printf("3의 배수"); // 실행
    }
    
    if (i % 3 == 0) //단문일 경우만 {} 생략 가능
        printf("3의 배수");

    //[3] 복문(MultiLine) : {}안에 다중 문장
    if (i % 3 == 0)
    {
        printf("\n");
        printf("\n");
        // ; 불필요
    }

    return 0; // main 함수는 반드시 0을 반환해야 함
}