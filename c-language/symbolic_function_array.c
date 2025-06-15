#include <stdio.h>
#define SIZE 5 // 기호 상수로 배열 크기 지정

int main(void)
{
    int scores[SIZE] = {88, 76, 92, 85, 69};
    
    printf("학생 점수 목록: \n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    return 0;
}    
    
