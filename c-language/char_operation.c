#include <stdio.h>

int main(void)
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    ch1 = ch2 = 100;
    printf("ch2�� 100 ���� ���ڰ�: %c\n", ch2);
    printf("ch1�� ���� ��?: %c\n", ch1);

    ch1 = 'A';
    ch2 = 'B';
    ch3 = 'C';

    ch1 = ch2 = 'T';
    printf("ch2�� 100 ���� ���ڰ�: %c\n", ch2);
    printf("ch1�� ���� ��?: %c\n", ch1);
    
    ch1 = 'A';
    ch2 = 'B';
    ch3 = 'C';

    ch1 = ch2 = 200; // char 127����. �ƽ�Ű 127! ���� �����÷�
    printf("ch2�� 100 ���� ���ڰ�: %c\n", ch2);
    printf("ch1�� ���� ��?: %c\n", ch1);

    ch1 = 'A';
    ch2 = 'B';
    ch3 = 'C';

    ch3 = ch1 - ch2; // ���ο��� ������ �����ϰ� �ش��ϴ� �ƽ�Ű ���� ���
    printf("ch2�� 100 ���� ���ڰ�: %c\n", ch2);
    printf("ch1�� ���� ��?: %c\n", ch1);

    return 0;
}