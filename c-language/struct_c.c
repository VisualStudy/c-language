#include <stdio.h>

// ����ü ����
struct Student
{
    char name[20];
    int age;
    double grade;
};

int main(void)
{
    // ����ü ���� ���� �� �ʱ�ȭ
    struct Student s1 = {"Alice", 20, 3.8};

    // ����ü ��� ����
    printf("�̸�: %s\n", s1.name);
    printf("����: %d\n", s1.age);
    printf("����: %.1f\n", s1.grade);

    return 0;
}