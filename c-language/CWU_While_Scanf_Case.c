#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // 동적 할당
#pragma warning (disable:4996) // c++은 해당 작업으로 c로 사용 가능

void main()
{
    int i, menu;
    while (1) // while문으로 반복!
    {
        printf("\n 메뉴 1) 2) 3) 4) 5) 6) 7)종료: ");
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
            default: printf("\n 메뉴선택 오류. 다시 선택해주세요!\n\n")
        }
    }
}