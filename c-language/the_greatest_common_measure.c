#include <stdio.h>
#pragma warning (disable:4996)

int main(void) // ���� 2�� �Է� �޾Ƽ� �ִ����� ã��
{
    int _ = 0;
    int x = 0;
    int y = 0;
    int r = 0;

    printf("\n ���� 2�� �Է� ( ū �� / ���� ��) :  ");
    _ = scanf("%d%d", &x, &y);
    
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    } 
    // �ִ����� = x
    
    printf("\n\n �ִ����� = %d", x);

    return 0;
}