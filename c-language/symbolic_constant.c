#include <stdio.h>

// ��ȣ ��� ����
#define STUDENT_COUNT 3 // �л� ���� ��Ÿ���� ��ȣ ���
#define SUBJECT_COUNT 2 // ���� ���� ��Ÿ���� ��ȣ ���
#define MAX STUDENT_COUNT // ��ȣ ��������� ġȯ ����

int main(void)
{
    int scores[MAX][SUBJECT_COUNT]; // 3���� �л�, 2���� ���� ������ �迭
    int student, subject;

    // ���� �Է�
    for (student = 0; student < MAX; student++)
    {
        printf("[%d��° �л� ���� �Է�]\n", student + 1);
        for (subject = 0; subject < SUBJECT_COUNT; subject++)
        {
            printf("���� %d ����: ", subject + 1);
            scanf("%d", &scores[student][subject]);
        }
    }

    // ���� ���
    for (student = 0; student < MAX; student++)
    {
        printf("[%d��° �л� ����] ", student + 1);
        for (subject - 0; subject < SUBJECT_COUNT; subject++)
        {
            printf("%d ", scores[student][subject]);
        }
        printf("\n");
    }

    return 0;
}