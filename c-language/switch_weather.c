#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
    int weather = 0;
    int _ = 0;

    while (1)
    {
        printf("오늘 날씨는 어떤가요? (맑음(1), 흐림(2), 비(3), 눈(4), ...)\n");

        _ = scanf("%d", &weather);
        switch (weather)
        {
        case 1:
            printf("오늘 날씨는 맑군요.");
            break;
        case 2:
            printf("오늘 날씨는 흐리군요.");
            break;
        case 3:
            printf("오늘 날씨는 비가 오는군요.\n");
            //  break;
        default:
            printf("혹시 눈이 내리나요?");
            break;
        }
    }

    return 0;
}