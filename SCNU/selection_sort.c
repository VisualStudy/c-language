#include <stdio.h>

int main(void)
{
    int sort[10] = {9, 18, 1, 37, 5, 8, 99, 10, 12, 3};
    int i, j, min, temp;
    for(i = 0; i < 9; i++)
    {
        min = i;
        for(j = i + 1; j < 10; j++)
        {
            if(sort[j] < sort[min])
            {
                min = j;
            }
        }
        temp = sort[i];
        sort[i] = sort[min];
        sort[min] = temp;
    }

    printf("정렬 결과: ");
    for(i = 0; i < 10; i++)
    {
        printf("sort[%d] = %d\n", i, sort[i]);
    }

    return 0;
}