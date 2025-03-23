#include <stdio.h>

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
    return 0;
}