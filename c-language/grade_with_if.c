#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)   // ���� if, else if, else���� ����Ͽ� ���� ����ϱ�
{
    int score;
    int _;
    printf("���� �Է�: ");
    _ = scanf("%d", &score);
    if (score >= 90)
    {
        printf("A\n");
    }
    else if (score >= 80)
    {
        printf("B\n");
    }
    else if (score >= 70)
    {
        printf("C\n");
    }
    else if (score >= 60)
    {
        printf("D\n");
    }
    else
    {
        printf("F\n");
    }

    return 0;
}