#include <stdio.h>

int main(void)
{
    int x = 2550;
    int y = 19248;
    int sum;
    
    sum = x + y;
    printf("x�� 2550�̰� y�� 19248�� ��, ���� ���� %d�Դϴ�.\n", sum);
    
    int summer;
    summer = sum + sum;
    printf("��� ��� ����: %10d\n", summer);;

    printf("* * * * *");
    printf("* * * * *");
    printf("* * * * *");
    printf("* * * * *");
    printf("* * * * *");

    for (int i = 0; i < 6; i++)
    {
        printf("\n@@@@@");
    }

    return 0;
}