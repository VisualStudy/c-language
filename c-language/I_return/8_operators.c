#include <stdio.h>

int main(void)
{
    int a = 5, b = 3;
    
    printf("Arithmetic Operators(��� ������):\n");
    printf("Addition(����): %d\n", a + b);
    printf("Subtraction(����): %d\n", a - b);
    printf("Multiplication(����): %d\n", a * b);
    printf("Division(������): %d\n", a / b);
    printf("Modulus(���� �� ������ not ��): %d\n\n", a % b);
    
    printf("Relational Operators(���� ������):\n");
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n\n", a < b);

    printf("Logical Operators(�� ������):\n");
    printf("a > 0 && b > 0: %d\n", (a > 0 && b > 0)); // a > 0 && b > 0: a�� 0���� ũ�� �׸��� b�� 0���� ũ��
    printf("a > 0 || b < 0: %d\n\n", (a > 0 || b < 0)); // a > 0 || b < 0: a�� 0���� ũ�� �Ǵ� b�� 0���� �۴�

    printf("Bitwise Operators(��Ʈ ������):\n"); // ��Ʈ ������ ���� ����: 2���� ��ȯ �� ����
    printf("Bitwise AND: %d\n", a & b); // ��Ʈ AND: 2���� ��ȯ �� �� ��Ʈ ��� 1�� ���� 1�� ����Ͽ� ��Ʈ�� ���
    printf("Bitwise OR: %d\n", a | b); // ��Ʈ OR: 2���� ��ȯ �� �� ��Ʈ �� �ϳ��� 1�̸� 1 -> ��Ʈ�� ���
    printf("Bitwise XOR: %d\n", a ^ b); // ��Ʈ XOR: 2���� ��ȯ �� �� ���� ��Ʈ�� �ٸ� ���� 1 -> ��Ʈ�� ���
    printf("Bitwise NOT (a): %d\n", ~a); // ��Ʈ NOT: 2���� ��ȯ �� 1�� 0����, 0�� 1�� -> ��Ʈ�� ���

    return 0;
}