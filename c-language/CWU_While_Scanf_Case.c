#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // ���� �Ҵ�
#pragma warning (disable:4996) // c++�� �ش� �۾����� c�� ��� ����

void main()
{
    int i, menu;
    while (1) // while������ �ݺ�!
    {
        printf("\n �޴� 1) 2) 3) 4) 5) 6) 7)����: ");
        scanf("%d", &menu); if(menu == 7) break;
        switch (menu) 
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default: printf("\n �޴����� ����. �ٽ� �������ּ���!\n\n")
        }
    }
}