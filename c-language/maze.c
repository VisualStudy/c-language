#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Windows ���� ��� ����

#define ROWS 10
#define COLS 10

// �̷� �迭: 0�� ��, 1�� ���� ��Ÿ���ϴ�.
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

int startX = 0, startY = 0; // ���� ����
int endX = 9, endY = 9;     // ��ǥ ����
int playerX = 0, playerY = 0; // �÷��̾� �ʱ� ��ġ

// �̷θ� ����ϴ� �Լ�
void printMaze() 
{
    system("cls"); // ȭ�� ����� (Windows��. Unix-like �ý��ۿ����� "clear" ���)
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (i == playerX && j == playerY)
                printf("P "); // �÷��̾� ��ġ ǥ��
            else if (i == startX && j == startY)
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

// �÷��̾� �̵� ó�� �Լ�
void movePlayer(char direction) 
{
    int newX = playerX, newY = playerY;
    if (direction == 'w') newX--;
    if (direction == 's') newX++;
    if (direction == 'a') newY--;
    if (direction == 'd') newY++;

    // �̵� �������� Ȯ��
    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && maze[newX][newY] == 0) 
    {
        playerX = newX;
        playerY = newY;
    }
}

int main() 
{
    char input;
    playerX = startX; // �÷��̾� �ʱ� ��ġ ����
    playerY = startY;

    while (1) 
    {
        printMaze();
        if (playerX == endX && playerY == endY) 
        {
            printf("�����մϴ�! ��ǥ ������ �����߽��ϴ�!\n");
            break;
        }

        input = _getch(); // ����Ű �Է� ���
        if (input == 'q') break; // 'q' �Է½� ���� ����
        movePlayer(input);
    }

    return 0;
}
