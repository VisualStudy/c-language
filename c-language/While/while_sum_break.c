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

    printf("1���� %d������ ���� %d�̰�, ", i, sum);
    printf("��ǥġ %d�̻��� �޼��߽��ϴ�.\n", goal);

    return 0;
}