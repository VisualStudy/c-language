#include <stdio.h>

typedef struct {
    char *name;
    int age;
    char *subjects[3];
} Student;

int main(void)
{
    Student students[2] =
    {
        {
            "Alice", 20, {"Math", "Physics", "English"}
        },
        {
            "Bob", 22, {"C Programming", "Data Structure", "OS"}
        }
    };

    Student *pStudents = students;
    Student ** ppStudents = &pStudents;

    for (int i = 0; i < 2; i++)
    {
        printf("이름: %s\n", (*ppStudents)[i].name);
        printf("나이: %d\n", (*ppStudents)[i].age);

        printf("수강 과목:\n");

        for (int j = 0; j < 3; j++) 
        {
            printf("  - %s\n", (*ppStudents)[i].subjects[j]);
        }

        printf("-----------------------------\n");
    }

    return 0;
}