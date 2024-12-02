#define _CRT_SECURE_NO_WARNINGS // scanf가 포함된 코드를 문제없이 콘솔 구동하기 위해
#include <stdio.h>

int main(void)
{
    int age; // int로 정수형 선언 그리고 해당 정수형 이름을 age로 설정하기
    printf("나이 입력: "); // 사용자에게 나이 입력 요청
    scanf("%d", &age);   // 사용자가 입력한 숫자를 정수형 변수 age에 저장, %d는 정수 데이터 처리에 쓰임
    printf("\n당신의 나이는 %d살이군요!", age); // 위에서 int age에 입력(저장)한 값을 printf로 불러와 출력

    return 0; // 반환값은 0으로 처리해 코드 깔끔히 끝내기
}