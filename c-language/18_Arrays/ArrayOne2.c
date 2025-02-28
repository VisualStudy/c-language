//[?] 배열의 모든 요소를 0으로 초기화
#include <stdio.h>

int main(void)
{
    //[1] 1차원 배열 선언과 동시에 0으로 초기화
    int intArray[3] = { 0, };
    
    //[2] 배열 초기화
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;

    //[3] for 문 사용 출력
    for (int i = 0; i < 3; i++)
    {
        printf("%d번째 인덱스: %d\n", i, intArray[i]);
    }

    return 0;
}