// ��ø�� else ���� Ȱ���� �Է� ó�� ����
#include <stdio.h>

int main(void)
{
    char input;
    printf("���ڸ� �Է��ϼ���. (y/n/c): ");
    input = getchar();

    if (input == 'y')
    {
        printf("Yes");
    }
    else if (input == 'n')
    {
        printf("No");
    }
    else
    {
        printf("Cancel");
    }

    return 0;
}