#include <stdio.h>
#define SIZE 5

// 함수 원형
void array(int arr[], int size);

int main(void)
{
    int data[SIZE] = {3, 6, 9, 12, 15};

    // 배열을 함수에 전달
    array(data, SIZE);

    return 0;
}

// 배열을 받아서 출력하는 함수
void array(int arr[], int size)
{
    printf("배열 요소: \n");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}