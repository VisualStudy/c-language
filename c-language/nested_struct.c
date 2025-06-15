#include <stdio.h>
#include <string.h>

// 주소 정보를 담는 구조체
struct Address
{
    char city[20];
    int code;
};

// 사람 정보를 담는 구조체
struct Person
{
    char name[20];
    int age;
    struct Address addr; // 구조체 안 구조체
};

int main(void)
{
    struct Person p1;

    // 문자열과 숫자 초기화
    strcpy(p1.name, "Robin");
    p1.age = 25;
    strcpy(p1.addr.city, "Suncheon");
    p1.addr.code = 34512;

    // 출력
    printf("이름: %s\n", p1.name);
    printf("나이: %d\n", p1.age);
    printf("도시: %s\n", p1.addr.city);
    printf("우편 번호: %d\n", p1.addr.code);

    return 0;
}