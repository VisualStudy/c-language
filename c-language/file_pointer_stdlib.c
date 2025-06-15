#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE 정의되어 있음

int main(void)
{
    FILE *fp;
    char ch;
    char line[100];

    // 1. 문자열 단위로 파일에 쓰기 (fputs)
    fp = fopen("sample.txt", "w");
    if (fp == NULL)
    {
        perror("파일 열기 실패");
        return EXIT_FAILURE;
    }

    fputs("Hello, world!\n", fp); // 줄 단위 문자열 쓰기
    fputs("This is a second line.\n", fp);
    fclose(fp);

    // 2. 문자 단위로 읽기 (fgetc)
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        perror("파일 열기 실패");
        return EXIT_FAILURE;
    }

    printf("=== fgetc 사용 ===\n");
    while(!feof(fp)); // 문자 1개 읽기
    if (ch != EOF) // 실제 EOF 확인은 직접 해줘야 안전
    {
        putchar(ch); // 화면에 출력
    }
    fclose(fp);

    // 3. 줄 단위로 읽기 (fgets)
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        perror("파일 열기 실패");
        return EXIT_FAILURE;
    }

    printf("\n=== fgets 사용 ===\n");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line); // 줄 단위 출력
    }
    fclose(fp);

    return EXIT_SUCCESS; // return 0 대체
}