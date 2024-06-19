#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int arith_sum();

int arith_sum()
{
    int f, l, d, p, sum = 0;

    printf("초항 입력 : ");
    scanf("%d", &f);
    printf("말항 입력 : ");
    scanf("%d", &l);
    printf("등차 입력 : ");
    scanf("%d", &d);
    
    for (p = f; p <= l; p = p + d)
    {
        sum = sum + p;
    }
    return sum;
}

void main(void)
{
    int result = arith_sum();
    printf("결과 :  %d", result);
}