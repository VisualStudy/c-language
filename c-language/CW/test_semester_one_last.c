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

    printf("���� �Է� : ");
    scanf("%d", &f);
    printf("���� �Է� : ");
    scanf("%d", &l);
    printf("���� �Է� : ");
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
        printf("������ �Է� : ");
        scanf("%d", &guess);
        if (answer < guess) printf("�Է°��� ũ��");
        if (answer > guess) printf("�Է°��� �۴�");
        cnt++;
    } 
    while (answer != guess);
    printf("����. ���� Ƚ�� = %d", cnt);
}

void convert_A_a()
{
    char letter;
    letter = getchar();
    while (1)
    {
        printf("��ҹ��� �Է� : ");
        letter = getche();
        if (letter == '?') break;
        
        if (letter >= 'a' && letter <= 'z') 
        {
            printf("\n �Է¹� %c�� �빮�� %c�� ��ȯ", letter, letter - 32);
        }

        else if (letter >= 'A' && letter <= 'Z')
        {
            printf("\n �Է¹� %c�� �ҹ��� %c�� ��ȯ", letter , letter + 32);
        }
    }
}

void main(void)
{
    int result, menu = 0;
    while (1)
    {
        printf("\n\n\n �޴� 1) �������� 2) ���� 3) ��ҹ��� ��ȯ 4) ����:  ");
        scanf("%d", &menu);
        if (menu == 4)
            break;
        switch (menu)
        {
            case 1:
                result = arith_sum();
                printf("��� :  %d", result);
                break;

            case 2:
                ran_num();
                
                break;

            case 3:
                convert_A_a();

                break;

            default:
                printf("\n�峭ġ�� ������!");
                break;
        }
    }
}