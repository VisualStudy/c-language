#include <stdio.h>

int main(void)
{
    int a = 0x41, b = 0x61;

    int tol;
    tol = b - a;

    printf("%c�� �ҹ��ڷ� ǥ���ϸ� %c�̸� \n", 'K', 'K' + tol);
    printf("%c�� �빮���� ǥ���ϸ� %c�̸� \n", 'z', 'z' - tol);

    return 0;
}