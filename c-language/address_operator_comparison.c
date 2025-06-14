#include <stdio.h>

int main(void)
{
    int arr[3] = {10, 20, 30};
    int *p = arr; // �迭 �̸��� �迭�� ���� �ּ� -> �����ͷ� ��� ����

    printf("arr[0] = %d\n", arr[0]); // [ ]: �迭�� ù ��° "��"
    printf("*(arr) = %d\n", *(arr)); // *: �迭 �̸��� �ּ� -> �� �ּ��� ��
    printf("*p = %d\n", *p); // *: p�� arr�� ���� -> arr[0]
    
    printf("&arr[0] = %p\n", (void *)&arr[0]); // &: ù ��° ����� �ּ�
    printf("arr = %p\n", (void *)arr); // arr ��ü�� �ּ� (== &arr[0]) ù ��° �ε���!
    printf("p = %p\n", (void *)p); // p�� arr�� ������ �ּ� ������ ��

    printf("arr[1] = %d\n", arr[1]); // [ ]: �� ��° ����� ��
    printf("*(arr + 1) = %d\n", *(arr + 1)); // * + : �� ��° ����� ��
    printf("p[2] = %d\n", p[2]); // [ ]: �����͵� �迭ó�� ���� ����

    return 0;
}