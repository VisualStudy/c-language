#include <stdio.h>
#include <string.h>

// ����ü ����
struct Student
{
    char name[20];
    int age;
    double score;
};

int main(void)
{
    struct Student students[3];

    // �� �Է�
    strcpy(students[0].name, "Alice");
    students[0].age = 20;
    students[0].score = 91.5;

    strcpy(students[1].name, "Robin");
    students[1].age = 25;
    students[1].score = 100;

    strcpy(students[2].name, "John");
    students[2].age = 37;
    students[2].score = 88;

    // ���
    for (int i = 0; i < 3; i++)
    {
        printf("�л� %d\n", i + 1);
        printf("�̸�: %s\n", students[i].name);
        printf("����: %d\n", students[i].age);
        printf("����: %.1f\n\n", students[i].score);
    }

    return 0;
}