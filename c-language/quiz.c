#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 문제의 총 개수
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
                printf("정답! 다음 문제로 넘어갑니다.\n\n");
                break;
            }
            else {
                printf("오답! 다시 생각해보세요.\n");
                i = -1;  // 문제를 처음부터 다시 시작
                break;
            }
        }
    }
}

int main(void) {
    Question questions[TOTAL_QUESTIONS] = {
        {"다음 중 생물학적 과일이 아닌 것은?", {"수박", "토마토", "오이", "루바브"}, 4},
        {"다음 중 포유류가 아닌 것은?", {"고양이", "상어", "사람", "코끼리"}, 2},
        {"다음 중 대륙이 아닌 것은?", {"아프리카", "아시아", "유럽", "하와이"}, 4},
        {"다음 중 한국의 수도는?", {"서울", "부산", "대전", "인천"}, 1},
        {"다음 중 바다에 속하지 않는 것은?", {"태평양", "대서양", "흑해", "아마존강"}, 4}
    };

    printf("문제를 시작합니다.\n\n");
    ask_questions(questions);

    printf("모든 문제를 맞췄습니다! 프로그램을 종료합니다.\n");
    return 0;
}
