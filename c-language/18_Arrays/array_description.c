//[?] 1���� �迭 �����
#include <stdio.h>

int main(void)
{
    //[1] �迭 ����: ũ�Ⱑ 2�� �迭�� �����մϴ�.
    int numbers[2];

    //[2] �迭 �ʱ�ȭ: �迭�� ���� �Ҵ��մϴ�.
    numbers[0] = 3840;
    numbers[1] = 2160;

    //[3] �迭 ���: �迭�� ����� ���� ����մϴ�.
    printf("%d * %d\n", numbers[0], numbers[1]);

    return 0;
}