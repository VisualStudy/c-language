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

    printf("Bitwise Operators(비트 연산자):\n"); // 비트 연산자 설명 추가 예정
    printf("Bitwise AND: %d\n", a & b); // 비트 AND
    printf("Bitwise OR: %d\n", a | b); // 비트 OR
    printf("Bitwise XOR: %d\n", a ^ b); // 비트 XOR
    printf("Bitwise NOT (a): %d\n", ~a); // 비트 NOT

    return 0;
}