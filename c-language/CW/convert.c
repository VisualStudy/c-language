#include <stdio.h>

int main(void)
{
    char letter;
    while (1)
    {
        printf("\n\n 대/소문자 입력 (종료하려면 ? 입력):  ");
        letter = getchar(); // 입력을 받음
        getchar(); // 엔터키 제거

        if (letter == '?')
        {
            break;
        }

        if (letter >= 'A' && letter <= 'Z')
        {
            letter = letter + ('a' - 'A'); // 대문자를 소문자로 변환
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            letter = letter - ('a' - 'A'); // 소문자를 대문자로 변환
        }

        printf("\n 변환된 문자: %c", letter);
    }

    return 0;
}
