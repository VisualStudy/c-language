#include <stdio.h>

int main(void)
{
    int kor[3];
    int sum = 0; // 합계가 담길 변수 sum 선언과 동시에 0으로 초기화
    float avg = 0; // 평균이 담길 실수형 변수 avg 선언과 동시에 0으로 초기화

    // 배열에 수작업으로 직접 값 대입
    kor[0] = 100;
    kor[1] = 90;
    kor[2] = 80;

    sum = kor[0] + kor[1] + kor[2]; // 총점 계산
    avg = sum / (float)3.0;         // 평균 계산

    // 총점과 평균 출력: 평균은 소수점 2자리까지 출력
    printf("총점: %d, 평균: %.2f\n", sum, avg);

    return 0;
}