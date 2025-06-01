#include <stdio.h>
#define N 5

int main(void)
{
    int data[] = {3, 2, 1, 5, 4};
    int i, j, temp;

    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (data[i] > data[j])
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");

    return 0;
}