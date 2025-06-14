#include <stdio.h>

int main(void)
{
    int scores[5]; // 학생 점수를 저장할 배열
    int sum = 0;
    float average;

    // 배열 입력 (단순 반복)
    for (int i = 0; i < 5; i++)
    {
        printf("%d번째 학생의 점수 입력: ", i + 1);
        scanf("%d", &scores[i]); // 배열 요소에 값 저장
    }

    // 배열 출력 + 합계 계산
    for (int i = 0; i < 5; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
        sum += scores[i];
    }

    // 평균 계산
    average = sum / 5.0;

    // 출력
    printf("총점: %d\n", sum);
    printf("평균: %.2f\n", average);

    return 0;
}