#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������ �� ����
#define TOTAL_QUESTIONS 5

typedef struct {
    char question[100];
    char options[4][20];
    int correct_option;
} Question;

void shuffle(int* array, int n) {
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

void ask_questions(Question questions[]) {
    int order[TOTAL_QUESTIONS] = { 0, 1, 2, 3, 4 };
    shuffle(order, TOTAL_QUESTIONS);

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        int question_index = order[i];
        int a;

        while (1) {
            printf("%s\n", questions[question_index].question);
            for (int j = 0; j < 4; j++) {
                printf("%d) %s ", j + 1, questions[question_index].options[j]);
            }
            printf("\n");
            scanf("%d", &a);

            if (a == questions[question_index].correct_option) {
                printf("����! ���� ������ �Ѿ�ϴ�.\n\n");
                break;
            }
            else {
                printf("����! �ٽ� �����غ�����.\n");
                i = -1;  // ������ ó������ �ٽ� ����
                break;
            }
        }
    }
}

int main(void) {
    Question questions[TOTAL_QUESTIONS] = {
        {"���� �� �������� ������ �ƴ� ����?", {"����", "�丶��", "����", "��ٺ�"}, 4},
        {"���� �� �������� �ƴ� ����?", {"�����", "���", "���", "�ڳ���"}, 2},
        {"���� �� ����� �ƴ� ����?", {"������ī", "�ƽþ�", "����", "�Ͽ���"}, 4},
        {"���� �� �ѱ��� ������?", {"����", "�λ�", "����", "��õ"}, 1},
        {"���� �� �ٴٿ� ������ �ʴ� ����?", {"�����", "�뼭��", "����", "�Ƹ�����"}, 4}
    };

    printf("������ �����մϴ�.\n\n");
    ask_questions(questions);

    printf("��� ������ ������ϴ�! ���α׷��� �����մϴ�.\n");
    return 0;
}
