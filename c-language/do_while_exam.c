#include <stdio.h>

int main(void)
{
    int i;
    printf("�� �Է�: ");
    scanf("%d", &i);

    while (i > 0)
    {
        if (i % 2 != 0)
        {
            printf("Ȧ���Դϴ�.\n");
        }
        else if (i % 2 == 0)
        {
            continue;
            printf("¦���Դϴ�.\n");
        }
    }
    
    return 0;
}