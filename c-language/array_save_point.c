#include <stdio.h>

int main(void)
{
    int numbers[3] = {10, 20, 30};

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
   
    return 0;
}