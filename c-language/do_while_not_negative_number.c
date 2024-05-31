#include <stdio.h>
#pragma warning (disable:4996)

int main(void) // 음수가 아닐 동안 계속(do while) 입력하고 덧셈해서 출력
{
    int _ = 0;
    int n = 0;
    int sum = 0;
    do
    {
        printf("\n 정수 입력 :  ");
        _ = scanf("%d", &n);
        if ( n < 0 )
        {
            break;
        }
        sum = sum + n;
    }

    while ( n >= 0 ); // 음수 x -> 반복
    {
        printf("\n\n합산 = %d", sum);
    }

    return 0;
}