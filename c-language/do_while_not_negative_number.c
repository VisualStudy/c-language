#include <stdio.h>
#pragma warning (disable:4996)

int main(void) // ������ �ƴ� ���� ���(do while) �Է��ϰ� �����ؼ� ���
{
    int _ = 0;
    int n = 0;
    int sum = 0;
    do
    {
        printf("\n ���� �Է� :  ");
        _ = scanf("%d", &n);
        if ( n < 0 )
        {
            break;
        }
        sum = sum + n;
    }

    while ( n >= 0 ); // ���� x -> �ݺ�
    {
        printf("\n\n�ջ� = %d", sum);
    }

    return 0;
}