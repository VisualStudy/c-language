#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int answer = 0;
    int _ = 0;
    printf("������ �Է��ϼ���.\n");

    // ���� �ϳ� �Է��ϰ� ���� �Է��� �� answer ������ ���
    _ = scanf("%d", &answer);

    // ���ù�
    switch (answer)
    {
        case 1:
            printf("1�� �����߽��ϴ�.\n");
            break;
        case 2:
            printf("2�� �����߽��ϴ�.\n");
        case 3:
            printf("3�� �����߽��ϴ�.\n");
            break;
        default:
            printf("�׳� �����̱���.\n");
            break;
    }

    return 0;
}