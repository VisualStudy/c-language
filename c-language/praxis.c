#include <stdio.h>

void para(void)
{
    printf("이건 para() 함수입니다.\n");
    printf("*\n");
    printf("asterisk\n");
}

int main(void)
{
    int x = 2550;
    int y = 19248;
    int sum;
    
    sum = x + y;
    printf("x가 2550이고 y가 19248일 때, 둘의 합은 %d입니다.\n", sum);
    
    int summer;
    summer = sum + sum;
    printf("썸머 썸머 데이: %10d\n\n", summer);;

    printf("* * * * *\n");
    printf("* * * * *\n");
    printf("* * * * *\n");
    printf("* * * * *\n");
    printf("* * * * *\n");

    for (int i = 0; i < 6; i++)
    {
        printf("\n@@@@@");
    }

    printf("\n\n\n");

    for (int i = 0; i < 6; i++)
    {
        printf("*****");
    }

    for (int i = 0; i < 2; i++)
    {
        printf("어라? 왜 2번씩 적히지?");
    }

    printf("\n\n\n");

    return 0;
}