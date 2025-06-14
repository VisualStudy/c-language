#include <stdio.h>

// 함수 선언
int Factorial(int n);

int main(void)
{
    int num = 5;
    int result = Factorial(num);
    printf("%d! = %d\n", num, result);

    return 0;
}

// 재귀 함수 정의
int Factorial(int n)
{
    if (n == 0)
    {
        return 1; // 종료 조건: 0! = 1
    }
    else
    {
        return n * Factorial(n - 1); // 재귀 호출
    }
}