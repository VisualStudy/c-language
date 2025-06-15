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


    printf("이름: %s\n", (*p).name);
    printf("나이: %d\n", p->age); // 이런 방식도 가능

    return 0;
}