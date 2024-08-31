#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    int _;

    char str1[100];
    char str2[100];

    // 사용자로부터 첫 번째 문자열 입력 받기
    printf("첫 번째 문자열을 입력하세요: ");
    _ = scanf("%s", str1);

    // 사용자로부터 두 번째 문자열 입력 받기
    printf("두 번째 문자열을 입력하세요: ");
    _ = scanf("%s", str2);

    // 문자열 비교
    int result = strcmp(str1, str2);

    if (result == 0)
    {
        printf("두 문자열은 같습니다.\n");
    }
    else if (result < 0)
    {
        printf("첫 번째 문자열이 두 번째 문자열보다 사전적으로 앞에 있습니다.\n");
    }
    else
    {
        printf("첫 번째 문자열이 두 번째 문자열보다 사전적으로 뒤에 있습니다.\n");
    }

    return 0;
}