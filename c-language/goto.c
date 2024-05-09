// goto문: 지정한 레이블(책갈피)로 이동하는 구문
#define _CRT_SECURE_NO_WARNINGS // scanf() 보안 경고 에러 방지
#include <stdio.h>

int main(void)
{
    int chapter = 0;
    int r = 0;

    printf("시작\n");

    Start:
        printf("0, 1, 2 중 하나 입력: _\b");
        r = scanf("%d", &chapter);

        if (chapter == 1)
        {
            goto Chapter1;
        }
        else if (chapter == 2)
        {
            goto Chapter2;
        }
        else
        {
            goto End;
        }

Chapter1:
    printf("1장입니다.\n");
Chapter2:
    printf("2장입니다.\n");
    goto Start;

End:
    printf("종료\n");

    return 0;
}