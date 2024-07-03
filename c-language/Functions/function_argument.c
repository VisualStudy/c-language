#include <stdio.h>

// 매개 변수가 있는 함수
void show_message(char* message)
{
    puts(message); // 넘어온 매개 변수의 값을 출력
}

int main(void)
{
    show_message("매개 변수"); // "매개 변수" 문자열을 show_message 함수로 전달
    show_message("Parameter"); // "Parameter" 문자열을 show_message 함수로 전달

    return 0;
}