#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

// ������ �� ����
#define TOTAL_QUESTIONS 10

typedef struct {
    char question[100];
    char options[10][20];
    int correct_option;
} Question;

void shuffle(int* array, int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void ask_questions(Question questions[]) {
    int order[TOTAL_QUESTIONS];
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        order[i] = i;
    }

    int score = 0;

    while (1) {
        shuffle(order, TOTAL_QUESTIONS);
        for (int i = 0; i < TOTAL_QUESTIONS; i++) {
            int question_index = order[i];
            int a;

            printf("%s\n", questions[question_index].question);
            for (int j = 0; j < 10; j++) {
                printf("%d) %s ", j + 1, questions[question_index].options[j]);
            }
            printf("\n");

            while (1) {
                if (scanf("%d", &a) != 1) {
                    printf("�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�.\n");
                    return;
                }
                if (a < 1 || a > 10) {
                    printf("�߸��� �Է��Դϴ�. 1���� 10 ������ ���ڸ� �Է����ּ���.\n");
                    while (getchar() != '\n'); // ���� ����
                }
                else {
                    break;
                }
            }

            if (a == questions[question_index].correct_option) {
                printf("����! 10���� ȹ���Ͽ����ϴ�.\n\n");
                score += 10;
            }
            else {
                printf("����! �ٽ� �����غ�����.\n\n");
            }
        }

        if (score == 100) {
            printf("��� ������ ���߼̽��ϴ�! ���� �Ǹ��մϴ�! �� ����: %d��. ���α׷��� �����մϴ�.\n", score);
            break;
        }
        else if (score >= 80) {
            printf("�Ǹ��մϴ�! ������ �������� �� ���� ������ �޵��� ����ϼ���. �� ����: %d��. ���α׷��� �����մϴ�.\n", score);
            break;
        }
        else if (score >= 60) {
            printf("����� �ʿ��մϴ�. �� ����: %d��. ���α׷��� �����մϴ�.\n", score);
            break;
        }
        else {
            printf("�����մϴ�. �ٽ� �����ϼ���. �� ����: %d��. ��� ������ �������� ���ġ�Ͽ� �ٽ� �����մϴ�.\n\n", score);
            score = 0;  // ���� �ʱ�ȭ
        }
    }
}

int main(void) {
    srand(time(NULL));  // ���� �ʱ�ȭ�� main �Լ����� �� ���� ȣ���մϴ�.

    Question questions[TOTAL_QUESTIONS] = {
        {"���� �� �������� ������ �ƴ� ����?", {"����", "�丶��", "����", "��ٺ�", "���", "����", "�ٳ���", "���", "����", "���ξ���"}, 4},
        {"���� �� �������� �ƴ� ����?", {"�����", "���", "���", "�ڳ���", "��", "����", "��", "ȣ����", "�⸰", "����"}, 2},
        {"���� �� ����� �ƴ� ����?", {"������ī", "�ƽþ�", "����", "�Ͽ���", "�ϾƸ޸�ī", "���Ƹ޸�ī", "�����ƴϾ�", "����", "������", "������"}, 4},
        {"���� �� �ѱ��� ������?", {"����", "�λ�", "����", "��õ", "����", "�뱸", "���", "����", "û��", "����"}, 1},
        {"���� �� �ٴٿ� ������ �ʴ� ����?", {"�����", "�뼭��", "����", "�Ƹ�����", "�ε���", "�ϱ���", "ī������", "ȫ��", "��Ʈ��", "������"}, 4},
        {"���� �� �Ϻ��� ������?", {"����ī", "����", "����", "������", "�����", "���νø�", "�����ī", "��", "������", "�����ϸ�"}, 3},
        {"���� �� �¾���� �༺�� �ƴ� ����?", {"����", "ȭ��", "��", "��", "�ݼ�", "����", "õ�ռ�", "�ؿռ�", "��ռ�", "�¾�"}, 4},
        {"���� �� �ѱ��� ���� ������ �ƴ� ����?", {"��ġ", "�Ұ��", "�ʹ�", "�����", "����", "����", "�����", "�����", "�ҳ�����", "���κ��"}, 3},
        {"���� �� �ε��� ������?", {"������", "����", "�������", "þ����", "��īŸ", "Ǫ��", "�Ƹ��ٹٵ�", "����Ʈ", "����Ǫ��", "��ũ����"}, 2},
        {"���� �� �̱��� ������?", {"����", "�ν���������", "��ī��", "������ D.C.", "�޽���", "�ʶ��Ǿ�", "�Ǵн�", "������Ͽ�", "���𿡰�", "���"}, 4}
    };

    printf("������ �����մϴ�.\n\n");
    ask_questions(questions);

    return 0;
}
