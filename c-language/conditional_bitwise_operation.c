#include <stdio.h>

main() {
    int num1 = 16, num2 = 80; 
    // num1 = 00010000, 
    // num2 = 01010000
    //        01000000 = 64
    printf("%d", num1 > num2 ? num1 & num2 : num1 ^ num2);
}