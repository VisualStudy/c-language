#include <stdio.h>

// �Լ� ����
int Factorial(int n);

int main(void)
{
    int num = 5;
    int result = Factorial(num);
    printf("%d! = %d\n", num, result);

    return 0;
}

// ��� �Լ� ����
int Factorial(int n)
{
    if (n == 0)
    {
        return 1; // ���� ����: 0! = 1
    }
    else
    {
        return n * Factorial(n - 1); // ��� ȣ��
    }
}