#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

// 문제의 총 개수
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
                    printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
                    return;
                }
                if (a < 1 || a > 10) {
                    printf("잘못된 입력입니다. 1부터 10 사이의 숫자를 입력해주세요.\n");
                    while (getchar() != '\n'); // 버퍼 비우기
                }
                else {
                    break;
                }
            }

            if (a == questions[question_index].correct_option) {
                printf("정답! 10점을 획득하였습니다.\n\n");
                score += 10;
            }
            else {
                printf("오답! 다시 생각해보세요.\n\n");
            }
        }

        if (score == 100) {
            printf("모든 문제를 맞추셨습니다! 정말 훌륭합니다! 총 점수: %d점. 프로그램을 종료합니다.\n", score);
            break;
        }
        else if (score >= 80) {
            printf("훌륭합니다! 하지만 다음에는 더 좋은 점수를 받도록 노력하세요. 총 점수: %d점. 프로그램을 종료합니다.\n", score);
            break;
        }
        else if (score >= 60) {
            printf("노력이 필요합니다. 총 점수: %d점. 프로그램을 종료합니다.\n", score);
            break;
        }
        else {
            printf("부족합니다. 다시 도전하세요. 총 점수: %d점. 모든 문제를 랜덤으로 재배치하여 다시 시작합니다.\n\n", score);
            score = 0;  // 점수 초기화
        }
    }
}

int main(void) {
    srand(time(NULL));  // 랜덤 초기화는 main 함수에서 한 번만 호출합니다.

    Question questions[TOTAL_QUESTIONS] = {
        {"다음 중 생물학적 과일이 아닌 것은?", {"수박", "토마토", "오이", "루바브", "사과", "포도", "바나나", "멜론", "딸기", "파인애플"}, 4},
        {"다음 중 포유류가 아닌 것은?", {"고양이", "상어", "사람", "코끼리", "개", "돼지", "말", "호랑이", "기린", "고릴라"}, 2},
        {"다음 중 대륙이 아닌 것은?", {"아프리카", "아시아", "유럽", "하와이", "북아메리카", "남아메리카", "오세아니아", "남극", "서유럽", "동유럽"}, 4},
        {"다음 중 한국의 수도는?", {"서울", "부산", "대전", "인천", "광주", "대구", "울산", "수원", "청주", "전주"}, 1},
        {"다음 중 바다에 속하지 않는 것은?", {"태평양", "대서양", "흑해", "아마존강", "인도양", "북극해", "카리브해", "홍해", "발트해", "남극해"}, 4},
        {"다음 중 일본의 수도는?", {"오사카", "교토", "도쿄", "삿포로", "나고야", "히로시마", "후쿠오카", "고베", "센다이", "요코하마"}, 3},
        {"다음 중 태양계의 행성이 아닌 것은?", {"지구", "화성", "목성", "달", "금성", "수성", "천왕성", "해왕성", "명왕성", "태양"}, 4},
        {"다음 중 한국의 전통 음식이 아닌 것은?", {"김치", "불고기", "초밥", "비빔밥", "떡국", "갈비", "된장찌개", "삼계탕", "불낙전골", "순두부찌개"}, 3},
        {"다음 중 인도의 수도는?", {"뭄바이", "델리", "벵갈루루", "첸나이", "콜카타", "푸네", "아마다바드", "수라트", "자이푸르", "러크나우"}, 2},
        {"다음 중 미국의 수도는?", {"뉴욕", "로스앤젤레스", "시카고", "워싱턴 D.C.", "휴스턴", "필라델피아", "피닉스", "샌안토니오", "샌디에고", "댈러스"}, 4}
    };

    printf("문제를 시작합니다.\n\n");
    ask_questions(questions);

    return 0;
}
