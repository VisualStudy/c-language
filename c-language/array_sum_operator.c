#include <stdio.h>

int main(void)
{
    int sum_array[5] = { 10, 20, 30, 40, 50 };

    int sum = 0;

    int i;
    for (i = 0; i < 5; i++)
    {
        sum += sum_array[i];
    }
    printf("오와!! 최종 합계는 %d이ㄷr.", sum);

    return 0;
}