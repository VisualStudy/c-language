#include <stdio.h>

int main(void)
{
    int kor[3];
    int sum = 0; // �հ谡 ��� ���� sum ����� ���ÿ� 0���� �ʱ�ȭ
    float avg = 0; // ����� ��� �Ǽ��� ���� avg ����� ���ÿ� 0���� �ʱ�ȭ

    // �迭�� ���۾����� ���� �� ����
    kor[0] = 100;
    kor[1] = 90;
    kor[2] = 80;

    sum = kor[0] + kor[1] + kor[2]; // ���� ���
    avg = sum / (float)3.0;         // ��� ���

    // ������ ��� ���: ����� �Ҽ��� 2�ڸ����� ���
    printf("����: %d, ���: %.2f\n", sum, avg);

    return 0;
}