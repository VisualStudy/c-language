#include <stdio.h>

int main(void)
{
    // input
    int scores[] = { 100, 75, 50, 37, 90, 95 };
    int n = sizeof(scores) / sizeof(int);
    int sum = 0;

    // process
    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= 80)
        {
            sum += scores[i];
        }
    }

    // output
    printf("%d명의 점수 중 80점 이상의 총점: %d\n", n, sum);

    return 0;
}