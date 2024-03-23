#include <stdio.h>

int main(void)
{
    int num = 100;
    ++num;
    printf("%d\n", num); // 101

    --num;
    printf("%d\n", num); // 100

    return 0;
}
