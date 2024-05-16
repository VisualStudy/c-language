#include <stdio.h>

int main(void)
{
    int i;

    // for 루프를 사용하여 1부터 10까지 반복
    for (i = 1; i <= 10; i++)
    {
        // if 문을 사용하여 홀수인 경우에만 출력
        if (i % 2 != 0)
        {
            printf("%d", i);
        }
    }

    printf("\n"); // for 루프 출력 후 줄 바꿈

    // while 루프를 사용하여 1부터 10까지 반복 (짝수만 출력)
    i = 1; // i를 1로 초기화
    while (i <= 10)
    {
        // if 문을 사용하여 짝수인 경우에만 출력
        if (i % 2 == 0)
        {
            printf("%d", i);
        }
        i++; // i를 증가시킴
    }

    printf("\n"); // while 루프 출력 후 줄 바꿈

    return 0;
}