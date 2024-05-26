#include <stdio.h>

int main(void)
{
    int _ = 0;
    int f = 0;
    int l = 0;
    int n = 0;
    int sum = 0;

    printf("초항 입력 :  ");
    _ = scanf("%d", &f);
    printf("말항 입력 :  ");
    _ = scanf("%d", &l);
    printf("항의 개수 입력 :  ");
    _ = scanf("%d", &n);

    sum = (n * ( f + l )) / 2;
    printf("등차수열 합 :  %d", sum);

    return 0;
}