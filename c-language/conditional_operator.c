#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num = 3;

    const char* result = (num % 2 == 0) ? "even" : "odd";

    printf("%s\n", result);

    return EXIT_SUCCESS;
}