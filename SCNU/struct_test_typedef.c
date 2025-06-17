#include <stdio.h>

typedef struct people
{
    char name[100];
} MAN; 

int main(void)
{
    MAN a;
    scanf("%s", a.name);
    printf("%s", a.name);
    
    return 0;
}