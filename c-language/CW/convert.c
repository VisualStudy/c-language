#include <stdio.h>

int main(void)
{
    char letter;
    while (1)
    {
        printf("\n\n ��/�ҹ��� �Է� (�����Ϸ��� ? �Է�):  ");
        letter = getchar(); // �Է��� ����
        getchar(); // ����Ű ����

        if (letter == '?')
        {
            break;
        }

        if (letter >= 'A' && letter <= 'Z')
        {
            letter = letter + ('a' - 'A'); // �빮�ڸ� �ҹ��ڷ� ��ȯ
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            letter = letter - ('a' - 'A'); // �ҹ��ڸ� �빮�ڷ� ��ȯ
        }

        printf("\n ��ȯ�� ����: %c", letter);
    }

    return 0;
}
