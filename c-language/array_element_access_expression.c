#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};

    printf("== 배열 인덱스 방식 ==\n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\n== 포인터 연산 방식 ==\n");
    for (int i = 0; i < 5; i++)
    {
        printf("*(arr + %d) = %d\n", i, *(arr + i));
    }

    printf("\n== 특별한 표현도 가능 ==\n");
    printf("2[arr] = %d\n", 2[arr]); // arr[2]와 같음

    return 0;
}