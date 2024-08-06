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
    srand(time(0)); // ���� �õ� ����

    while (1)
    {
        printf("��ɾ �Է��ϼ��� (1: '����! ����!', 2: '����'): ");
        scanf("%d", &command);

        if (command == 1)
        {
            toss();
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

void toss()
{
    int coinState = rand() % 2; // 0 �Ǵ� 1 ������ ����
    checkResult(coinState);
}

void checkResult(int coinState)
{
    char guess[10];

    printf("������ �յ޸��� ���纸���� ('�ո�' �Ǵ� '�޸�'�� ���� �Է��Ͻÿ�. ��, '�� �����ϰ� �Է��� ��.): ");
    scanf("%s", guess);

    if ((coinState == 1 && strcmp(guess, "�ո�") == 0) ||
        (coinState == 0 && strcmp(guess, "�޸�") == 0))
    {
        printf("����!\n");
    }
    else
    {
        printf("����!\n");
    }
}
