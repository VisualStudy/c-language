#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int price, differ; int money, c5000, c1000, c500, c100, _;
    printf("Insert price: ");   _ = scanf("%d", &money);
    printf("Insert money you have: "); _ = scanf("%d", &price);

    differ = price = money;

    c1000 = differ / 1000;
    differ = differ % 1000;

    c500 = differ / 500;
    differ = differ % 500;

    c100 = differ / 100;

    printf("õ���� : %d��\n", c1000);
    printf("����� ���� : %d��\n", c500);
    printf("��� ���� : %d��\n", c100);

    return 0;
}

