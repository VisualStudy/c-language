#include <stdio.h>

int main(void)
{
    int i = 3;
    int j = 5;
    int k = 0;

    //k = ++i - j--; // -1
    ++i;
    k = i - j; // -1
    j--;

    printf("������ :  \\\"%d\"\\", k);

    return 0;
}