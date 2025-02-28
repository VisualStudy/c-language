#include <stdio.h>

int main(void)
{
    //[1] 모두 초기화
    int all[5] = { 1,2,3,4,5 };
    //[2] 나머지 0으로 초기화
    int zero[5] = { 1,2 /* 나머지 요소 0으로 초기화 */};

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", all[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", zero[i]);
    }
    printf("\n");

    return 0;
}