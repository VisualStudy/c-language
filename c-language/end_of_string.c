#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("\'\"\'\"\n");
    printf("%\n");
    printf("%%\n");
    printf("1) 100%\n");
    printf("2) 100%%\n");
    int size = strlen("Minjae");
    printf("%d\n", size);
    int c;
    while ((c = getchar()) != -1)
    {
        putchar(c);
    }

    return 0;
}