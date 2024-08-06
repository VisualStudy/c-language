#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void toss();
void checkResult(int coinState);

int main()
{
    int command;
    srand(time(0)); // 랜덤 시드 설정

    while (1)
    {
        printf("명령어를 입력하세요 (1: '던져! 던져!', 2: '종료'): ");
        scanf("%d", &command);

        if (command == 1)
        {
            toss();
        }
        else if (command == 2)
        {
            printf("게임을 종료합니다.\n");
            break;
        }
        else
        {
            printf("알 수 없는 명령어입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}

void toss()
{
    int coinState = rand() % 2; // 0 또는 1 무작위 생성
    checkResult(coinState);
}

void checkResult(int coinState)
{
    char guess[10];

    printf("동전의 앞뒷면을 맞춰보세요 ('앞면' 또는 '뒷면'을 직접 입력하시오. 단, '을 제외하고 입력할 것.): ");
    scanf("%s", guess);

    if ((coinState == 1 && strcmp(guess, "앞면") == 0) ||
        (coinState == 0 && strcmp(guess, "뒷면") == 0))
    {
        printf("정답!\n");
    }
    else
    {
        printf("오답!\n");
    }
}
