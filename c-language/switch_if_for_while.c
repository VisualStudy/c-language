#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int menu = 0;
    int _ = 0;

    printf("메뉴 번호를 입력하시오. (단, 1 또는 2 중에서 하나만 입력하시오.) :  ");
    _ = scanf("%d", &menu);

    switch (menu)
    {
     case 1:
        printf("\n케이스 1, 정상 적용.\n\n");
        printf("케이스 1을 작동할까요? 1) YES 2) NO\n\n");
        
        int start = 0;

        _ = scanf("%d", &start);

        if (start == 1)
        { 
            
            printf("\n정상 작동!\n\n");

            for (int i = 0; i < 5; i++)
            {
                printf("다섯 번 출력되는 문자열입니다.\n");
            }
        }
        else if (start == 2)
            printf("\n종료 중...\n\n");
                
                break;

    case 2:
        printf("\n케이스 2, 정상 적용.\n\n");
        printf("케이스 2을 작동할까요? 1) YES 2) NO\n\n");

        int start2 = 0;

        _ = scanf("%d", &start2);

        if (start2 == 1)
        { 
            printf("\n정상 작동!\n\n");

            for (int j = 0; j < 10; j++)
            {
                printf("열 번 출력되는 문자열입니다.\n");
            }
        }
        else if (start2 == 2)
            printf("\n종료 중...\n\n");
                
                break;

        default:
            printf("\n저런 1 또는 2를 제외한 숫자를 입력하셨군요...");
                
                break;
    }

    return 0;
}