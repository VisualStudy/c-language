#include <stdio.h>
#define N 8


int main(void)
{
    int arr[N] = { 5, 10, 192, 141, 1444, 999, 0, 1};
    int i, j, temp;

    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }
    for (i = 0; i < N; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}