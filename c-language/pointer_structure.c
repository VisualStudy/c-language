#include <stdio.h>

struct TAG
{
    int num;
    char name[100];
    double grade;
};
typedef struct TAG T;

int main(int argc, char* argv[])
{
    int x;
    int *p;
    int **q;
    struct TAG a1;
    T a2 = {1, "hello", 4.3};
    a1 = a2;
    
    printf("%.2f\n", a1.grade);

    x = 10;
    p = &x;
    q = &p;

    printf("%d\n%d\n%d\n", x, *p, **q);
    
    return 0;
}