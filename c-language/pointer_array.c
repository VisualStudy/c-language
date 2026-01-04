#include <stdio.h>
#include <stdlib.h>
#define TITLE "Understanding Pointer"

struct str {
    char name[100];
};

int main(int argc, char *argv[])
{
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;

    int *px;
    int str[] = {10, 20, 30, 40, 50};
    struct str *spx;
    struct str s;
    spx = &s;

    spx->name[0] = 'a';
    spx->name[1] = '\0';

    px = str;
    printf_s("%d\n", px[2]);

    printf_s("%s\n", TITLE);
    printf_s("%d\n", arr[1]);
    printf_s("%d\n", p[1]);
    printf_s("%d\n", *(p + 1));
    // CTRL + SHIFT + 방향키: 자기 자신 탐색
    // ALT + DRAG: MultiLine editing

    // double click: select word

    // triple click: select line

    // 멀티 라인의 힘

    // 멀티 라인의 힘
    
    // CTRL + DEL: 공백 제거 및 땡기기

    printf_s("%d\n", argc);

    return EXIT_SUCCESS;
}