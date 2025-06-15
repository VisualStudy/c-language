#include <stdio.h>
#include <string.h>

// 구조체 정의
struct Student
{
    char name[20];
    int age;
    double score;
};

int main(void)
{
    struct Student students[3];

    // 값 입력
    strcpy(students[0].name, "Alice");
    students[0].age = 20;
    students[0].score = 91.5;

    strcpy(students[1].name, "Robin");
    students[1].age = 25;
    students[1].score = 100;

    strcpy(students[2].name, "John");
    students[2].age = 37;
    students[2].score = 88;

    // 출력
    for (int i = 0; i < 3; i++)
    {
        printf("학생 %d\n", i + 1);
        printf("이름: %s\n", students[i].name);
        printf("나이: %d\n", students[i].age);
        printf("점수: %.1f\n\n", students[i].score);
    }

    return 0;
}