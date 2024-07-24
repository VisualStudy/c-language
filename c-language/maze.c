#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// 미로 배열: 0은 길, 1은 벽을 나타냅니다.
int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// 방문 배열: 방문한 위치를 기록합니다.
int visited[ROWS][COLS] = { 0 };

int startX = 0, startY = 0; // 시작 지점
int endX = 4, endY = 4;     // 목표 지점

// 미로를 출력하는 함수
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == startX && j == startY)
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

// 미로를 해결하는 함수
int solveMaze(int x, int y) {
    if (x == endX && y == endY) { // 목표 지점에 도달하면
        printf("목표 지점에 도달했습니다: (%d, %d)\n", x, y);
        return 1;
    }

    // 범위를 벗어나거나, 벽이거나, 이미 방문한 경우
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == 1 || visited[x][y]) {
        return 0;
    }

    visited[x][y] = 1; // 현재 위치를 방문했다고 표시

    // 오른쪽으로 이동
    if (solveMaze(x, y + 1)) {
        return 1;
    }

    // 아래쪽으로 이동
    if (solveMaze(x + 1, y)) {
        return 1;
    }

    // 왼쪽으로 이동
    if (solveMaze(x, y - 1)) {
        return 1;
    }

    // 위쪽으로 이동
    if (solveMaze(x - 1, y)) {
        return 1;
    }

    visited[x][y] = 0; // 다른 경로를 찾기 위해 현재 위치를 미방문 상태로 되돌림
    return 0;
}

int main() {
    printf("미로:\n");
    printMaze();

    if (solveMaze(startX, startY)) {
        printf("경로를 찾았습니다!\n");
    }
    else {
        printf("경로를 찾지 못했습니다.\n");
    }

    return 0;
}
