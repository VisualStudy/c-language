#include <stdio.h>
#include <string.h> // strcpy �Լ� ����� ���� �ʿ�

// ����ü ����
struct book
{
    char title[50]; // ���ڿ� ���
    int year;
};

int main(void)
{
    struct book b1;

    // ���ڿ� ���� (strcpy�� ����ü ����� ���ڿ� ����)
    strcpy(b1.title, "C# ������ ������");
    b1.year = 2025;

    // ���
    printf("å ����: %s\n", b1.title);
    printf("���� ����: %d\n", b1.year);

    return 0;
}

