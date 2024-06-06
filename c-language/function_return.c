// 반환값이 있는 함수 만들고 호출하기
#include <stdio.h>

char* get_string()
{
    return "반환값(Return Value)"; // return 키워드를 사용하여 문자열 반환
}

int main(void)
{
    // get_string 함수를 호출하고 반환된 값을 return_value 변수에 저장
    char* return_value = get_string();
    printf("%s\n", return_value);

    return 0;
}