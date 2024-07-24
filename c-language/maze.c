#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// �̷� �迭: 0�� ��, 1�� ���� ��Ÿ���ϴ�.
int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// �湮 �迭: �湮�� ��ġ�� ����մϴ�.
int visited[ROWS][COLS] = { 0 };

int startX = 0, startY = 0; // ���� ����
int endX = 4, endY = 4;     // ��ǥ ����

// �̷θ� ����ϴ� �Լ�
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == startX && j == startY)
                printf("S ");
            else if (i == endX && j == endY)
                printf("E ");
            else if (maze[i][j] == 0)
                printf("�� ");
            else
                printf("�� ");
        }
        printf("\n");
    }
}

// �̷θ� �ذ��ϴ� �Լ�
int solveMaze(int x, int y) {
    if (x == endX && y == endY) { // ��ǥ ������ �����ϸ�
        printf("��ǥ ������ �����߽��ϴ�: (%d, %d)\n", x, y);
        return 1;
    }

    // ������ ����ų�, ���̰ų�, �̹� �湮�� ���
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == 1 || visited[x][y]) {
        return 0;
    }

    visited[x][y] = 1; // ���� ��ġ�� �湮�ߴٰ� ǥ��

    // ���������� �̵�
    if (solveMaze(x, y + 1)) {
        return 1;
    }

    // �Ʒ������� �̵�
    if (solveMaze(x + 1, y)) {
        return 1;
    }

    // �������� �̵�
    if (solveMaze(x, y - 1)) {
        return 1;
    }

    // �������� �̵�
    if (solveMaze(x - 1, y)) {
        return 1;
    }

    visited[x][y] = 0; // �ٸ� ��θ� ã�� ���� ���� ��ġ�� �̹湮 ���·� �ǵ���
    return 0;
}

int main() {
    printf("�̷�:\n");
    printMaze();

    if (solveMaze(startX, startY)) {
        printf("��θ� ã�ҽ��ϴ�!\n");
    }
    else {
        printf("��θ� ã�� ���߽��ϴ�.\n");
    }

    return 0;
}
