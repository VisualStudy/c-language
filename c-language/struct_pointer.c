#include <stdio.h>
#include <string.h>

struct Student
{
    char name[20];
    int age;
};

int main(void)
{
    struct Student s;
    struct Student *p = &s;
    strcpy((*p).name, "raba");
    (*p).age = 20;


    printf("�̸�: %s\n", (*p).name);
    printf("����: %d\n", p->age); // �̷� ��ĵ� ����

    return 0;
}