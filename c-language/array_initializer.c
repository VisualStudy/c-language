// 배열 이니셜라이저 식
#include <stdio.h>

int main(void)
{
    int num = { 1234 }; // 배열 이니셜라이저(초기자, 초기화자)

    double numbers[] = { 1234, 3.14 }; // 배열 이니셜라이저

    printf("%d\n", num);
    printf("%lf, %lf\n", numbers[0], numbers[1]); // 1234.000000, 3.140000

    return 0;
}