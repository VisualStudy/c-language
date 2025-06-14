#include <stdio.h>

int main(void)
{
    FILE *fp;
    int a = 10, b = 20, c = 30;
    int x, y, z;

    // 1. ���� ���� ���� ����
    fp = fopen("data.txt", "w"); // "w" = write
    if (fp == NULL)
    {
        printf("���� ���� ����!\n");
        return 1; // ������ ����
    }

    // 2. ���Ͽ� ������ ����
    fprintf(fp, "%d %d %d\n", a, b, c);
    fclose(fp); // ���� �ݱ�

    // 3. ���� �б� ���� �ٽ� ����
    fp = fopen("data.txt", "r"); // "r" = read
    if (fp == NULL)
    {
        printf("���� ���� ����!\n");
        return 1;
    }

    // 4. ���Ͽ��� ������ �б�
    fscanf(fp, "%d %d %d", &x, &y, &z);
    printf("�о�� ��: %d %d %d\n", x, y, z);

    fclose(fp); // ���� �ݱ�

    return 0;
}