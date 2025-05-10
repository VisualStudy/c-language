#include <stdio.h>

int main() {
    printf("== �⺻ Ÿ�� ũ�� (����Ʈ ����) ==\n");

    printf("char               : %zu bytes\n", sizeof(char));
    printf("short              : %zu bytes\n", sizeof(short));
    printf("int                : %zu bytes\n", sizeof(int));
    printf("long               : %zu bytes\n", sizeof(long));
    printf("long long          : %zu bytes\n", sizeof(long long));
    printf("float              : %zu bytes\n", sizeof(float));
    printf("double             : %zu bytes\n", sizeof(double));
    printf("long double        : %zu bytes\n", sizeof(long double));

    printf("\n== ������ Ÿ�� ũ�� (����Ʈ ����) ==\n");

    printf("char*              : %zu bytes\n", sizeof(char*));
    printf("int*               : %zu bytes\n", sizeof(int*));
    printf("void*              : %zu bytes\n", sizeof(void*));
    printf("float*             : %zu bytes\n", sizeof(float*));
    printf("double*            : %zu bytes\n", sizeof(double*));

    printf("\n== �迭 Ÿ�� ũ�� ���� ==\n");

    char arr1[10];
    int arr2[10];
    double arr3[10];

    printf("char arr[10]       : %zu bytes\n", sizeof(arr1));
    printf("int arr[10]        : %zu bytes\n", sizeof(arr2));
    printf("double arr[10]     : %zu bytes\n", sizeof(arr3));

    return 0;
}
