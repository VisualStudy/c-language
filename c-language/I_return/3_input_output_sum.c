#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num1, num2, sum;

    printf("첫 번째 숫자 입력: ");
    scanf("%d", &num1); // 첫 번째 숫자 입력 받기
    printf("두 번째 숫자 입력: ");
    scanf("%d", &num2); // 두 번째 숫자 입력 받기
    
    sum = num1 + num2; // 정수형 변수 sum을 변수 num1과 num2의 합으로 설정
    printf("첫 번째 숫자 %d와 두 번째 숫자 %d의 합은 %d입니다.", num1, num2, sum); //알맞게 각각의 %d에 변수 할당 후 출력!

    return 0;
}