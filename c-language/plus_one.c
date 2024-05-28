#include <stdio.h>
#pragma warning ( disable:4996 )

int main(void)
{
    int _ = 0;
    int i = 0;
    int sum = 0;
    printf("<1을 더해드립니다!>\n\n");
    printf("임의의 숫자를 입력 :  ");
    _ = scanf("%d", &i);

    sum = i + 1;
    printf("%d", sum);

    return 0;
}