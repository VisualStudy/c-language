#include <stdio.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int b[5];

    // 배열 a의 값을 배열 b에 복사
    for (int i = 0; i < 5; i++)
    {
        b[i] = a[i]; // 올바른 방향: b <- a
    }

    // 결과 출력
    printf("배열 b의 내용: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}