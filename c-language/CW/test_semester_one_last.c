#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)

int arith_sum();
void ran_num();

int arith_sum()
{
    int f, l, d, p, sum = 0;

    printf("초항 입력 : ");
    scanf("%d", &f);
    printf("말항 입력 : ");
    scanf("%d", &l);
    printf("등차 입력 : ");
    scanf("%d", &d);
    
    for (p = f; p <= l; p = p + d)
    {
        sum = sum + p;
    }
    return sum;
}

void ran_num()
{
    int answer, guess, cnt;

    srand((unsigned)time(NULL)); // srand((unsigned)time(null)) == srand(0)
    answer = (rand() % 100) + 1;
    cnt = 0;

    do
    {
        printf("추측값 입력 : ");
        scanf("%d", &guess);
        if (answer < guess) printf("입력값이 크다");
        if (answer > guess) printf("입력값이 작다");
        cnt++;
    } 
    while (answer != guess);
    printf("정답. 추측 횟수 = %d", cnt);
}

void convert_A_a()
{
    char letter;
    letter = getchar();
    while (1)
    {
        printf("대소문자 입력 : ");
        letter = getche();
        if (letter == '?') break;
        
        if (letter >= 'a' && letter <= 'z') 
        {
            printf("\n 입력문 %c는 대문자 %c로 변환", letter, letter - 32);
        }

        else if (letter >= 'A' && letter <= 'Z')
        {
            printf("\n 입력문 %c는 소문자 %c로 변환", letter , letter + 32);
        }
    }
}

void main(void)
{
    int result, menu = 0;
    while (1)
    {
        printf("\n\n\n 메뉴 1) 등차수열 2) 난수 3) 대소문자 변환 4) 종료:  ");
        scanf("%d", &menu);
        if (menu == 4)
            break;
        switch (menu)
        {
            case 1:
                result = arith_sum();
                printf("결과 :  %d", result);
                break;

            case 2:
                ran_num();
                
                break;

            case 3:
                convert_A_a();

                break;

            default:
                printf("\n장난치지 마세요!");
                break;
        }
    }
}