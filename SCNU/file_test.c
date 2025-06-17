#include <stdio.h>

int main(void)
{
    FILE *fp;
    char a;
   
    fp = fopen("test.txt", "w");
     if(fp == NULL)
    {
        printf("파일 열기 실패\n");
        return 0;
    }
    fputc('a', fp);
    fprintf(fp, "pple\n");
    fprintf(fp, "abc");
    fclose(fp);

    fp = fopen("test.txt", "r");
    while(!feof(fp)) // 마지막 문자 두 번 읽는 문제점
    {
         fscanf(fp, "%c", &a);
        printf("%c", a);
    }
   fclose(fp);

   return 0;
}