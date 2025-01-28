#include <stdio.h>

int main(void)
{
    int scores[5]; // 5명의 점수를 저장할 배열
    int i, sum = 0;

    // 점수 입력 받기
    printf("학생 5명의 점수를 입력하세요:\n");
    for ( i = 0; i < 5; i++)
    {
        printf("학생 %d의 점수: ", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }

    // 평균 계산 및 출력
    float average = (float)sum / 5;
    printf("전체 학생의 평균 점수: %.2f\n", average);

    return 0;
}