#include <stdio.h>

int main() 
{
    int rows = 10;    // ���� ũ��
    int cols = 50;    // ���� ũ��

// �簢���� ����ϴ� ���� for��
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("*");
        }
        printf("\n"); // �� ���� ������ �ٹٲ�
    }

    return 0;
}
