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
    printf("����!! ���� �հ�� %d�̤�r.", sum);

    return 0;
}