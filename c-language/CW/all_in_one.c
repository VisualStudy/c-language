#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arith_sum()
{
    int _, f, l, d, p, sum = 0;
    
    printf("���� �Է� : ");
    _ = scanf("%d", &f);

    printf("���� �Է� :  ");
    _ = scanf("%d", &l);

    printf("���� �Է� :  ");
    _ = scanf("%d", &d);

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
