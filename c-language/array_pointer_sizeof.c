#include <stdio.h>

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    printf("sizeof(arr) = %zu\n", sizeof(arr));
    printf("sizeof(p) = %zu\n", sizeof(p));
    printf("sizeof(*arr) = %zu\n", sizeof(*arr));
    printf("sizeof(*p) = %zu\n", sizeof(*p));
    printf("arr == &arr[0]? %s\n", (arr == &arr[0]) ? "true" : "false");
    printf("arr + 1 == &arr[1]? %s\n", ((arr + 1) == &arr[1]) ? "true" : "false");

    return 0;
}