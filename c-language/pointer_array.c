#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("pointer 이해하기\n");
    printf("%d\n", arr[1]);
    printf("%d\n", p[1]);
    printf("%d\n", *(p + 1));

    return 0;
}