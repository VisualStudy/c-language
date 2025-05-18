#include <stdio.h>

typedef struct
{
    char name[20];
    int score;
} Student;

// �Լ� ����
void PrintStudent(Student s);
const char* GetGrade(int score);

int main(void)
{
    Student s1 = { "yeastyeast", 80 };
    Student s2 = { "Parkkuro", 100 };

    PrintStudent(s1);
    PrintStudent(s2);

    return 0;
}

// ��� �Լ�
void PrintStudent(Student s)
{
    printf("�̸�: %s, ����: %d, ���: %s\n", s.name, s.score, GetGrade(s.score));
}

// ������ ���� ��� ��ȯ �Լ�
const char* GetGrade(int score)
{
    return (score >= 90) ? "���" : "����";
}