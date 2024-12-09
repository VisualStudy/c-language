#include <stdio.h>

int main(void)
{
    int a = 5, b = 3;
    
    printf("Arithmetic Operators(»ê¼ú ¿¬»êÀÚ):\n");
    printf("Addition(µ¡¼À): %d\n", a + b);
    printf("Subtraction(»¬¼À): %d\n", a - b);
    printf("Multiplication(°ö¼À): %d\n", a * b);
    printf("Division(³ª´°¼À): %d\n", a / b);
    printf("Modulus(³ª´« ÈÄ ³ª¸ÓÁö not ¸ò): %d\n\n", a % b);
    
    printf("Relational Operators(°ü°è ¿¬»êÀÚ):\n");
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n\n", a < b);

    printf("Logical Operators(³í¸® ¿¬»êÀÚ):\n");
    printf("a > 0 && b > 0: %d\n", (a > 0 && b > 0));
    printf("a > 0 || b < 0: %d\n\n", (a > 0 || b < 0));

    printf("Bitwise Operators(ºñÆ® ¿¬»êÀÚ):\n");
    printf("Bitwise AND: %d\n", a & b);
    printf("Bitwise OR: %d\n", a | b);
    printf("Bitwise XOR: %d\n", a ^ b);
    printf("Bitwise NOT (a): %d\n", ~a);

    return 0;
}