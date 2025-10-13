#include <stdio.h>

int main(void)
{
    int num1, num2, num3, result = 0;
    char calcu;

    printf("연산 선택 (+ 또는 *) => ");
    scanf("%c", &calcu);

    if (calcu == '+')
    {
        printf("첫 번째 값 => ");
        scanf("%d", &num1);
        printf("두 번째 값 => ");
        scanf("%d", &num2);
        printf("세 번째 값 => ");
        scanf("%d", &num3);

        result = num1 + num2 + num3;
        printf("%d + %d + %d = %d", num1, num2, num3, result);
    }

    else if (calcu == '*')
    {
        printf("첫 번째 값 => ");
        scanf("%d", &num1);
        printf("두 번째 값 => ");
        scanf("%d", &num2);
        printf("세 번째 값 => ");
        scanf("%d", &num3);

        result = num1 * num2 * num3;
        printf("%d * %d * %d = %d", num1, num2, num3, result);
    }
    
    return 0;
}