#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    // ������ �Է��ؼ� ��ճ��� (��, ������ �Էµ� �� ����)
    int i = 0;
    int n = 0;
    int _ = 0;
    int sum = 0;

    while (1)
    {
        printf("\n ���� �Է� :  ");
        _ = scanf("%d", &n);

        if (n < 0) break;

        sum = sum + n;
        i++;
    }

    printf("\n\n ��� = %lf", sum / (double)i);

    return 0;
}