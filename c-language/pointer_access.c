#include <stdio.h>

int main(void)
{
    char f[2][4] = {
        "abc",
        "def"
    };

    printf("%c\n", f[0][1]);
    printf("%c\n", *(f[0] + 1));

    return 0;
}