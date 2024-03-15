// scanf_multi_line.c
#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지 
#include <stdio.h>

int main(void)
{
    char name[20];
    int age;
    char nick[20];
    int _;

    printf("입력\n----\n");
    printf("이름: "); _ = scanf(" %s", name); // 서식 지정자 앞에 공백 하나 추가 
    printf("나이: "); _ = scanf(" %d", &age);
    printf("별명: "); _ = scanf(" %s", nick);

    printf("\n출력\n----\n");
    printf("이름: %s\n", name);
    printf("나이: %d\n", age);
    printf("별명: %s\n", nick);

    return 0;
}