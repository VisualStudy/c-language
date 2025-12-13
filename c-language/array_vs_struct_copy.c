/*
    배열 복사 vs 구조체 복사 원리를 한 파일로 정리한 예제

    핵심 포인트
    1) 배열은 대입(=) 불가 → 원소 단위/문자열 복사 필요
    2) 구조체는 같은 타입이면 대입(=) 가능 → 통째 복사
    3) 구조체 안에 배열이 있어도 통째 복사됨
    4) 구조체 안에 포인터가 있으면 “주소만” 복사되는 얕은 복사(shallow copy) 발생
*/
#include <stdio.h>
#include <string.h>

typedef struct 
{
    int x;
    int y;
} Point;

typedef struct 
{
    char name[10];
    int age;
} Person;

typedef struct 
{
    int *ptr;
} Data;

static void my_strcpy(char dst[], const char src[])
{
    int i = 0;
    while((dst[i] = src[i]) != '\0')
    {
        i++;
    }
} 

int main(void)
{
    /* =========================================================
       1) 배열: 대입(=) 불가, 직접 복사해야 함
       ========================================================= */
    {
        char src[6] = "Hello"; // 6칸 null 문자 포함
        char dst1[6];
        char dst2[6];

        // dst1 = src; 컴파일 오류: 배열은 대입 불가(이 줄은 주석 해제하면 에러 남)

        // 방법 1: 직접 구현한 my_strcpy로 복사
        my_strcpy(dst1, src);

        // 방법 2: 표준 strcpy로 복사(원리 동일: '\0'까지 복사)
        strcpy(dst2, src);

        printf("[Array Copy]\n");
        printf("src = %s\n", src);
        printf("dst1 = %s (my_strcpy)\n", dst1);
        printf("dst2 = %s (strcpy)\n\n", dst2);
    }

    /* =========================================================
       2) 구조체: 같은 타입이면 대입(=)으로 통째 복사 가능
       ========================================================= */
    {
        Point p1 = {10, 20};
        Point p2;

        p2 = p1; // 구조체 통째 복사 가능

        printf("[Struct Copy - same type]\n");
        printf("p1 = (%d, %d)\n", p1.x, p1.y);
        printf("p2 = (%d, %d) <-- p2 = p1\n\n", p2.x, p2.y);
    }

    /* =========================================================
       3) 구조체 안에 배열이 있어도 통째 복사됨
       ========================================================= */
    {
        Person a = {"Hello", 30};
        Person b;

        b = a; // name 배열 포함 전체 복사

        printf("[Struct Copy - includes internal array]\n");
        printf("a = {name = %s, age = %d}\n", a.name, a.age);
        printf("b = {name = %s, age = %d} <-- b = a\n\n", b.name, b.age);
    }

    /* =========================================================
       4) 주의: 구조체에 포인터가 있으면 “주소만” 복사됨(얕은 복사)
       ========================================================= */
    {
        int x = 10;
        Data d1, d2;
        d1.ptr = &x;

        d2 = d1; // 대입은 되지만, ptr은 "주소"만 복사됨 → 둘 다 같은 x를 가리킴

        printf("[Struct Copy Pitfall - shallow copy with pointer]\n");
        printf("  before: x=%d, *d1.ptr=%d, *d2.ptr=%d\n", x, *d1.ptr, *d2.ptr);

        *d2.ptr = 99; // d2로 바꿨는데 x가 바뀜(공유 중이니까)

        printf("  after : x=%d, *d1.ptr=%d, *d2.ptr=%d  (same target)\n\n", x, *d1.ptr, *d2.ptr);
    }

    /* =========================================================
       5) 서로 다른 구조체 타입끼리는 대입 불가(참고)
       =========================================================
       struct A { int x; int y; };
       struct B { int x; int y; };
       struct A a; struct B b;
       b = a; // 타입이 다르므로 컴파일 오류
    */

    return 0;
}