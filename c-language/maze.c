#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>  // Windows 전용 헤더 파일

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];
int startX = 0, startY = 0; // 시작 지점
int endX, endY;             // 목표 지점
int playerX = 0, playerY = 0; // 플레이어 초기 위치

// 상하좌우 방향 정의
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 미로를 초기화하는 함수
void initializeMaze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            maze[i][j] = 1; // 벽으로 초기화
        }
    }
}

// 깊이 우선 탐색을 이용한 미로 생성 함수
void generateMaze(int x, int y)
{
    maze[x][y] = 0;

    // 무작위로 방향을 섞음
    int directions[4] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; i++)
    {
        int r = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[r];
        directions[r] = temp;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[directions[i]] * 2;
        int ny = y + dy[directions[i]] * 2;

        if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && maze[nx][ny] == 1)
        {
            maze[x + dx[directions[i]]][y + dy[directions[i]]] = 0;
            generateMaze(nx, ny);
        }
    }
}

// 목표 지점 설정 함수
void setEndPoint()
{
    do
    {
        endX = rand() % (ROWS - 2) + 1; // 1 ~ ROWS-2 범위
        endY = rand() % (COLS - 2) + 1; // 1 ~ COLS-2 범위
    } while (maze[endX][endY] == 1 || (endX == startX && endY == startY)); // 벽이 아니고 시작 지점이 아닌 경우
}

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
    srand(time(NULL));

    while (1)
    {
        initializeMaze();
        generateMaze(startX, startY);
        setEndPoint(); // 목표 지점 설정

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

        if (input == 'q') break; // 게임 종료 확인
    }

    return 0;
}
