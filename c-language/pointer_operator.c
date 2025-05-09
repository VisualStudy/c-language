#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30 , 40 ,50};
    int *p = arr; // �迭 �̸��� ù ��° ���(����: element)�� �ּ�

    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("*(p + 2) = %d\n", *(p + 2));
    printf("&arr[2] = %p\n", (void*)&arr[2]);
    printf("arr + 2 = %p\n", (void*)(arr + 2));
    // (void*)�� Ÿ�� �𸣴� �����ͷ� ���� -> %p�� ����. ��� ����.
    printf("*&arr[2] = %d\n", *&arr[2]);
    printf("*&*&arr[2] = %d\n", *&*&arr[2]);
    printf("*(&arr[2]) = %d\n", *(&arr[2]));

    // ������ �� ��
    int x = 42;
    printf("x = %d\n", x);
    printf("*&x = %d\n", *&x);
    printf("*&*&x = %d\n", *&*&x);

    //    ��� ���:
    //    arr[2] = 30
    //    *(arr + 2) = 30
    //    * (p + 2) = 30
    //    & arr[2] = 00000014A690FBF0
    //    arr + 2 = 00000014A690FBF0
    //    * &arr[2] = 30
    //    * &*&arr[2] = 30
    //    * (&arr[2]) = 30
    //    x = 42
    //    * &x = 42
    //    * &*&x = 42

    return 0;
}