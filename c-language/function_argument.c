#include <stdio.h>

// �Ű� ������ �ִ� �Լ�
void show_message(char* message)
{
    puts(message); // �Ѿ�� �Ű� ������ ���� ���
}

int main(void)
{
    show_message("�Ű� ����"); // "�Ű� ����" ���ڿ��� show_message �Լ��� ����
    show_message("Parameter"); // "Parameter" ���ڿ��� show_message �Լ��� ����

    return 0;
}