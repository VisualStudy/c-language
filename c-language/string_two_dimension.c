#include <stdio.h>
#include <string.h>

struct people {
    int age;
    char name[10];
    double grade;
};

int main(void)
{
    char str[3][6] = {"Hello", "World", "minja"};
    struct people minjae;
    minjae.age = 10;
    strcpy(minjae.name, "chos");

    printf("%s\n", str[2]);

    return 0;
}