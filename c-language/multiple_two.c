#include <stdio.h>
#pragma warning (disable:4996)

int main(void)
{
    int _ = 0;
    int i = 0;
    int sum = 0;
    
    printf("<2를 곱하기>");
    printf("\n\n값 입력 :  ");
    _ = scanf("%d", &i);
    
    sum = i * 2;
    printf("%d", sum);

    return 0;
}