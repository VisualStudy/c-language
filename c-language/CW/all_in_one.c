#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arith_sum()
{
    int _, f, l, d, p, sum = 0;
    
    printf("초항 입력 : ");
    _ = scanf("%d", &f);

    printf("말항 입력 :  ");
    _ = scanf("%d", &l);

    printf("등차 입력 :  ");
    _ = scanf("%d", &d);

    for (p = f; p <= l; p = p + d)
    {
        sum = sum + p;
    }

    printf("초항부터 말항까지 합 :  %d", sum);
}

int main(void)
{
    arith_sum();
}
