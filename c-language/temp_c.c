#include <stdio.h>

// temp ������ �̿��� ���� �� ���� ���� ���� �ٲ㺸��!
int main(void)
{
    int a, b, temp;
    a = 1000;
    b = 10;
    // a = 1000, b = 10�̴�. �׷���, temp�� ���� ����Ͽ� a�� �Ļ���� ����!
    temp = b;
    b = a;
    a = temp;

    printf("���� a�� �Ļ�������: %d\n", a);
    if (a == 10)
    {
        printf("��ȣ! a �Ļ��Ű�� ����!\n");
    }
    else
    {
        printf("���� �߸��� �� �����ϴ�.\n");
    }
    if (b == 1000)
    {
        printf("���� b�� ���δ�!\n");
    }
    else
    {
        printf("���� �߸��� �� �����ϴ�. Somethings wrong!\n");
    }

    return 0;
}