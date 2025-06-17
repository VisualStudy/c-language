#include <stdio.h>

struct Body
{
    float height;
    float weight;
};

struct People
{
    char name[100];
    int age;
    struct Body b;
};



int main(void)
{
    struct People p;
    
    printf("name: ");
    scanf("%s", p.name);
    printf("age: ");
    scanf("%d", &p.age);
    printf("height: ");
    scanf("%f", &p.b.height);
    printf("weight: ");
    scanf("%f", &p.b.weight);

    printf("\n\nname: %s, age: %d, height: %.2f, weight: %.2f\n", p.name, p.age, p.b.height, p.b.weight);

    return 0;
}