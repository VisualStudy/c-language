// 3���� �л��� ������ �Է¹޾� ������ ���ϴ� ���α׷�
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 3���� ��Ҹ� ������ 1���� �迭 ����
    int students[3];
    char buffer[5];
    int total = 0;

    // ����ڷκ��� ���� ������ 3�� �Է¹޾� �迭�� ����
    for (int i = 0; i < 3; i++)
    {
        printf("%d�� �л� ����: ___\b\b\b", (i + 1));
        gets_s(buffer, sizeof(buffer)); // ����ں��� ���� �Է�
        students[i] = atoi(buffer); // �Էµ� ���� ������ ��ȯ
        total += students[i];
    }

    // ����ϱ�
    printf("\n����: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t", students[i]);
    }
    printf("\n����: %d\n", total);

    return 0;
}