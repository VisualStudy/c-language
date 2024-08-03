#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h> // Ŀ�� ����� ���� �ʿ�
#include <stdbool.h> // bool Ÿ�� ����� ���� �ʿ�

#define INITIAL_ROWS 10
#define INITIAL_COLS 10
#define TOTAL_LEVELS 5
#define LEVEL_INCREASE 2 // �ܰ�� ������ �̷� ũ�� (����)
#define MIN_DISTANCE 10 // ���� ������ ��ǥ ���� ������ �ּ� �Ÿ�
#define CHALLENGE_COUNT 10 // ç���� �ܰ� ��
#define ROUND_COUNT 10 // ���� �ܰ� ��

int** maze;
int startX = 0, startY = 0;
int endX, endY;
int playerX = 0, playerY = 0;
int rows, cols;
char input[10];

// �����¿� ���� ����
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// ���� 2���� �迭 ���� �Լ�
int** createMaze(int rows, int cols)
{
    int** maze = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        maze[i] = (int*)malloc(cols * sizeof(int));
    }
    return maze;
}

// ���� 2���� �迭 ���� �Լ�
void freeMaze(int** maze, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(maze[i]);
    }
    free(maze);
}

// �̷θ� �ʱ�ȭ�ϴ� �Լ�
void initializeMaze()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            maze[i][j] = 1; // ������ �ʱ�ȭ
        }
    }
}

// ���� �켱 Ž���� �̿��� �̷� ���� �Լ�
void generateMaze(int x, int y)
{
    maze[x][y] = 0;

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

        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == 1)
        {
            maze[x + dx[directions[i]]][y + dy[directions[i]]] = 0;
            generateMaze(nx, ny);
        }
    }
}

// ��ǥ ���� ���� �Լ� (�ּ� �Ÿ� ����)
void setEndPoint()
{
    int** distances = createMaze(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            distances[i][j] = -1;
        }
    }

    // BFS�� ����Ͽ� ���� �������� ��� ���������� �ִ� �Ÿ� ���
    int* queueX = (int*)malloc(rows * cols * sizeof(int));
    int* queueY = (int*)malloc(rows * cols * sizeof(int));
    int front = 0, rear = 0;

    queueX[rear] = startX;
    queueY[rear] = startY;
    rear++;
    distances[startX][startY] = 0;

    while (front < rear)
    {
        int x = queueX[front];
        int y = queueY[front];
        front++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == 0 && distances[nx][ny] == -1)
            {
                distances[nx][ny] = distances[x][y] + 1;
                queueX[rear] = nx;
                queueY[rear] = ny;
                rear++;
            }
        }
    }

    // �ּ� �Ÿ��� �����ϴ� ��ǥ ���� ã��
    int maxDist = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (distances[i][j] >= MIN_DISTANCE && distances[i][j] > maxDist)
            {
                maxDist = distances[i][j];
                endX = i;
                endY = j;
            }
        }
    }

    free(queueX);
    free(queueY);
    freeMaze(distances, rows);
}

// Ŀ�� ����� �Լ�
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

// Ŀ�� ���̱� �Լ�
void showCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

// Ŀ�� ��ġ ���� �Լ�
void setCursorPosition(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPosition;
    cursorPosition.X = y * 2;
    cursorPosition.Y = x;
    SetConsoleCursorPosition(consoleHandle, cursorPosition);
}

// �̷θ� ����ϴ� �Լ�
void printMaze()
{
    setCursorPosition(0, 0); // ��� ���� ��ġ�� Ŀ�� �̵�
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == playerX && j == playerY)
                printf("P ");
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

// ���� �޽����� ����ϴ� �Լ�
void printMessage(int level)
{
    printf("\n%d�ܰ� �̷��Դϴ�.\n", level);
    printf("������� ���� ��ġ�� 'P'(player)�� ǥ���˴ϴ�.\n");
    printf("��ǥ�� ��ǥ ������ 'E'(end point)���� �̵��ϴ� ���Դϴ�.\n");
    printf("����Ű�� �̿��Ͽ� �̵��ϼ��� (w: ��, s: �Ʒ�, a: ����, d: ������).\n");
    printf("������ �����Ϸ��� 'q'�� �Է��ϼ���.\n");
}

// �÷��̾� �̵� ó�� �Լ�
void movePlayer(char direction)
{
    int newX = playerX, newY = playerY;
    if (direction == 'w') newX--;
    if (direction == 's') newX++;
    if (direction == 'a') newY--;
    if (direction == 'd') newY++;

    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && maze[newX][newY] == 0)
    {
        // ���� ��ġ ���
        setCursorPosition(playerX, playerY);
        printf("�� ");

        playerX = newX;
        playerY = newY;

        // ���ο� ��ġ ���
        setCursorPosition(playerX, playerY);
        printf("P ");
    }
}

// ȯ�� �޽��� ��� �Լ�
void printWelcomeMessage()
{
    printf("�ܷ�(�ܼ� �̷�)�� ���� ���� ȯ���մϴ�!\n\n");
    printf("������ �����Ϸ��� 'start'�� �Է��ϼ���.\n");
    printf("������ �����Ϸ��� 'quit' �Ǵ� 'q'�� �Է��ϼ���.\n");
}

// ������ �޽����� ����ϴ� �Լ�
void printSecretMessage()
{
    // ������ �޽��� ��� �ڵ� ��ġ
    printf("������ ���̶�� �����ϳ�?\n");
    printf("�̷��� �ý��ϰ� ���� �����̾��ٸ� ���۵� �� �ߴ�.\n");
    printf("����� ��. ����� �غ��ڰ�.");
}

// ���� ���� ����
void gameLoop()
{
    int level = 1;
    while (level <= TOTAL_LEVELS)
    {
        rows = INITIAL_ROWS + (level - 1) * LEVEL_INCREASE;
        cols = INITIAL_COLS + (level - 1) * LEVEL_INCREASE;

        maze = createMaze(rows, cols);
        initializeMaze();
        generateMaze(startX, startY);
        setEndPoint();

        playerX = startX;
        playerY = startY;

        system("cls"); // �ܼ� ȭ���� ����ϴ�
        hideCursor();
        printMaze();
        printMessage(level);

        while (1)
        {
            if (_kbhit())
            {
                char direction = _getch();
                if (direction == 'q')
                {
                    showCursor();
                    freeMaze(maze, rows);
                    printf("\n������ ����Ǿ����ϴ�.\n");
                    return;
                }
                movePlayer(direction);

                if (playerX == endX && playerY == endY)
                {
                    showCursor();
                    printf("\n%d�ܰ踦 �Ϸ��Ͽ����ϴ�!\n", level);
                    freeMaze(maze, rows);
                    level++;
                    break;
                }
            }
        }
    }

    showCursor();
    printSecretMessage(); // ��� �ܰ踦 �Ϸ����� �� ������ �޽��� ���
    printf("\n�����մϴ�! ��� �ܰ踦 �Ϸ��Ͽ����ϴ�!\n");
}

int main()
{
    srand((unsigned int)time(NULL));
    printWelcomeMessage();

    while (1)
    {
        printf("\n����� �Է��ϼ���: ");
        scanf("%s", input);

        if (strcmp(input, "start") == 0)
        {
            gameLoop();
            break;
        }
        else if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0)
        {
            printf("������ ����Ǿ����ϴ�.\n");
            break;
        }
        else
        {
            printf("�� �� ���� ����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }

    return 0;
}
