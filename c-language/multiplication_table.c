#include <stdio.h>
#pragma warning ( disable:4996 ) // 경고 무시 통해 빌드 작동 O

int main(void)
{
    int i = 0; // 단 입력 받을 값 초기화
    int _ = 0; // scanf 경고 무시
    printf("원하는 단 입력 :  ");
    _ = scanf("%d", &i);

    for (int j = 1; j <= 9; j++) // 입력 받은 단에 1 ~ 9까지 곱하기
    {
        printf("\n %d * %d = %d", i, j, i * j); // 구구단 구현
    }

    return 0;
}