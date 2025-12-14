#include <stdio.h>

int main(void)
{
    int x;
    int *p;
    int **pp;

    x = 10;
    p = &x;
    pp = &p;

    printf("x의 값: %d\n", x);
    printf("p의 값(x의 주소): %d\n", p);
    printf("p가 가리키는 주소의 값: %d\n", *p);
    printf("pp의 값(p의 주소): %d\n", pp);
    printf("pp가 가리키는 주소의 첫번째 값: %d\n", *pp);
    printf("pp가 가리키는 주소의 두번째 값: %d\n", **pp);
    
    return 0;
}