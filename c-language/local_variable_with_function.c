#include <stdio.h>

int function_local(int i)
{   
    printf("�ڷ��� �������� ����: %d\n", i);
    i++;
}

int main(void)
{
    int i = 100; // ���� �Լ��� ���� ���� i�� 100�̶� ���� ����

    printf("�� �̽� ������ ����: %d\n", i);
    printf("��...\n");
    function_local(10);
    printf("����ī.. i���� ++ �Ͽ��µ� �þ����?: %d\n", i);

    return 0;
}