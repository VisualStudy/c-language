// �迭 �̴ϼȶ����� ��
#include <stdio.h>

int main(void)
{
    int num = { 1234 }; // �迭 �̴ϼȶ�����(�ʱ���, �ʱ�ȭ��)

    double numbers[] = { 1234, 3.14 }; // �迭 �̴ϼȶ�����

    printf("%d\n", num);
    printf("%lf, %lf\n", numbers[0], numbers[1]); // 1234.000000, 3.140000

    return 0;
}