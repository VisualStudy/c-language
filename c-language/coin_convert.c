#include <stdio.h>

int main(void)
{
    int money;

    printf("## ����� ��ȯ�� ���� ? ");
    scanf("%d", &money);

    int num50 = money / 50000;
    int num50_per = money % 50000;
    int num10 = num50_per / 10000;
    int num10_per = num50_per % 10000;
    int num5 = num10_per / 5000;
    int num5_per = num10_per % 5000;
    int num1 = num5_per / 1000;
    int num_ = num5_per % 1000;

    printf("\n���� ��¥�� => %d ��\n", num50);
    printf("�� ��¥�� => %d ��\n", num10);
    printf("��õ ��¥�� => %d ��\n", num5);
    printf("õ ��¥�� => %d ��", num1);
    printf("����� �ٲ��� ���� �ܵ� => %d ��", num_);

    return 0;
}