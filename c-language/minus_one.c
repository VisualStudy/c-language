#include <stdio.h>
#pragma warning (disable:4996)

int main(void)
{
    int _ = 0;
    int i = 0;
    int sum = 0;

    printf("<1을 빼겠습니다!>");
    printf("\n\n숫자 입력 :  ");
    _ = scanf("%d", &i);

    sum = i - 1;

    printf("%d", sum);

    return 0;
}