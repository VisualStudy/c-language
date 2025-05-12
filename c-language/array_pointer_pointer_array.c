#include <stdio.h>   

int main(void)   //말장난 파트: 포인터 배열 vs 배열 포인터
{
    // 포인터 배열: int* 3개짜리 배열
    int a = 10;
    int b = 20;
    int c = 30;
    int *parr[3] = {&a, &b, &c};

    printf ("== 포인터 배열 (int *arr[3] ==\n");
    for (int i = 0; i < 3; i++)
    {
        printf("parr[%d] points to value: %d\n", i, *parr[i]);
    }

    // 배열 포인터: int [3] 배열을 가리키는 포인터
    int arr[3] = {100, 200, 300};
    int (*p)[3] = &arr;

    printf("\n== 배열 포인터 (int (*p)[3]) ==\n");
    for (int i = 0; i < 3; i++)
    {
        printf("(*p)[%d] = %d\n", i, (*p)[i]);
    }

    return 0;
}