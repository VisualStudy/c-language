#include <stdio.h>

int main(void)
{
    int scores[5]; // �л� ������ ������ �迭
    int sum = 0;
    float average;

    // �迭 �Է� (�ܼ� �ݺ�)
    for (int i = 0; i < 5; i++)
    {
        printf("%d��° �л��� ���� �Է�: ", i + 1);
        scanf("%d", &scores[i]); // �迭 ��ҿ� �� ����
    }

    // �迭 ��� + �հ� ���
    for (int i = 0; i < 5; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
        sum += scores[i];
    }

    // ��� ���
    average = sum / 5.0;

    // ���
    printf("����: %d\n", sum);
    printf("���: %.2f\n", average);

    return 0;
}