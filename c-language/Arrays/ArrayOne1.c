//[?] 1���� �迭�� ���� �� �ʱ�ȭ�ϴ� ���α׷�
#include <stdio.h>

int main(void)
{
    //[1] 1���� �迭 ����
    int intArray[3];

    //[2] �迭 �ʱ�ȭ
    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;

    //[3] for �� ��� ���
    for (int i = 0; i < 3; i++)
    {
        printf("%d��° �ε���: %d\n", i, intArray[i]);
    }

    return 0;
}