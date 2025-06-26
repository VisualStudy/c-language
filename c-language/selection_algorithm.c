#include <stdio.h>

int main(void)
{
    int arr[8] = { 5, 10, 192, 141, 1444, 999, 0, 1};
    int i, j, temp;

    for (i = 0; i < 7; i++)
    {
        for (j = i + 1; j < 8; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }
    for (i = 0; i < 8; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}