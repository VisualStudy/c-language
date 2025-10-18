#include <stdio.h>

int main(void)
{
    int num = 10;
    printf("전위 증감: %d\n", ++num);
    printf("후위 증감: %d\n", num++);
    printf("후위 증감 확인: %d\n", num);

    return 0;
}