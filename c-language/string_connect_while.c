#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NULLWORD '\0'

void mystrcat(char a[], char b[]);

int main(void)
{
    char dst[40];
    char src[20];

    printf("���ڿ� �迭 dst�� ������ ����: ");
    scanf("%s", dst);
    printf("���ڿ� �迭 src�� ������ ����: ");
    scanf("%s", src);

    mystrcat(dst, src);

    printf("���ڿ� ���� Ȯ�� ���: %s\n", dst);

    return 0;
}

void mystrcat(char a[], char b[])
{
    int i = 0;
    int j;

    while(a[i] != NULLWORD)
    {
        i++;
    }

    for(j = 0; b[j] != NULLWORD; j++)
    {
        a[i + j] = b[j];
    }

    a[i + j] = NULLWORD;
}