#define _CRT_SECURE_NO_WARNINGS // scanf ���� ��� ����
#include <stdio.h>

int main(void) 
{
    int a, b, r;
    scanf("%d %d", &a, &b);
    r = a % b;
    printf("%d", r);

    return 0;
}