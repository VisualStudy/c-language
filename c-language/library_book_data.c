#include <stdio.h>
#define LIMIT 100

struct book 
{
    char title[LIMIT];
    char author[LIMIT];
    int year;
    int price;
};

typedef struct book BOOK;

int _;

void InputBooks(BOOK b);

int main(void)
{
    BOOK b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;

    InputBooks(b1);
    PrintBooks(b1);
    InputBooks(b2);
    PrintBooks(b2);
    InputBooks(b3);
    PrintBooks(b3);
    InputBooks(b4);
    PrintBooks(b4);
    InputBooks(b5);
    PrintBooks(b5);
    InputBooks(b6);
    PrintBooks(b6);
    InputBooks(b7);
    PrintBooks(b7);
    InputBooks(b8);
    PrintBooks(b8);
    InputBooks(b9);
    PrintBooks(b9);
    InputBooks(b10);
    Print(b10);

    return 0;
}

void InputBooks(BOOK b)
{
    printf("책의 저자: ");
    _ = scanf("%s", b.author);
    printf("책의 이름: ");
    _ = scanf("%s", b.title);
    printf("출판 연도: ");
    _ = scanf("%d", &b.year);
    printf("가격: ");
    _ = scanf("%d", &b.price);
}

void PrintBooks(BOOK b)
{
    printf("책의 저자는 %s\n", b.author);
    printf("책의 이름은 %s\n", b.title);
    printf("책의 출판 연도는 %d\n", b.year);
    printf("책의 가격은 %d\n", b.price);
}