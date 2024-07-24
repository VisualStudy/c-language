#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Windows 전용 헤더 파일

#define ROWS 10
#define COLS 10

// 미로 배열: 0은 길, 1은 벽을 나타냅니다.
int maze[ROWS][COLS] = 
{
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0}
};

int startX = 0, startY = 0; // 시작 지점
int endX = 9, endY = 9;     // 목표 지점
int playerX = 0, playerY = 0; // 플레이어 초기 위치

// 미로를 출력하는 함수
void printMaze() 
{
    system("cls"); // 화면 지우기 (Windows용. Unix-like 시스템에서는 "clear" 사용)
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (i == playerX && j == playerY)
                printf("P "); // 플레이어 위치 표시
            else if (i == startX && j == startY)
                printf("S ");
            else if (i == endX && j == endY)
                printf("E ");
            else if (maze[i][j] == 0)
                printf("□ ");
            else
                printf("■ ");
        }
        printf("\n");
    }
}

// 플레이어 이동 처리 함수
void movePlayer(char direction) 
{
    int newX = playerX, newY = playerY;
    if (direction == 'w') newX--;
    if (direction == 's') newX++;
    if (direction == 'a') newY--;
    if (direction == 'd') newY++;

    // 이동 가능한지 확인
    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && maze[newX][newY] == 0) 
    {
        playerX = newX;
        playerY = newY;
    }
}

int main() 
{
    char input;
    playerX = startX; // 플레이어 초기 위치 설정
    playerY = startY;

    while (1) 
    {
        printMaze();
        if (playerX == endX && playerY == endY) 
        {
            printf("축하합니다! 목표 지점에 도달했습니다!\n");
            break;
        }

        input = _getch(); // 방향키 입력 대기
        if (input == 'q') break; // 'q' 입력시 게임 종료
        movePlayer(input);
    }

    return 0;
}
