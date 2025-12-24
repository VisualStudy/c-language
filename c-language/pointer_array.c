#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("UnderstandingPointer\n");
    printf("%d\n", arr[1]);
    printf("%d\n", p[1]);
    printf("%d\n", *(p + 1));

    return EXIT_SUCCESS;
}