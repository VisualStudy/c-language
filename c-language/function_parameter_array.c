#include <stdio.h>
#define SIZE 5

// �Լ� ����
void array(int arr[], int size);

int main(void)
{
    int data[SIZE] = {3, 6, 9, 12, 15};

    // �迭�� �Լ��� ����
    array(data, SIZE);

    return 0;
}

// �迭�� �޾Ƽ� ����ϴ� �Լ�
void array(int arr[], int size)
{
    printf("�迭 ���: \n");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}