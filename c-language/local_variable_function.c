#include <stdio.h>

void FunctionA();
void FunctionB();

int main(void)
{
    FunctionA();
    FunctionB();
    FunctionA();

    return 0;
}

void FunctionA()
{
    int a = 10; // FunctionA ���� ���� ����
    printf("FunctionA: a = %d, �ּ� = %p\n", a, &a);
}

void FunctionB()
{
    int a = 20; // FunctionB ���� ���� ���� (�̸��� ������ ������ �ٸ� ���� ����)
    printf("FunctionB: a = %d, �ּ� = %p\n", a, &a);
}

//�޸� �ּҴ� �Ź� �ٸ���!
//���� ������ RAM�� ���� ������ �Լ� ȣ�� ������ ���� �����ǰ�, �Լ��� ������ �ڵ����� �Ҹ�ȴ�.
//
//����: 
//1 ���� ������ ���ÿ� ����Ǹ� �̷� ���� �Լ� ȣ�� �ø��� ���Ӱ� �����ȴ�(�޸� �ּ� ���� ����)
//2 �Լ� ���� �� ���� ������ �Ҹ��Ѵ�.
//3 �̸��� ���Ƶ� �������̴�. FunctionA �� a�� FunctionB �� a�� ���̿��� ���ҵ� ���� ������ �ٸ� �����̴�.

