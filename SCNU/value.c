#include <stdio.h>

void shiftVal(int a, int b, int c);

int main(void)
{
    int a = 0, b = 10, c = 20;

    shiftVal(a, b, c);

    printf("���� �Լ� �� a�� ��: %d\n", a);
    printf("���� �Լ� �� b�� ��: %d\n", b);
    printf("���� �Լ� �� c�� ��: %d\n", c);

    return 0;
}

void shiftVal(int a, int b, int c)
{
    int temp;
    temp = c;
    c = b;
    b = a;
    a = temp;

    printf("shiftVal �Լ� �� �ű� a�� ��: %d\n", a);
    printf("shiftVal �Լ� �� �ű� b�� ��: %d\n", b);
    printf("shiftVal �Լ� �� �ű� c�� ��: %d\n", c);
}