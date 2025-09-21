#include <stdio.h>

int main(void)
{
    char dst[40];
    char src[20];
    int i = 0; // 교수님이 수업 시간 때 말씀하신 대로 변수는 변수끼리!
    int j;

    printf("문자열 배열 dst에 저장할 과일: ");
    scanf("%s", dst);
    printf("문자열 배열 src에 저장할 과일: ");
    scanf("%s", src);

    while (dst[i] != '\0')
    {
        i++;
    }

    for (j = 0; src[j] != '\0'; j++)
    {
        dst[i + j] = src[j];
    }
    dst[i + j] = '\0';

    printf("문자열 연결 확인 출력: %s\n", dst);

    return 0;
}
