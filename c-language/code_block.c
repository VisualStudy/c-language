#include <stdio.h>

int main(void)
{
    int x =5;
    {
        int y = 10;
        printf("x = %d, y = %d\n", x, y);
    }
    // y�� ��� �ۿ��� ��ȿ���� ����
    printf("x = %d\n", x);
    return 0;
}