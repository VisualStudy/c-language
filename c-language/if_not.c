#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

int main(void)
{
    int bln = false;

    if (!bln)
    {
        printf("bln: false(0) -> ! -> true(1)\n");
    }

    return EXIT_SUCCESS;
}