// switch 문 사용하기
#include <stdio.h>

int main(void)
{
    int x = 2;

    switch (5)
    {
        case 1:
            printf("1입니다.\n"); // x가 1일 때 실행
            break;
        case 2:
            printf("2입니다.\n"); // x가 2일 때 실행
            break;
        case 3:
            printf("3입니다.\n"); // x가 3일 때 실행
            break;
        default:
            printf("1도 2도 3도 아닙니다.\n"); // 기본값
            break;
    }

    return 0;
}