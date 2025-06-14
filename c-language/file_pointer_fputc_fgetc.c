#include <stdio.h>

int main(void)
{
    FILE *fp;
    char ch;

    // 파일에 문자(딱 한 글자: 캐릭터) 쓰기
    fp = fopen("char_test.txt", "w");
    if (fp == NULL)
    {
        printf("파일 열기 실패!\n");
        return 1;
    }

    printf("문자열을 입력하세요 (끝내려면 Enter):  ");
    while ((ch = getchar()) != '\n') // 표준 입력에서 문자 1개씩 입력
    {
        fputc(ch, fp); // 파일에 문자 1개씩 저장
    }
    fclose(fp);

    // 파일에서 문자 읽기
    fp - fopen("char_test.txt", "r");
    if (fp == NULL)
    {
        printf("파일 읽기 실패!\n");
        return 1;
    }

    printf("파일에서 읽은 내용: ");
    while ((ch = fgetc(fp)) != EOF) // 파일에서 한 글자씩 읽어 출력
    {
        putchar(ch);
    }
    printf("\n");

    fclose(fp);

    return 0;
}