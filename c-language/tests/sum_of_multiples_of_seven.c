#include <stdio.h>

int main(void) 
{
    int i = 1, n = 0;
    
    while (i <= 50) 
    {
        if (i % 7 == 0) 
        {
            n += i;
        }
        i++;
    }
    printf("%d", n);

    return 0;
}