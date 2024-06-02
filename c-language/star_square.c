#include <stdio.h>

int main() 
{
    int rows = 10;    // 세로 크기
    int cols = 50;    // 가로 크기

// 사각형을 출력하는 이중 for문
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("*");
        }
        printf("\n"); // 각 행의 끝에서 줄바꿈
    }

    return 0;
}
