#include <stdio.h>
#define SIZE 5 // ��ȣ ����� �迭 ũ�� ����

int main(void)
{
    int scores[SIZE] = {88, 76, 92, 85, 69};
    
    printf("�л� ���� ���: \n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    return 0;
}    
    
