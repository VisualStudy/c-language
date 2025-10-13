#include <stdio.h>

int main(void)
{
    int num1, num2, result = 0;
    
    printf("## 두 수를 나누기 ##\n");
    printf("첫 번째 값 => ");
    scanf("%d", &num1);
    printf("두 번째 값 => ");
    scanf("%d", &num2);
    if (num2 == 0)
    {
        printf("다시 입력하세요.");
        printf("두 번째 값 => ");
        scanf("%d", &num2);
        if (num2 == 0)
        {
            printf("또 다시 입력하세요.");
            printf("두 번째 값 => ");
            scanf("%d", &num2);
            if (num2 == 0)
            {
                printf("0을 세 번 입력했습니다. 종료합니다.");
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