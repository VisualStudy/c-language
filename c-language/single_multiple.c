#include <stdio.h>

int main(void)
{
    // [1] �ܹ� ����: 3���� ��Ÿ��
    if (1 == 1) printf("�ܹ� 1\n");
    if (1 == 1)
        printf("�ܹ� 2\n");
    if (1 == 1)
    {
        printf("�ܹ� 3\n");
    }
    
    // [2] ���� ����: �߰�ȣ�� ����Ͽ� ���� ������ ����
    if (1 == 1)
    {
        printf("���� A\n");
        printf("���� B\n");
    }
    
    return 0;
}