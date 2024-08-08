#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void toss(int stage);
void checkResult(int coinState, int stage);
void finalMessage();
void resetGame();

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
            for (int stage = 1; stage <= 10; stage++)
            {
                toss(stage);

                if (stage == 5)
                {
                    char decision[4];
                    printf("\n세계의 이치를 깨부수고 확률로서 세상에 도전할 것인가? (yes 또는 no): ");
                    scanf("%s", decision);

                    if (strcmp(decision, "no") == 0)
                    {
                        printf("\n그대는 세계의 거대한 이치 속에 잠겨 가라앉았다. 그대의 운 또한 여기까지일지니.. 그대는 규율에 대적하지 못하였구나.\n");
                        break;
                    }
                }
            }
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

void toss(int stage)
{
    int coinState = rand() % 2; // 0 또는 1 무작위 생성
    checkResult(coinState, stage);
}

void checkResult(int coinState, int stage)
{
    char guess[10];
    const char* stageName = stage <= 5 ? "단계" : "Challenge";

    if (stage > 5)
    {
        printf("\n%s %d: 동전의 앞뒷면을 맞춰보세요 ('앞면' 또는 '뒷면'을 입력하세요): ", stageName, stage - 5);
    }
    else
    {
        printf("\n%d단계: 동전의 앞뒷면을 맞춰보세요 ('앞면' 또는 '뒷면'을 입력하세요): ", stage);
    }

    scanf("%s", guess);

    if ((coinState == 1 && strcmp(guess, "앞면") == 0) ||
        (coinState == 0 && strcmp(guess, "뒷면") == 0))
    {
        printf("정답입니다! 다음 단계로 넘어갑니다.\n");
    }
    else
    {
        if (stage > 5)
        {
            printf("그대는 이치를 극복하지 못했다...\n");
        }
        else
        {
            printf("오답입니다! 다시 처음부터 시작하세요.\n");
        }
        resetGame();
    }

    if (stage == 10)
    {
        finalMessage();
    }
}

void finalMessage()
{
    char decision[4];
    printf("\n그대는 집념을 보여 이치를 부수었으니.. 이를 기억하여 나아가라! (yes를 입력하면 종료): ");
    scanf("%s", decision);
    if (strcmp(decision, "yes") == 0)
    {
        printf("게임을 종료합니다.\n");
        exit(0);
    }
}

void resetGame()
{
    main();
    exit(0);
}
