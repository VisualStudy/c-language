#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char dst[40];
    char src[20];
    int i;
    int j;
    int _ = 0;

    printf("���ڿ� �迭 dst�� ������ ����: ");
    _ = scanf("%s", dst);
    printf("���ڿ� �迭 src�� ������ ����: ");
    _ = scanf("%s", src);

    for (i = 0; dst[i] != '\0'; i++)
    {

    }

    for (j = 0; src[j] != '\0'; j++)
    {
        dst[i + j] = src[j];
    }
    dst[i + j] = '\0';

    printf("���ڿ� ���� Ȯ�� ���: %s\n", dst);

    return 0;
}