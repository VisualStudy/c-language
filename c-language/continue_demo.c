// continue��: �ݺ������� �Ʒ� ���๮�� �������� �ʰ� ���� �������� �̵�
#include <stdio.h>

int main(void)
{
    int sum = 0;

    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0)
        {
            continue; // 3�� ����̸� [i++] �ڵ� �������� �̵��ϱ�
        }
        sum += i;
    }

    printf("SUM: %d\n", sum);

    return 0;
}