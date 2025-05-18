#include <stdio.h>

int main(void)
{
    FILE *fp;

    fp = fopen("file.txt", "w");
    if (fp == NULL)
    {
        printf("파일 열기 실패\n");
        return 1;
    }

    fprintf(fp, "Hello, C file I/O!\n");
    fprintf(fp, "두 번째 줄입니다.\n");

    fclose(fp);

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}