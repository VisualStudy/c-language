//[?] 2���� �迭: ��� ���� �̷���� �迭
#include <stdio.h>

int main(void)
{
    //[1] 2���� �迭 ����
    char arr[2][2];

    //[2] 2���� �迭 �ʱ�ȭ
    arr[0][0] = 'A';
    arr[0][1] = 'B';

    arr[1][0] = 'C';
    arr[1][1] = 'D';

    //[3] 2���� �迭 ���
    printf("%c, %c\n", arr[0][0], arr[0][1]);
    printf("%c, %c\n", arr[1][0], arr[1][1]);

    return 0;
}