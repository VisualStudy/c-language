#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100];
    int age;
} Person;

int main(void)
{
    Person person;

    strcpy(person.name, "Jane Doe");
    person.age = 30;

    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);

    return 0;
}
