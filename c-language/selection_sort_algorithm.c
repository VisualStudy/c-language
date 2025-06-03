#include <stdio.h>

int main(void)
{
    int intNum[5] = {2, 3, 1, 5, 4};
    int i, j, temp;

    for (i = 0; i < 5 - 1; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (intNum[i] > intNum[j])
            {
                temp = intNum[i];
                intNum[i] = intNum[j];
                intNum[j] = temp;
            }
        }
    }

    // OUTPUT
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", intNum[i]);
    }

    return 0;
}