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

    printf("���� �Է� : ");
    scanf("%d", &f);
    printf("���� �Է� : ");
    scanf("%d", &l);
    printf("���� �Է� : ");
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
    printf("��� :  %d", result);
}