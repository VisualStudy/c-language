#include <stdio.h>

int main(void)
{
    char dst[40];
    char src[20];
    int i = 0; // �������� ���� �ð� �� �����Ͻ� ��� ������ ��������!
    int j;

    printf("���ڿ� �迭 dst�� ������ ����: ");
    scanf("%s", dst);
    printf("���ڿ� �迭 src�� ������ ����: ");
    scanf("%s", src);

    while (dst[i] != '\0')
    {
        i++;
    }

    for (j = 0; src[j] != '\0'; j++)
    {
        dst[i + j] = src[j];
    }
    dst[i + j] = '\0';

    printf("���ڿ� ���� Ȯ�� ���: %s\n", dst);

    return 0;
}
