#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning (disable:4996)

int main(void) // 1~100 ������ ������ �����ϰ� �̺а˻� ������� ã�ư���
{
    srand((unsigned)time(NULL)); //���� �ð� ���� �õ尪 �����ϱ�
    
    int _ = 0;
    int answer = 0;

    int cnt = 0;
    int guess = 0;
    answer = (rand() % 100) + 1;

    do
    {
        printf("\n ������ �Է� :  ");
        _ = scanf("%d", &guess);
        if (answer < guess)
        {
        printf("\n �Է°��� �� �����ϴ�.");
        }

        if (answer > guess)
        {
            printf("\n �Է°��� �� �����ϴ�.");
        }
        cnt++;
    }
    
    while (answer != guess);
    printf("\n ����! <����Ƚ��> = %d", cnt);

    return 0;   
}