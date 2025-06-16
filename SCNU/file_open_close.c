#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    char naming[100];
    int age;
    char getname[100];
    int getage;

    FILE *fp;
    fp = fopen("scnu_file.txt", "w");
    if(fp == NULL)
    {
        printf("망함을 감지. 긴급 종료!\n");

        return 1;
    }
    fprintf(fp, "이것은 문자열 작성이ㄷr\n");
    fprintf(fp, "다음 줄 대기하라이!");

    while(1)
    {
        printf("지금부터 입력 받을 것. 탈출 원하면 0 입력\n");
        printf("전설적인 존재의 이름 입력: \n");
        strcpy(name, "라바라타");
        printf("홀리! strcpy가 침공! 너가 직접 이름 입력: ");
        scanf("%s", naming);
        printf("음, 이름 입력 자알~ 받았다. 나이 입력: ");
        scanf("%d", &age);

        fprintf(fp, "\n 네 놈이 넣은 정보 %s, %d\n", naming, age);

        if(age == 0)
        {
            break;
        }
    }

    fputc('a', fp);
    fputc('b', fp);
    fputc('c', fp);

    fclose(fp);

    fp = fopen("scnu_file.txt", "r");

    while(!feof(fp))
    {
        fscanf(fp, "%s, %d", getname, &age);
        printf("부아아아악! 문자 우오아아: %s\n", getname);
        printf("우어어억, 그어어억 숫자: %d\n", age);
    }

    fclose(fp);

    return 0;
}