#include <stdio.h>
#define NULL '\0'

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

    while(a[i] != NULL)
    {
        i++;
    }

    for(j = 0; b[j] != NULL; j++)
    {
        a[i + j] = b[j];
    }

    a[i + j] = NULL;
}