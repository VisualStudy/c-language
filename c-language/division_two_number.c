#include <stdio.h>

int main(void)
{
    int num1, num2, result = 0;
    
    printf("## �� ���� ������ ##\n");
    printf("ù ��° �� => ");
    scanf("%d", &num1);
    printf("�� ��° �� => ");
    scanf("%d", &num2);
    if (num2 == 0)
    {
        printf("�ٽ� �Է��ϼ���.");
        printf("�� ��° �� => ");
        scanf("%d", &num2);
        if (num2 == 0)
        {
            printf("�� �ٽ� �Է��ϼ���.");
            printf("�� ��° �� => ");
            scanf("%d", &num2);
            if (num2 == 0)
            {
                printf("0�� �� �� �Է��߽��ϴ�. �����մϴ�.");
            }
            else
            {
                result = num1 / num2;
                printf("%d / %d = %d", num1, num2, result);
            }
        }
        else
        {
            result = num1 / num2;
            printf("%d / %d = %d", num1, num2, result);
        }
    }
    else
    {
        result = num1 / num2;
        printf("%d / %d = %d", num1, num2, result);
    }
    

    return 0;
}