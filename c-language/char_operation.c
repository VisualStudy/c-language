#include <stdio.h>

int main(void)
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    ch1 = ch2 = 100;
    printf("ch2에 100 넣은 문자값: %c\n", ch2);
    printf("ch1은 무슨 값?: %c\n", ch1);

    ch1 = 'A';
    ch2 = 'B';
    ch3 = 'C';

    ch1 = ch2 = 'T';
    printf("ch2에 100 넣은 문자값: %c\n", ch2);
    printf("ch1은 무슨 값?: %c\n", ch1);
    
    ch1 = 'A';
    ch2 = 'B';
    ch3 = 'C';

    ch1 = ch2 = 200; // char 127까지. 아스키 127! 따라서 오버플로
    printf("ch2에 100 넣은 문자값: %c\n", ch2);
    printf("ch1은 무슨 값?: %c\n", ch1);

    ch1 = 'A';
    ch2 = 'B';
    ch3 = 'C';

    ch3 = ch1 - ch2; // 내부에서 정수로 연산하고 해당하는 아스키 글자 출력
    printf("ch2에 100 넣은 문자값: %c\n", ch2);
    printf("ch1은 무슨 값?: %c\n", ch1);

    return 0;
}