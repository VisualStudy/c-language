#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    int _ = 0;
    int f = 0;
    int l = 0;
    int n = 0;
    int sum = 0;

    printf("���� �Է� :  ");
    _ = scanf("%d", &f);
    printf("���� �Է� :  ");
    _ = scanf("%d", &l);
    printf("���� ���� �Է� :  ");
    _ = scanf("%d", &n);

    sum = (n * ( f + l )) / 2;
    printf("\n\n�������� �� :  %d", sum);

    return 0;
}