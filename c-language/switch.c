// switch �� ����ϱ�
#include <stdio.h>

int main(void)
{
    int x = 2;

    switch (5)
    {
        case 1:
            printf("1�Դϴ�.\n"); // x�� 1�� �� ����
            break;
        case 2:
            printf("2�Դϴ�.\n"); // x�� 2�� �� ����
            break;
        case 3:
            printf("3�Դϴ�.\n"); // x�� 3�� �� ����
            break;
        default:
            printf("1�� 2�� 3�� �ƴմϴ�.\n"); // �⺻��
            break;
    }

    return 0;
}