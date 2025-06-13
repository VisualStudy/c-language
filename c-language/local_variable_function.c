#include <stdio.h>

void FunctionA();
void FunctionB();

int main(void)
{
    FunctionA();
    FunctionB();
    FunctionA();

    return 0;
}

void FunctionA()
{
    int a = 10; // FunctionA 안의 지역 변수
    printf("FunctionA: a = %d, 주소 = %p\n", a, &a);
}

void FunctionB()
{
    int a = 20; // FunctionB 안의 지역 변수 (이름은 같지만 완전히 다른 지역 변수)
    printf("FunctionB: a = %d, 주소 = %p\n", a, &a);
}

//메모리 주소는 매번 다르다!
//지역 변수는 RAM의 스택 영역에 함수 호출 때마다 새로 생성되고, 함수가 끝나면 자동으로 소멸된다.
//
//정리: 
//1 지역 변수는 스택에 저장되며 이로 인해 함수 호출 시마다 새롭게 생성된다(메모리 주소 변경 이유)
//2 함수 종료 시 지역 변수는 소멸한다.
//3 이름이 같아도 독립적이다. FunctionA 속 a와 FunctionB 속 a의 차이에서 보았듯 둘은 완전히 다른 변수이다.

