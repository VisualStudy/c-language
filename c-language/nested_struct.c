#include <stdio.h>
#include <string.h>

// �ּ� ������ ��� ����ü
struct Address
{
    char city[20];
    int code;
};

// ��� ������ ��� ����ü
struct Person
{
    char name[20];
    int age;
    struct Address addr; // ����ü �� ����ü
};

int main(void)
{
    struct Person p1;

    // ���ڿ��� ���� �ʱ�ȭ
    strcpy(p1.name, "Robin");
    p1.age = 25;
    strcpy(p1.addr.city, "Suncheon");
    p1.addr.code = 34512;

    // ���
    printf("�̸�: %s\n", p1.name);
    printf("����: %d\n", p1.age);
    printf("����: %s\n", p1.addr.city);
    printf("���� ��ȣ: %d\n", p1.addr.code);

    return 0;
}