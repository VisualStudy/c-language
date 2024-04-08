#include <stdio.h>

int main(void) 
{
    int a = 5, b = 10, c = 15, d = 30, result; 
    result = a * 3 + b > d || c - b / a <= d && 1; 
    // result = (a * 3) + (b > d) || c - (b / a) <= d && 1;
    // result = (((a * 3) + b) > d) || (c - (b / a)) <= d && 1;
    // result = (((15) + 10) > 30) || (13) <= 30 && 1;
    // result = FALSE || TRUE && 1;
    // result = TRUE && 1(TRUE); => TRUE = 1
    printf("%d\n", result); // 1
}