#include <stdio.h>

// 함수 선언
void printMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main(voide)
{
    float num1, num2, result;
    int choice;

    while (1)
    {
        printMenu(); // 메뉴 출력

        printf("원하는 연산을 선택하시오 (1-4) 또는 0을 입력하여 종료:  ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        printf("첫 번째 숫자를 입력하세요: ");
        scanf("%f", &num1);
        printf("두 번째 숫자를 입력하세요: ");
        scanf("%f", &num2);

        
    }
}