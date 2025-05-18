#include <stdio.h>

typedef struct
{
    char name[20];
    int score;
} Student;

// 함수 선언
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

// 출력 함수
void PrintStudent(Student s)
{
    printf("이름: %s, 점수: %d, 등급: %s\n", s.name, s.score, GetGrade(s.score));
}

// 점수에 따른 등급 반환 함수
const char* GetGrade(int score)
{
    return (score >= 90) ? "우수" : "보통";
}