#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arith_sum()
{
    int f, l, d, p, sum = 0;
    
    printf("���� �Է� : ");
    scanf("%d", &f);

    printf("���� �Է� :  ");
    scanf("%d", &l);

    printf("���� �Է� :  ");
    scanf("%d", &d);

    for (p = f; p <= l; p = p + d)
    {
        sum = sum + p;
    }

    printf("���׺��� ���ױ��� �� :  %d", sum);
}

int main(void)
{
    arith_sum();
}
