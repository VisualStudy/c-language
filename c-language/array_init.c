#include <stdio.h>

int main(void)
{
    //[1] ��� �ʱ�ȭ
    int all[5] = { 1,2,3,4,5 };
    //[2] ������ 0���� �ʱ�ȭ
    int zero[5] = { 1,2 /* ������ ��� 0���� �ʱ�ȭ */};

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