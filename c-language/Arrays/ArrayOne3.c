//[?] �迭�� ����� ���ÿ� �ʱ�ȭ
#include <stdio.h>

int main(void)
{
    //[!] 1���� �迭 ����� ���ÿ� ���ϴ� ������ �ʱ�ȭ
    int intArray[3] = { 100, 200, 300 };

    for (int i = 0; i < 3; i++)
    {
        printf("%d��° �ε���: %d\n", i, intArray[i]);
    }

    return 0;
}