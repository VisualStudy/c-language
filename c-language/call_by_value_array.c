#include <stdio.h>

void shiftArr(int array[]);

int main(void)
{
    int a[3] = {10, 20, 30};

    printf("초기 배열의 값: a[0] = %d, a[1] = %d, a[2] = %d\n\n", a[0], a[1], a[2]);

    shiftArr(a);

    for (int i = 0; i < 3; i++)
    {
        printf("메인 함수 안 배열 a[%d]의 값: %d\n", i, a[i]);
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
        printf("shiftArr 함수 안 배열[%d]의 값: %d\n", i, array[i]);
    }
}