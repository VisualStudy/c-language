#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

// 문제의 총 개수
#define TOTAL_QUESTIONS 10

typedef struct 
{
    char question[100];
    char options[4][20];
    int correct_option;
} Question;

void shuffle(int* array, int n) 
{
    if (n > 1) 
    {
        for (int i = 0; i < n - 1; i++) 
        {
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
            if (scanf("%d", &a) != 1) 
            {
                printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
                return;
            }

            if (a == questions[question_index].correct_option) 
            {
                printf("정답! 10점을 획득하였습니다.\n\n");
                score += 10;
            }
            else 
            {
                printf("오답! 다시 생각해보세요.\n\n");
            }
        }

        if (score == 100) 
        {
            printf("모든 문제를 맞추셨습니다! 정말 훌륭합니다! 프로그램을 종료합니다.\n");
            break;
        }
        else if (score >= 80) 
        {
            printf("훌륭합니다! 하지만 더 잘할 수 있습니다. 프로그램을 종료합니다.\n");
            break;
        }
        else if (score >= 60) 
        {
            printf("노력하셨습니다. 하지만 더 노력하세요. 프로그램을 종료합니다.\n");
            break;
        }
        else 
        {
            printf("부족합니다. 다시 도전하세요. 모든 문제를 랜덤으로 재배치하여 다시 시작합니다.\n\n");
            score = 0;  // 점수 초기화
        }
    }
}

int main(void) 
{
    srand(time(NULL));  // 랜덤 초기화는 main 함수에서 한 번만 호출합니다.

    Question questions[TOTAL_QUESTIONS] = 
    {
        {"다음 중 생물학적 과일이 아닌 것은?", {"수박", "토마토", "오이", "루바브"}, 4},
        {"다음 중 포유류가 아닌 것은?", {"고양이", "상어", "사람", "코끼리"}, 2},
        {"다음 중 대륙이 아닌 것은?", {"아프리카", "아시아", "유럽", "하와이"}, 4},
        {"다음 중 한국의 수도는?", {"서울", "부산", "대전", "인천"}, 1},
        {"다음 중 바다에 속하지 않는 것은?", {"태평양", "대서양", "흑해", "아마존강"}, 4},
        {"다음 중 일본의 수도는?", {"오사카", "교토", "도쿄", "삿포로"}, 3},
        {"다음 중 태양계의 행성이 아닌 것은?", {"지구", "화성", "목성", "달"}, 4},
        {"다음 중 한국의 전통 음식이 아닌 것은?", {"김치", "불고기", "초밥", "비빔밥"}, 3},
        {"다음 중 인도의 수도는?", {"뭄바이", "델리", "벵갈루루", "첸나이"}, 2},
        {"다음 중 미국의 수도는?", {"뉴욕", "로스앤젤레스", "시카고", "워싱턴 D.C."}, 4}
    };

    printf("문제를 시작합니다.\n\n");
    ask_questions(questions);

    return 0;
}
