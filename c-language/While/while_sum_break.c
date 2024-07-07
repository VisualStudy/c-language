#include <stdio.h>

int main(void)
{
    int goal = 22;
    int sum = 0;

    int i = 1;
    while (i <= 10)
    {
        sum += i;

        if (sum >= goal)
        {
            break;
        }

        i++;
    }

    printf("1부터 %d까지의 합은 %d이고, ", i, sum);
    printf("목표치 %d이상을 달성했습니다.\n", goal);

    return 0;
}