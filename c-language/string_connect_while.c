#include <stdio.h>
#define NULL '\0'

void mystrcat(char a[], char b[]);

int main(void)
{
    char dst[40];
    char src[20];

    printf("문자열 배열 dst에 저장할 과일: ");
    scanf("%s", dst);
    printf("문자열 배열 src에 저장할 과일: ");
    scanf("%s", src);

    mystrcat(dst, src);

    printf("문자열 연결 확인 출력: %s\n", dst);

    return 0;
}

void mystrcat(char a[], char b[])
{
    int i = 0;
    int j;

    while(a[i] != NULL)
    {
        i++;
    }

    for(j = 0; b[j] != NULL; j++)
    {
        a[i + j] = b[j];
    }

    a[i + j] = NULL;
}