#include <stdio.h>

int main(void)
{
    int i = 3;
    //[1] ����(Empty) : {}�ȿ� �ƹ��� ������ ���� ����
    if (i % 2 == 0)
    {
        // Empty : ���� �ȵ�.
    }
    
    //[2] �ܹ�(SingleLine) : {}�ȿ� ���� ����(���๮)
    if (i % 3 == 0)
    {
        printf("3�� ���"); // ����
    }
    
    if (i % 3 == 0) //�ܹ��� ��츸 {} ���� ����
        printf("3�� ���");

    //[3] ����(MultiLine) : {}�ȿ� ���� ����
    if (i % 3 == 0)
    {
        printf("\n");
        printf("\n");
        // ; ���ʿ�
    }

    return 0; // main �Լ��� �ݵ�� 0�� ��ȯ�ؾ� ��
}