#include <stdio.h>

int main(void)
{
    int i = 0;
    int arr[5] = { 10, 20, 30, 40, 50 };

    int* p = &arr; //&arr[0]; &arr[2];

    printf("%d %d %d %d %d\n", *p, *(p + 1), *(p + 2), *(p + 3), *(p + 4));

    for (i = 0; i < 5; i++)
    {
        printf("이것은 배열: %d\n", *(p + i));
    }

    for (i = 0; i < 5; i++)
    {
        printf("이것은 배열: %d\n", arr[i]);
    }

    return 0;
}