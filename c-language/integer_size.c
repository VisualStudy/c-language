#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("short: %lld\n", sizeof(short));
    printf("int: %lld\n", sizeof(int));
    printf("long: %lld\n", sizeof(long));
    printf("unsigned: %lld\n", sizeof(unsigned int));

    return EXIT_SUCCESS;
}
