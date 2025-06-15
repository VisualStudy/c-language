#include <stdio.h>

int main(void)
{
    int a = 5, b = 2;
    double result1, result2;

    result1 = a / b; // 정수끼리 나눔 -> 2
    result2 = (double)a / b; // a를 double로 형변환 -> 2.5

    printf("정수 나눗셈 (a / b): %f\n", result1);
    printf("형변환 후 나눗셈 ((double)a / b: %f\n", result2);

    // 실수를 정수로 변환
    double pi = 3.14159;
    int IntPi = (int)pi;
    printf("실수 pi를 정수로 변환: %d\n", IntPi); // 3

    return 0;
}