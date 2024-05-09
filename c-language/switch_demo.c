#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int answer = 0;
    int _ = 0;
    printf("정수를 입력하세요.\n");

    // 정수 하나 입력하고 엔터 입력한 후 answer 변수에 담기
    _ = scanf("%d", &answer);

    // 선택문
    switch (answer)
    {
        case 1:
            printf("1을 선택했습니다.\n");
            break;
        case 2:
            printf("2을 선택했습니다.\n");
        case 3:
            printf("3을 선택했습니다.\n");
            break;
        default:
            printf("그냥 찍으셨군요.\n");
            break;
    }

    return 0;
}