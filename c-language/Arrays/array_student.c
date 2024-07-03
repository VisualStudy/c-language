// 3명의 학생의 점수를 입력받아 총점을 구하는 프로그램
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 3개의 요소를 가지는 1차원 배열 생성
    int students[3];
    char buffer[5];
    int total = 0;

    // 사용자로부터 정수 데이터 3개 입력받아 배열에 저장
    for (int i = 0; i < 3; i++)
    {
        printf("%d번 학생 점수: ___\b\b\b", (i + 1));
        gets_s(buffer, sizeof(buffer)); // 사용자부터 점수 입력
        students[i] = atoi(buffer); // 입력된 값을 정수로 변환
        total += students[i];
    }

    // 출력하기
    printf("\n점수: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t", students[i]);
    }
    printf("\n총점: %d\n", total);

    return 0;
}