//[?] 배열을 사용하지 않고 3명의 학생의 국어 점수의 총점을 구하려면?
#include <stdio.h>

int main(void)
{
    int kor1 = 90; // 1번 학생
    int kor2 = 80; // 2번 학생
    int kor3 = 70; // 3번 학생

    int tot = kor1 + kor2 + kor3;

    printf("총점: %d", tot); // 240

    return 0;
}