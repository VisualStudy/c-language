#include <stdio.h>

int main(void)
{
    int kor = 100;
    int eng = 90;

    int tot = kor + eng; // ���� ���ϱ�
    double avg = tot / 2.0; // ��� ���ϱ�
    
    printf("����: %d\n", tot);
    printf("���: %.2f\n", avg);

    return 0;
}