#include <stdio.h>

int Global = 100; // ���� ����

void TestScope()
{
    int Local = 50; // TestScope �Լ� �� ���� ����
    printf("TestScope �Լ� ��:\n");
    printf("���� ���� Global = %d \n", Global);
    printf("���� ���� Local = %d \n", Local);
}

int main(void)
{
    int Local = 10; //���� �Լ��� ���� ����
    printf("���� �Լ� ��: \n");
    printf("���� ���� Global = %d \n", Global);
    printf("���� ���� Local = %d \n", Local);

    TestScope();

    return 0;
}