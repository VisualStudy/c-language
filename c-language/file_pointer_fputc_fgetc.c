#include <stdio.h>

int main(void)
{
    FILE *fp;
    char ch;

    // ���Ͽ� ����(�� �� ����: ĳ����) ����
    fp = fopen("char_test.txt", "w");
    if (fp == NULL)
    {
        printf("���� ���� ����!\n");
        return 1;
    }

    printf("���ڿ��� �Է��ϼ��� (�������� Enter):  ");
    while ((ch = getchar()) != '\n') // ǥ�� �Է¿��� ���� 1���� �Է�
    {
        fputc(ch, fp); // ���Ͽ� ���� 1���� ����
    }
    fclose(fp);

    // ���Ͽ��� ���� �б�
    fp - fopen("char_test.txt", "r");
    if (fp == NULL)
    {
        printf("���� �б� ����!\n");
        return 1;
    }

    printf("���Ͽ��� ���� ����: ");
    while ((ch = fgetc(fp)) != EOF) // ���Ͽ��� �� ���ھ� �о� ���
    {
        putchar(ch);
    }
    printf("\n");

    fclose(fp);

    return 0;
}