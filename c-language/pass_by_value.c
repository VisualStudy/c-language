#include <stdio.h>

void Increase(int counter)
{
    counter++;
    printf("�Լ� ����: counter = %d\n", counter);
}

int main(void)
{
    int i = 10; // RAM�� i��� �̸��� ����, �ʱⰪ 10
    Increase(i); // i�� ���� ����Ǿ� ���޵�. ��, counter�� i ����
    printf("�Լ� ���� ��: i = %d\n", i); // i�� ������ 10. ���� X
    return 0;
}

// pass by value �� ����: ������ ���� �����ؼ� �Լ��� ����

// ���� ���� �����̶�, �Լ��� ȣ���� �� ���� ������ ���� �����ؼ� �Լ��� �Ű������� �ѱ�� ����̴�.
// �Լ� ���ο����� ����� ���� ���Ǹ�, ���� �������� ������ ���� �ʴ´�.