#include <stdio.h>

int main(void)
{
    int a = 5, b = 2;
    double result1, result2;

    result1 = a / b; // �������� ���� -> 2
    result2 = (double)a / b; // a�� double�� ����ȯ -> 2.5

    printf("���� ������ (a / b): %f\n", result1);
    printf("����ȯ �� ������ ((double)a / b: %f\n", result2);

    // �Ǽ��� ������ ��ȯ
    double pi = 3.14159;
    int IntPi = (int)pi;
    printf("�Ǽ� pi�� ������ ��ȯ: %d\n", IntPi); // 3

    return 0;
}