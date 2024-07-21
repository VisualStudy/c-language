#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������ �� ����
#define TOTAL_QUESTIONS 10

typedef struct 
{
    char question[100];
    char options[4][20];
    int correct_option;
} Question;

void shuffle(int* array, int n) 
{
    if (n > 1) {
        srand(time(NULL));
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void ask_questions(Question questions[]) 
{
    int order[TOTAL_QUESTIONS];
    for (int i = 0; i < TOTAL_QUESTIONS; i++) 
    {
        order[i] = i;
    }

    int score = 0;

    while (1) 
    {
        shuffle(order, TOTAL_QUESTIONS);
        for (int i = 0; i < TOTAL_QUESTIONS; i++) 
        {
            int question_index = order[i];
            int a;

            printf("%s\n", questions[question_index].question);
            for (int j = 0; j < 4; j++) 
            {
                printf("%d) %s ", j + 1, questions[question_index].options[j]);
            }
            printf("\n");
            scanf("%d", &a);

            if (a == questions[question_index].correct_option) 
            {
                printf("����! 10���� ȹ���Ͽ����ϴ�.\n\n");
                score += 10;
            }
            else {
                printf("����! �ٽ� �����غ�����.\n");
                if (score == 0) 
                {
                    printf("������ 0���̹Ƿ� ��� ������ �������� ���ġ�Ͽ� �ٽ� �����մϴ�.\n\n\n");
                    i = -1;  // ������ ó������ �ٽ� ����
                    break;
                }
                else 
                {
                    score = 0;  // ���� �ʱ�ȭ
                    printf("������ �ʱ�ȭ�Ǿ����ϴ�. ó������ �ٽ� �����մϴ�.\n\n");
                    i = TOTAL_QUESTIONS; // ���� ���� ����
                    break;
                }
            }
        }

        if (score == 100) 
        {
            printf("��� ������ ���߼̽��ϴ�! ���� �Ǹ��մϴ�! ���α׷��� �����մϴ�.\n");
            break;
        }
        else if (i == TOTAL_QUESTIONS) 
        {
            if (score >= 80) 
            {
                printf("�Ǹ��մϴ�! ������ �� �й��ϼ���. ���α׷��� �����մϴ�.\n");
            }
            else if (score >= 60) 
            {
                printf("����ϼ̽��ϴ�. ������ �� ����ϼ���. ���α׷��� �����մϴ�.\n");
            }
            else 
            {
                printf("�����մϴ�. �ٽ� �����ϼ���. ���α׷��� �����մϴ�.\n");
            }
            break;
        }
    }
}

int main(void) {
    Question questions[TOTAL_QUESTIONS] = 
    {
        {"���� �� �������� ������ �ƴ� ����?", {"����", "�丶��", "����", "��ٺ�"}, 4},
        {"���� �� �������� �ƴ� ����?", {"�����", "���", "���", "�ڳ���"}, 2},
        {"���� �� ����� �ƴ� ����?", {"������ī", "�ƽþ�", "����", "�Ͽ���"}, 4},
        {"���� �� �ѱ��� ������?", {"����", "�λ�", "����", "��õ"}, 1},
        {"���� �� �ٴٿ� ������ �ʴ� ����?", {"�����", "�뼭��", "����", "�Ƹ�����"}, 4},
        {"���� �� �Ϻ��� ������?", {"����ī", "����", "����", "������"}, 3},
        {"���� �� �¾���� �༺�� �ƴ� ����?", {"����", "ȭ��", "��", "��"}, 4},
        {"���� �� �ѱ��� ���� ������ �ƴ� ����?", {"��ġ", "�Ұ��", "�ʹ�", "�����"}, 3},
        {"���� �� �ε��� ������?", {"������", "����", "�������", "þ����"}, 2},
        {"���� �� �̱��� ������?", {"����", "�ν���������", "��ī��", "������ D.C."}, 4}
    };

    printf("������ �����մϴ�.\n\n");
    ask_questions(questions);

    return 0;
}
