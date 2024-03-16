#include <stdio.h>

int main(void)
{
    char buffer[80] = { NULL };

    gets(buffer);

    puts(buffer);

    return 0;
}