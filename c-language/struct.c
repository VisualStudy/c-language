#include <stdio.h>

struct Student 
{
    char name[50];
    int age;
    float average;
};

int main(void)
{
    struct Student s1 = {"ȫ�浿", 20, 88.5};

    printf("�л� �̸�: %s\n", s1.name);
    printf("�л� ����: %d\n", s1.age);
    printf("�л� ��� ����: %.2f\n", s1.average);

    return 0;
}