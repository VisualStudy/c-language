#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("scnu_file.txt", "w");
    if(fp == NULL)
    {
        printf("망함을 감지. 긴급 종료!\n");

        return 1;
    }
    fprintf(fp, "이것은 문자열 작성이ㄷr\n");
    fprintf(fp, "다음 줄 대기하라이!");

    fputc('a', fp);
    fputc('b', fp);
    fputc('c', fp);

    fclose(fp);

    return 0;
}