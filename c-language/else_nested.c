// 중첩된 else 문을 활용한 입력 처리 예제
#include <stdio.h>

int main(void)
{
    char input;
    printf("문자를 입력하세요. (y/n/c): ");
    input = getchar();

    if (input == 'y')
    {
        printf("Yes");
    }
    else if (input == 'n')
    {
        printf("No");
    }
    else
    {
        printf("Cancel");
    }

    return 0;
}