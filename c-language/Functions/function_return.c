// ��ȯ���� �ִ� �Լ� ����� ȣ���ϱ�
#include <stdio.h>

char* get_string()
{
    return "��ȯ��(Return Value)"; // return Ű���带 ����Ͽ� ���ڿ� ��ȯ
}

int main(void)
{
    // get_string �Լ��� ȣ���ϰ� ��ȯ�� ���� return_value ������ ����
    char* return_value = get_string();
    printf("%s\n", return_value);

    return 0;
}