#include <stdio.h>

int main(void)
{
    int num1 = 0;
    int num2 = 0;

    printf("�� ���� �Է� �޾� ������ �����ϱ�\ n");
    printf("ù ��° ��: ");
    scanf("%d", &num1);
    printf("�� ���� ��: ");
    scanf("%d", &num2);
    
    int result = 0;
    result = num1 % num2;

    printf("�� ���� ���� ���: %d\n", result);
 
    return 0;
}