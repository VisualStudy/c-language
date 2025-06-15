#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE ���ǵǾ� ����

int main(void)
{
    FILE *fp;
    char ch;
    char line[100];

    // 1. ���ڿ� ������ ���Ͽ� ���� (fputs)
    fp = fopen("sample.txt", "w");
    if (fp == NULL)
    {
        perror("���� ���� ����");
        return EXIT_FAILURE;
    }

    fputs("Hello, world!\n", fp); // �� ���� ���ڿ� ����
    fputs("This is a second line.\n", fp);
    fclose(fp);

    // 2. ���� ������ �б� (fgetc)
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        perror("���� ���� ����");
        return EXIT_FAILURE;
    }

    printf("=== fgetc ��� ===\n");
    while(!feof(fp)); // ���� 1�� �б�
    if (ch != EOF) // ���� EOF Ȯ���� ���� ����� ����
    {
        putchar(ch); // ȭ�鿡 ���
    }
    fclose(fp);

    // 3. �� ������ �б� (fgets)
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        perror("���� ���� ����");
        return EXIT_FAILURE;
    }

    printf("\n=== fgets ��� ===\n");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line); // �� ���� ���
    }
    fclose(fp);

    return EXIT_SUCCESS; // return 0 ��ü
}