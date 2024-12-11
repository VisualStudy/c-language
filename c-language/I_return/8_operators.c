#include <stdio.h>

int main(void)
{
    int a = 5, b = 3;
    
    printf("Arithmetic Operators(산술 연산자):\n");
    printf("Addition(덧셈): %d\n", a + b);
    printf("Subtraction(뺄셈): %d\n", a - b);
    printf("Multiplication(곱셈): %d\n", a * b);
    printf("Division(나눗셈): %d\n", a / b);
    printf("Modulus(나눈 후 나머지 not 몫): %d\n\n", a % b);
    
    printf("Relational Operators(관계 연산자):\n");
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n\n", a < b);

    printf("Logical Operators(논리 연산자):\n");
    printf("a > 0 && b > 0: %d\n", (a > 0 && b > 0)); // a > 0 && b > 0: a는 0보다 크다 그리고 b도 0보다 크다
    printf("a > 0 || b < 0: %d\n\n", (a > 0 || b < 0)); // a > 0 || b < 0: a는 0보다 크다 또는 b는 0보다 작다

    printf("Bitwise Operators(비트 연산자):\n"); // 비트 단위로 연산 수행: 2진수 변환 후 연산
    printf("Bitwise AND: %d\n", a & b); // 비트 AND: 2진수 변환 후 두 비트 모두 1일 때만 1로 취급하여 비트값 계산
    printf("Bitwise OR: %d\n", a | b); // 비트 OR: 2진수 변환 후 두 비트 중 하나라도 1이면 1 -> 비트값 계산
    printf("Bitwise XOR: %d\n", a ^ b); // 비트 XOR: 2진수 변환 후 두 수의 비트가 다를 때만 1 -> 비트값 계산
    printf("Bitwise NOT (a): %d\n", ~a); // 비트 NOT: 2진수 변환 후 1을 0으로, 0을 1로 -> 비트값 계산

    return 0;
}