#include <stdio.h>

int main(void)
{
    int scores[5]; // 5���� ������ ������ �迭
    int i, sum = 0;

    // ���� �Է� �ޱ�
    printf("�л� 5���� ������ �Է��ϼ���:\n");
    for ( i = 0; i < 5; i++)
    {
        printf("�л� %d�� ����: ", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }

    // ��� ��� �� ���
    float average = (float)sum / 5;
    printf("��ü �л��� ��� ����: %.2f\n", average);

    return 0;
}