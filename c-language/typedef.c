#include <stdio.h>
#include <string.h>

// typedef�� ����ü�� ��Ī �ο�
typedef struct Student
{
    char name[20];
    int age;
    double score;
} STUDENT;

int main(void)
{
    STUDENT s1;

    strcpy(s1.name, "Alice");
    s1.age = 20;
    s1.score = 90.0;

    return 0;
}