//[?] 함수(Function): 반복하여 사용하도록 하나의 이름으로 만들어 놓은 코드의 집합
#include <stdio.h>

//[1] 함수 만들기(정의, 선언)
hi()
{
    puts("안녕하세요.");
}

int main(void)
{
    //[2] 함수 사용하기(호출): 여러 번 호출
    hi(); hi(); hi();
    hi(); hi();
    hi();

    return 0;
}