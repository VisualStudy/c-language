#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int menu = 0;
    int _ = 0;

    printf("�޴� ��ȣ�� �Է��Ͻÿ�. (��, 1 �Ǵ� 2 �߿��� �ϳ��� �Է��Ͻÿ�.) :  ");
    _ = scanf("%d", &menu);

    switch (menu)
    {
     case 1:
        printf("\n���̽� 1, ���� ����.\n\n");
        printf("���̽� 1�� �۵��ұ��? 1) YES 2) NO\n\n");
        
        int start = 0;

        _ = scanf("%d", &start);

        if (start == 1)
        { 
            
            printf("\n���� �۵�!\n\n");

            for (int i = 0; i < 5; i++)
            {
                printf("�ټ� �� ��µǴ� ���ڿ��Դϴ�.\n");
            }
        }
        else if (start == 2)
            printf("\n���� ��...\n\n");
                
                break;

    case 2:
        printf("\n���̽� 2, ���� ����.\n\n");
        printf("���̽� 2�� �۵��ұ��? 1) YES 2) NO\n\n");

        int start2 = 0;

        _ = scanf("%d", &start2);

        if (start2 == 1)
        { 
            printf("\n���� �۵�!\n\n");

            for (int j = 0; j < 10; j++)
            {
                printf("�� �� ��µǴ� ���ڿ��Դϴ�.\n");
            }
        }
        else if (start2 == 2)
            printf("\n���� ��...\n\n");
                
                break;

        default:
            printf("\n���� 1 �Ǵ� 2�� ������ ���ڸ� �Է��ϼ̱���...");
                
                break;
    }

    return 0;
}