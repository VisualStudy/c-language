//[?] �迭�� ��� ��Ҹ� 0���� �ʱ�ȭ
#include <stdio.h>

int main(void)
{
    //[1] 1���� �迭 ����� ���ÿ� 0���� �ʱ�ȭ
    int intArray[3] = { 0, };
    
    //[2] �迭 �ʱ�ȭ
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;

    //[3] for �� ��� ���
    for (int i = 0; i < 3; i++)
    {
        printf("%d��° �ε���: %d\n", i, intArray[i]);
    }

    return 0;
}