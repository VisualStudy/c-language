#include <stdio.h>

int main(void)
{
    FILE *fp;
    int a = 10, b = 20, c = 30;
    int x, y, z;

    // 1. 파일 쓰기 모드로 열기
    fp = fopen("data.txt", "w"); // "w" = write
    if (fp == NULL)
    {
        printf("파일 열기 실패!\n");
        return 1; // 비정상 종료
    }

    // 2. 파일에 데이터 쓰기
    fprintf(fp, "%d %d %d\n", a, b, c);
    fclose(fp); // 파일 닫기

    // 3. 파일 읽기 모드로 다시 열기
    fp = fopen("data.txt", "r"); // "r" = read
    if (fp == NULL)
    {
        printf("파일 열기 실패!\n");
        return 1;
    }

    // 4. 파일에서 데이터 읽기
    fscanf(fp, "%d %d %d", &x, &y, &z);
    printf("읽어온 값: %d %d %d\n", x, y, z);

    fclose(fp); // 파일 닫기

    return 0;
}