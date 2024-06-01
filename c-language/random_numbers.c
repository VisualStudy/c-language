#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning (disable:4996)

int main(void) // 1~100 사이의 난수를 가정하고 이분검색 방식으로 찾아가기
{
    srand((unsigned)time(NULL)); //현재 시간 기준 시드값 설정하기
    
    int _ = 0;
    int answer = 0;

    int cnt = 0;
    int guess = 0;
    answer = (rand() % 100) + 1;

    do
    {
        printf("\n 추측값 입력 :  ");
        _ = scanf("%d", &guess);
        if (answer < guess)
        {
        printf("\n 입력값이 더 높습니다.");
        }

        if (answer > guess)
        {
            printf("\n 입력값이 더 낮습니다.");
        }
        cnt++;
    }
    
    while (answer != guess);
    printf("\n 정답! <추측횟수> = %d", cnt);

    return 0;   
}