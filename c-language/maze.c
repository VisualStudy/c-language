#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>  // Windows ���� ��� ����

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];
int startX = 0, startY = 0; // ���� ����
int endX, endY;             // ��ǥ ����
int playerX = 0, playerY = 0; // �÷��̾� �ʱ� ��ġ

// �����¿� ���� ����
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// �̷θ� �ʱ�ȭ�ϴ� �Լ�
void initializeMaze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            maze[i][j] = 1; // ������ �ʱ�ȭ
        }
    }
}

// ���� �켱 Ž���� �̿��� �̷� ���� �Լ�
void generateMaze(int x, int y)
{
    maze[x][y] = 0;

    // �������� ������ ����
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

// ��ǥ ���� ���� �Լ�
void setEndPoint()
{
    do
    {
        endX = rand() % (ROWS - 2) + 1; // 1 ~ ROWS-2 ����
        endY = rand() % (COLS - 2) + 1; // 1 ~ COLS-2 ����
    } while (maze[endX][endY] == 1 || (endX == startX && endY == startY)); // ���� �ƴϰ� ���� ������ �ƴ� ���
}

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
    srand(time(NULL));

    while (1)
    {
        initializeMaze();
        generateMaze(startX, startY);
        setEndPoint(); // ��ǥ ���� ����

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

        if (input == 'q') break; // ���� ���� Ȯ��
    }

    return 0;
}
