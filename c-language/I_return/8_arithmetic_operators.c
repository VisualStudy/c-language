#include <stdio.h>

int main(void)
{
    int a = 5, b = 3;
    
    printf("Arithmetic Operators(��� ������):\n");
    printf("Addition(����): %d\n", a + b);
    printf("Subtraction(����): %d\n", a - b);
    printf("Multiplication(����): %d\n", a * b);
    printf("Division(������): %d\n", a / b);
    printf("Modulus(���� �� ������ not ��): %d\n\n", a % b);
    
    printf("Relational Operators(���� ������):\n");
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n\n", a < b);

    printf("Logical Operators(�� ������):\n");
    printf("a > 0 && b > 0: %d\n", (a > 0 && b > 0));
    printf("a > 0 || b < 0: %d\n\n", (a > 0 || b < 0));

    printf("Bitwise Operators(��Ʈ ������):\n");
    printf("Bitwise AND: %d\n", a & b);
    printf("Bitwise OR: %d\n", a | b);
    printf("Bitwise XOR: %d\n", a ^ b);
    printf("Bitwise NOT (a): %d\n", ~a);

    return 0;
}