#include <stdio.h>

void shiftArr(int array[]);

int main(void)
{
    int a[3] = {10, 20, 30};

    printf("�ʱ� �迭�� ��: a[0] = %d, a[1] = %d, a[2] = %d\n\n", a[0], a[1], a[2]);

    shiftArr(a);

    for (int i = 0; i < 3; i++)
    {
        printf("���� �Լ� �� �迭 a[%d]�� ��: %d\n", i, a[i]);
    }

    return 0;
}

void shiftArr(int array[])
{
    int temp;
    
    temp = array[2];
    array[2] = array[1];
    array[1] = array[0];
    array[0] = temp;

    for (int i = 0; i < 3; i++)
    {
        printf("shiftArr �Լ� �� �迭[%d]�� ��: %d\n", i, array[i]);
    }
}