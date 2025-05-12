#include <stdio.h>   

int main(void)   //���峭 ��Ʈ: ������ �迭 vs �迭 ������
{
    // ������ �迭: int* 3��¥�� �迭
    int a = 10;
    int b = 20;
    int c = 30;
    int *parr[3] = {&a, &b, &c};

    printf ("== ������ �迭 (int *arr[3] ==\n");
    for (int i = 0; i < 3; i++)
    {
        printf("parr[%d] points to value: %d\n", i, *parr[i]);
    }

    // �迭 ������: int [3] �迭�� ����Ű�� ������
    int arr[3] = {100, 200, 300};
    int (*p)[3] = &arr;

    printf("\n== �迭 ������ (int (*p)[3]) ==\n");
    for (int i = 0; i < 3; i++)
    {
        printf("(*p)[%d] = %d\n", i, (*p)[i]);
    }

    return 0;
}