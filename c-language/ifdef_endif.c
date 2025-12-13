#include <stdio.h>
#define DEBUG

int main(void)
{
#ifdef DEBUG
    printf("Debug mode ON!\n");
#endif
    printf("Program running\n");

    return 0;
}