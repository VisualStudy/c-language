#include <stdio.h>

int main(void)
{
    FILE *fp;

    fp = fopen("file.txt", "w");
    if (fp == NULL)
    {
        printf("���� ���� ����\n");
        return 1;
    }

    fprintf(fp, "Hello, C file I/O!\n");
    fprintf(fp, "�� ��° ���Դϴ�.\n");

    fclose(fp);

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("���� ���� ����\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}