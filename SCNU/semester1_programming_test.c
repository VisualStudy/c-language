#include <stdio.h>

void function(int arr[], int *a, int arr2[])
{
    arr = *a + *b;
}

int main(void)
{
    int arr[3] = {3, 5, 7};
    int a = 6;
    int *p = a;
    int *pa = arr;
    int *pb = &arr[1];

    function(*pa, *p, *pb);
    
    printf("%d", arr[0]);


    return 0;
}