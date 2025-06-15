#include <stdio.h>
#include <string.h> // strcpy 함수 사용을 위해 필요

// 구조체 정의
struct book
{
    char title[50]; // 문자열 멤버
    int year;
};

int main(void)
{
    struct book b1;

    // 문자열 복사 (strcpy로 구조체 멤버에 문자열 대입)
    strcpy(b1.title, "C# 교과서 개정판");
    b1.year = 2025;

    // 출력
    printf("책 제목: %s\n", b1.title);
    printf("출판 연도: %d\n", b1.year);

    return 0;
}

