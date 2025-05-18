#include <stdio.h>

struct Student 
{
    char name[50];
    int age;
    float average;
};

int main(void)
{
    struct Student s1 = {"홍길동", 20, 88.5};

    printf("학생 이름: %s\n", s1.name);
    printf("학생 나이: %d\n", s1.age);
    printf("학생 평균 점수: %.2f\n", s1.average);

    return 0;
}