#include <stdio.h>

int MultiplyByTwo(int num);

int main(void)
{
    int x; // �ʱ�ȭ���� ������ �����Ⱚ!
    x = 5; // �Լ� ȣ�� �� �ݵ�� �ʱ�ȭ�ؾ� ��Ȯ�� ��� ����

    // �Լ� ȣ��: ���ǵ� MultiplyByTwo �Լ� ���
    int result = MultiplyByTwo(x); // �Ű� ������ x ���� ��, �Լ� �� num�� x�� ��. x = 5�̹Ƿ� num = 5

    printf("�Լ� ȣ�� ���: %d\n", result); // 10 ��� ����

    return 0;
}

// �Լ� ����
int MultiplyByTwo(int num)
{
    // �Ű����� num�� ȣ���� �� x�� ���纻�� �޴´�: 5 * 2
    return num * 2; // ��ȯ�� ����: ��ȯ�� int �����ϹǷ�..!
}