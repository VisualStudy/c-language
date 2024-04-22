#include <stdio.h>

int main(void)
{
    int input = 101110; // 2 + 4 + 8 + 32 = 46
    int di = 1;
    int sum = 0;
    while (1)
    {
        if (input == 0)
        {
            break;
        }
        sum = sum + (input % 10) * di;
        di = di * 2;
        input /= 10;
    }
    printf("\"%d\'", sum);

    return 0;
}