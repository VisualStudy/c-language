//[?] 1차원 배열을 선언 및 초기화하는 프로그램
#include <stdio.h>

int main(void)
{
    //[1] 1차원 배열 선언
    int intArray[3];

    //[2] 배열 초기화
    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;

    //[3] for 문 사용 출력
    for (int i = 0; i < 3; i++)
    {
        printf("%d번째 인덱스: %d\n", i, intArray[i]);
    }

    return 0;
}