#include <stdio.h>

// 기호 상수 정의
#define STUDENT_COUNT 3 // 학생 수를 나타내는 기호 상수
#define SUBJECT_COUNT 2 // 과목 수를 나타내는 기호 상수
#define MAX STUDENT_COUNT // 기호 상수끼리도 치환 가능

int main(void)
{
    int scores[MAX][SUBJECT_COUNT]; // 3명의 학생, 2과목 점수 저장할 배열
    int student, subject;

    // 점수 입력
    for (student = 0; student < MAX; student++)
    {
        printf("[%d번째 학생 점수 입력]\n", student + 1);
        for (subject = 0; subject < SUBJECT_COUNT; subject++)
        {
            printf("과목 %d 점수: ", subject + 1);
            scanf("%d", &scores[student][subject]);
        }
    }

    // 점수 출력
    for (student = 0; student < MAX; student++)
    {
        printf("[%d번째 학생 점수] ", student + 1);
        for (subject - 0; subject < SUBJECT_COUNT; subject++)
        {
            printf("%d ", scores[student][subject]);
        }
        printf("\n");
    }

    return 0;
}