#include <stdio.h>

int main(void)
{
    int arr[7];
    int i, j, min, temp;

    arr[0] = 0;
    arr[1] = 10;
    arr[2] = 100;
    arr[3] = 70;
    arr[4] = 90;
    arr[5] = 20;
    arr[6] = 40;

    for(i = 0; i < 6; i++)
    {
        min = i;

        for(j = i + 1; j < 7; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for(i = 0; i < 7; i++)
    { 
         printf("%d", arr[i]);
    }

    return 0;
}