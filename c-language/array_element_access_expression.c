#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};

    printf("== �迭 �ε��� ��� ==\n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\n== ������ ���� ��� ==\n");
    for (int i = 0; i < 5; i++)
    {
        printf("*(arr + %d) = %d\n", i, *(arr + i));
    }

    printf("\n== Ư���� ǥ���� ���� ==\n");
    printf("2[arr] = %d\n", 2[arr]); // arr[2]�� ����

    return 0;
}