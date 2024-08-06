#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void 던지기();
void 결과확인(int 동전상태);

int main() 
{
    char 명령어[20];
    srand(time(0)); // 랜덤 시드 설정

    while (1) 
    {
        printf("명령어를 입력하세요 ('던져! 던져!' 또는 '종료' 입력 가능): ");
        scanf("%s", 명령어);

        if (strcmp(명령어, "던져! 던져!") == 0) 
        {
            던지기();
        }
        else if (strcmp(명령어, "종료") == 0) 
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

void 던지기() 
{
    int 동전상태 = rand() % 2; // 0 또는 1 무작위 생성
    결과확인(동전상태);
}

void 결과확인(int 동전상태) 
{
    char 추측[10];

    printf("동전의 앞뒷면을 맞춰보세요 ('앞면' 또는 '뒷면'): ");
    scanf("%s", 추측);

    if ((동전상태 == 1 && strcmp(추측, "앞면") == 0) ||
        (동전상태 == 0 && strcmp(추측, "뒷면") == 0)) 
        {
        printf("정답!\n");
    }
    else 
    {
        printf("오답!\n");
    }
}
