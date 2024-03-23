#include <stdio.h>

int main(void)
{
    int x = 3;
    
    int y = x++;
    // int y = x;
    // x++;

    printf("%d\n", y); // 3
    printf("%d\n", x); // 4

    return 0;
}