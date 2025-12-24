#include <stdio.h>
#include <stdlib.h>
#define TITLE "Understanding Pointer"

int main(int argc, char *argv[])
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf_s("%s\n", TITLE);
    printf_s("%d\n", arr[1]);
    printf_s("%d\n", p[1]);
    printf_s("%d\n", *(p + 1));
    // CTRL + SHIFT + 방향키: 자기 자신 탐색

    return EXIT_SUCCESS;
}