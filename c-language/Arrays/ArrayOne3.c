//[?] 배열을 선언과 동시에 초기화
#include <stdio.h>

int main(void)
{
    //[!] 1차원 배열 선언과 동시에 원하는 값으로 초기화
    int intArray[3] = { 100, 200, 300 };

    for (int i = 0; i < 3; i++)
    {
        printf("%d번째 인덱스: %d\n", i, intArray[i]);
    }

    return 0;
}