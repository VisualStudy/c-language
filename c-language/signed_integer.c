#include <stdio.h>

int main(void)
{
    short s = 32767;
    int i = 2147483647;
    long l = 1234;
    long long ll = 1234;

    printf("short: %d\n", s);
    printf("int: %d\n", i);
    printf("long: %ld\n", l);
    printf("long long: %lld\n", ll);

    return 0;
}