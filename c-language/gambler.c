#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void ������();
void ���Ȯ��(int ��������);

int main() 
{
    char ��ɾ�[20];
    srand(time(0)); // ���� �õ� ����

    while (1) 
    {
        printf("��ɾ �Է��ϼ��� ('����! ����!' �Ǵ� '����' �Է� ����): ");
        scanf("%s", ��ɾ�);

        if (strcmp(��ɾ�, "����! ����!") == 0) 
        {
            ������();
        }
        else if (strcmp(��ɾ�, "����") == 0) 
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

void ������() 
{
    int �������� = rand() % 2; // 0 �Ǵ� 1 ������ ����
    ���Ȯ��(��������);
}

void ���Ȯ��(int ��������) 
{
    char ����[10];

    printf("������ �յ޸��� ���纸���� ('�ո�' �Ǵ� '�޸�'): ");
    scanf("%s", ����);

    if ((�������� == 1 && strcmp(����, "�ո�") == 0) ||
        (�������� == 0 && strcmp(����, "�޸�") == 0)) 
        {
        printf("����!\n");
    }
    else 
    {
        printf("����!\n");
    }
}
