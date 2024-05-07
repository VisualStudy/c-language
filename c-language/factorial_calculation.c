#include <stdio.h>

int main(void)
{
    int num = 1;
    for (int i = 1; ; i++)
    {
        num = num * i;
        if(i > 5)
            break;
    }
    
    printf("%d", num);

    return 0;
}