#include <stdio.h>

int main(void)
{
    int a;
    while (1)
    {
        printf("다음 중 생물학적 과일이 아닌 것은? 1) 수박 2) 토마토 3) 오이 4) 루바브");
        scanf("%d", &a);
        switch (a)
        {
            case(1):
            {
                printf("오답");
                break;
            }
            case(2):
            {
                printf("오답");
                break;
            }
            case(3):
            {
                printf("오답");
                break;
            }
            case(4):
            {
                printf("오답");
                break;
            }
            case(5):
            {
                printf("정답");
                break;
            }
        }
    }


    return 0;
}