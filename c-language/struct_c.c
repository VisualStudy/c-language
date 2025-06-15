#include <stdio.h>

// 구조체 정의
struct Student
{
    char name[20];
    int age;
    double grade;
};

int main(void)
{
    // 구조체 변수 선언 및 초기화
    struct Student s1 = {"Alice", 20, 3.8};

    // 구조체 멤버 접근
    printf("이름: %s\n", s1.name);
    printf("나이: %d\n", s1.age);
    printf("학점: %.1f\n", s1.grade);

    return 0;
}