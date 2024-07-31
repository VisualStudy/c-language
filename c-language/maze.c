#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // �÷��� Ÿ�� ���
#include <conio.h>  // Windows ���� ��� ����
#include <string.h> // ���ڿ� �񱳸� ���� ��� ����

#define ROWS 10
#define COLS 10
#define TOTAL_LEVELS 5

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
// DFS(Depth-First Search)�� �̿��Ͽ� �̷θ� �����մϴ�.
// ���� ��ġ���� �������� ������ �����ϰ�, �ش� �������� 2ĭ �̵��Ͽ� ���� ����ϴ�.
// �̵��� ��ġ���� �ٽ� ������ �������� ���� ����ϴ�. �� �̻� �̵��� �� ���� ������ �ݺ��մϴ�.
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
    // ȭ�� ����� ��ſ�, ���� ��ġ�� ����� ������ ����Ͽ� ����� �κи� ������Ʈ
    static int prevPlayerX = -1, prevPlayerY = -1;

    if (prevPlayerX != -1 && prevPlayerY != -1) 
    {
        // ���� �÷��̾� ��ġ�� ����
        printf("\033[%d;%dH��", prevPlayerX + 1, prevPlayerY * 2 + 1);
    }

    // ���ο� �÷��̾� ��ġ�� ���
    printf("\033[%d;%dHP", playerX + 1, playerY * 2 + 1);

    // ȭ�� Ŀ�� �̵��� ���� ��ġ ���
    prevPlayerX = playerX;
    prevPlayerY = playerY;
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
    char input[10];
    srand(time(NULL));

    printf("�ܷ�(�ܼ� �̷�)�� ���� ���� ȯ���մϴ�!\n\n");
    printf("������� ���� ��ġ�� 'P'(player)�� ǥ���˴ϴ�.\n\n");
    printf("��ǥ�� ��ǥ ������ 'E'(end point)���� �̵��ϴ� ���Դϴ�.\n\n");
    printf("������ ������ �����ϰ� �ʹٸ� 'q'�� �Է��Ͽ� �����ϰ� ����â���� �Ѿ �� �ֽ��ϴ�.\n\n");
    printf("����� ���ϴ�. Good Luck!\n\n");
    printf("������ �����Ϸ��� 'start'�� �Է��ϼ���.\n");
    printf("������ �����Ϸ��� 'quit' �Ǵ� 'q'�� �Է��ϼ���.\n");

    while (1)
    {
        scanf("%s", input);

        if (strcmp(input, "start") == 0) 
        {
            clock_t startTime = clock(); // ��ü ���� ���� �ð� ���
            for (int level = 1; level <= TOTAL_LEVELS; level++) 
            {
                printf("%d�ܰ� �̷θ� �����մϴ�.\n", level);
                printf("�̷θ� �����Ϸ��� 'yes'�� �Է��ϼ���.\n");
                while (1) 
                {
                    scanf("%s", input);
                    if (strcmp(input, "yes") == 0) break;
                    else printf("�߸��� �Է��Դϴ�. 'yes'�� �Է��ϼ���.\n");
                }

                initializeMaze();
                generateMaze(startX, startY);
                setEndPoint(); // ��ǥ ���� ����

                playerX = startX; // �÷��̾� �ʱ� ��ġ ����
                playerY = startY;

                // ȭ�� �ʱ�ȭ �� �̷� ���
                system("cls");
                for (int i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLS; j++)
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

                while (1)
                {
                    printMaze();
                    if (playerX == endX && playerY == endY)
                    {
                        printf("\n\n�����մϴ�! %d�ܰ� �̷θ� Ŭ�����߽��ϴ�!\n", level);
                        break;
                    }

                    input[0] = _getch(); // ����Ű �Է� ���
                    if (input[0] == 'q') 
                    {
                        clock_t endTime = clock(); // ���� ���� �ð� ���
                        double playTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
                        printf("������ ����Ǿ����ϴ�. �� �÷��� �ð�: %.2f ��\n", playTime);
                        while (1) 
                        {
                            printf("������ �����Ϸ��� 'quit'�� �Է��ϼ���.\n");
                            printf("������ �ٽ� �����Ϸ��� 'continue'�� �Է��ϼ���.\n");
                            scanf("%s", input);
                            if (strcmp(input, "quit") == 0) return 0;
                            else if (strcmp(input, "continue") == 0) 
                            {
                                startTime = clock(); // ���� �ٽ� ���� �ð� ���
                                level = 1; // ù ��° �ܰ���� �ٽ� ����
                                break;
                            }
                            else 
                            {
                                printf("�߸��� �Է��Դϴ�. 'quit' �Ǵ� 'continue'�� �Է��ϼ���.\n");
                            }
                        }
                    }
                    movePlayer(input[0]);
                }
            }

            clock_t endTime = clock(); // ��ü ���� ���� �ð� ���
            double playTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
            printf("\n\n�����մϴ�! ��� �̷θ� Ŭ�����߽��ϴ�!\n");
            printf("�� �÷��� �ð�: %.2f ��\n", playTime);

            while (1) 
            {
                printf("������ �����Ϸ��� 'quit'�� �Է��ϼ���.\n");
                printf("������ �ٽ� �����Ϸ��� 'continue'�� �Է��ϼ���.\n");
                scanf("%s", input);
                if (strcmp(input, "quit") == 0) break;
                else if (strcmp(input, "continue") == 0) 
                {
                    startTime = clock(); // ���� �ٽ� ���� �ð� ���
                    break;
                }
                else {
                    printf("�߸��� �Է��Դϴ�. 'quit' �Ǵ� 'continue'�� �Է��ϼ���.\n");
                }
            }

            if (strcmp(input, "quit") == 0) break;
        }
        else if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0)
        {
            printf("������ �����մϴ�.\n");
            break;
        }
        else
        {
            printf("�߸��� �Է��Դϴ�. 'start' �Ǵ� 'quit'�� �Է��ϼ���.\n");
        }
    }

    return 0;
}
