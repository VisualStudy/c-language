#include <stdio.h>

int main(void)
{
    int num1, num2, num3, result = 0;
    char calcu;

    printf("���� ���� (+ �Ǵ� *) => ");
    scanf("%c", &calcu);

    if (calcu == '+')
    {
        printf("ù ��° �� => ");
        scanf("%d", &num1);
        printf("�� ��° �� => ");
        scanf("%d", &num2);
        printf("�� ��° �� => ");
        scanf("%d", &num3);

        result = num1 + num2 + num3;
        printf("%d + %d + %d = %d", num1, num2, num3, result);
    }

    else if (calcu == '*')
    {
        printf("ù ��° �� => ");
        scanf("%d", &num1);
        printf("�� ��° �� => ");
        scanf("%d", &num2);
        printf("�� ��° �� => ");
        scanf("%d", &num3);

        result = num1 * num2 * num3;
        printf("%d * %d * %d = %d", num1, num2, num3, result);
    }
    
    return 0;
}