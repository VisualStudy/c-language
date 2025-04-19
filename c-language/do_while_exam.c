#include <stdio.h>

int main(void)
{
    int i;
    printf("값 입력: ");
    scanf("%d", &i);

    while (i > 0)
    {
        if (i % 2 != 0)
        {
            printf("홀수입니다.\n");
        }
        else if (i % 2 == 0)
        {
            continue;
            printf("짝수입니다.\n");
        }
    }
    
    return 0;
}