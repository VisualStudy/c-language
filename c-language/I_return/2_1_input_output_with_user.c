#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char name[100];
    printf("당신의 이름을 공백 없이 입력하시오");
    scanf("%s", name);
    
    printf("당신의 이름: %s", name);

    return 0;
}