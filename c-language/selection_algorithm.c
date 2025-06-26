#include <stdio.h>

int main(void)
{
    int arr[8] = { 5, 10, 192, 141, 1444, 999, 0, 1};
    int i, j, min, temp;

    for (i = 0; i < 7; i++)
    {
        min = i;

        for (j = i + 1; j < 8; j++)
        {
            if (arr[min] > arr[j])
            {
               min = j;
            }
        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    for (i = 0; i < 8; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}