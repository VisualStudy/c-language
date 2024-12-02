#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int number;
    printf("수 입력: ");
    scanf("%d", &number);

    if (number % 2 == 0) // 만약 변수 number를 2로 나누었을 때 나머지가 0이라면
    {
        printf("%d, 너는 짝수로군!", number);
    }
    else // 2로 나누었을 때 나머지가 0이 아니라면(위 if 괄호 안 내용이 아닐 경우를 뜻함)
    {
        printf("%d, 너는 홀수다!", number);
    }
    
    return 0;
}