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
    srand(time(0)); // ���� �õ� ����

    while (1)
    {
        printf("��ɾ �Է��ϼ��� (1: '����! ����!', 2: '����'): ");
        scanf("%d", &command);

        if (command == 1)
        {
            for (int stage = 1; stage <= 10; stage++)
            {
                toss(stage);

                if (stage == 5)
                {
                    char decision[4];
                    printf("\n������ ��ġ�� ���μ��� Ȯ���μ� ���� ������ ���ΰ�? (yes �Ǵ� no): ");
                    scanf("%s", decision);

                    if (strcmp(decision, "no") == 0)
                    {
                        printf("\n�״�� ������ �Ŵ��� ��ġ �ӿ� ��� ����ɾҴ�. �״��� �� ���� �������������.. �״�� ������ �������� ���Ͽ�����.\n");
                        break;
                    }
                }
            }
        }
        else if (command == 2)
        {
            printf("������ �����մϴ�.\n");
            break;
        }
        else
        {
            printf("�� �� ���� ��ɾ��Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }

    return 0;
}

void toss(int stage)
{
    int coinState = rand() % 2; // 0 �Ǵ� 1 ������ ����
    checkResult(coinState, stage);
}

void checkResult(int coinState, int stage)
{
    char guess[10];
    const char* stageName = stage <= 5 ? "�ܰ�" : "Challenge";

    if (stage > 5)
    {
        printf("\n%s %d: ������ �յ޸��� ���纸���� ('�ո�' �Ǵ� '�޸�'�� �Է��ϼ���): ", stageName, stage - 5);
    }
    else
    {
        printf("\n%d�ܰ�: ������ �յ޸��� ���纸���� ('�ո�' �Ǵ� '�޸�'�� �Է��ϼ���): ", stage);
    }

    scanf("%s", guess);

    if ((coinState == 1 && strcmp(guess, "�ո�") == 0) ||
        (coinState == 0 && strcmp(guess, "�޸�") == 0))
    {
        printf("�����Դϴ�! ���� �ܰ�� �Ѿ�ϴ�.\n");
    }
    else
    {
        if (stage > 5)
        {
            printf("�״�� ��ġ�� �غ����� ���ߴ�...\n");
        }
        else
        {
            printf("�����Դϴ�! �ٽ� ó������ �����ϼ���.\n");
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
    printf("\n�״�� ������ ���� ��ġ�� �μ�������.. �̸� ����Ͽ� ���ư���! (yes�� �Է��ϸ� ����): ");
    scanf("%s", decision);
    if (strcmp(decision, "yes") == 0)
    {
        printf("������ �����մϴ�.\n");
        exit(0);
    }
}

void resetGame()
{
    main();
    exit(0);
}
