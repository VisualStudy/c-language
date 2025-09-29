#include <stdio.h>

int main(void)
{
    int i = 100;
    float j = 123.45678;
    printf("%d %x %o\n", i, i, i);
    printf("%05d %5d\n", i, i);
    printf("%7.1f %f\n", j, j);
    
    return 0;
}