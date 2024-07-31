#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#define INITIAL_ROWS 10
#define INITIAL_COLS 10
#define TOTAL_LEVELS 5
#define LEVEL_INCREASE 5 // 단계당 증가할 미로 크기

int** maze;
int startX = 0, startY = 0;
int endX, endY;
int playerX = 0, playerY = 0;
int rows, cols;

// 상하좌우 방향 정의
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 동적 2차원 배열 생성 함수
int** createMaze(int rows, int cols)
{
    int** maze = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        maze[i] = (int*)malloc(cols * sizeof(int));
    }
    return maze;
}

// 동적 2차원 배열 해제 함수
void freeMaze(int** maze, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(maze[i]);
    }
    free(maze);
}

// 미로를 초기화하는 함수
void initializeMaze()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            maze[i][j] = 1; // 벽으로 초기화
        }
    }
}

// 깊이 우선 탐색을 이용한 미로 생성 함수
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

// 목표 지점 설정 함수
void setEndPoint()
{
    do
    {
        endX = rand() % (rows - 2) + 1;
        endY = rand() % (cols - 2) + 1;
    } while (maze[endX][endY] == 1 || (endX == startX && endY == startY));
}

// 미로를 출력하는 함수
void printMaze()
{
    static int prevPlayerX = -1, prevPlayerY = -1;

    if (prevPlayerX != -1 && prevPlayerY != -1)
    {
        printf("\033[%d;%dH□", prevPlayerX + 1, prevPlayerY * 2 + 1);
    }

    printf("\033[%d;%dHP", playerX + 1, playerY * 2 + 1);

    prevPlayerX = playerX;
    prevPlayerY = playerY;
}

// 미로와 메시지를 출력하는 함수
void display()
{
    system("cls");
    printf("사용자의 현재 위치는 'P'(player)로 표현됩니다.\n");
    printf("목표는 목표 지점인 'E'(end point)까지 이동하는 것입니다.\n");
    printf("방향키를 이용하여 이동하세요 (w: 위, s: 아래, a: 왼쪽, d: 오른쪽).\n");
    printf("게임을 종료하려면 'q'를 입력하세요.\n\n");

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

    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && maze[newX][newY] == 0)
    {
        playerX = newX;
        playerY = newY;
    }
}

int main()
{
    char input[10];
    srand(time(NULL));

    printf("콘로(콘솔 미로)에 오신 것을 환영합니다!\n\n");
    printf("사용자의 현재 위치는 'P'(player)로 표현됩니다.\n\n");
    printf("목표는 목표 지점인 'E'(end point)까지 이동하는 것입니다.\n\n");
    printf("언제든 게임을 종료하고 싶다면 'q'를 입력하여 종료하고 선택창으로 넘어갈 수 있습니다.\n\n");
    printf("행운을 빕니다. Good Luck!\n\n");
    printf("게임을 시작하려면 'start'를 입력하세요.\n");
    printf("게임을 종료하려면 'quit' 또는 'q'를 입력하세요.\n");

    while (1)
    {
        scanf("%s", input);

        if (strcmp(input, "start") == 0)
        {
            clock_t startTime = clock();
            for (int level = 1; level <= TOTAL_LEVELS; level++)
            {
                rows = INITIAL_ROWS + (level - 1) * LEVEL_INCREASE;
                cols = INITIAL_COLS + (level - 1) * LEVEL_INCREASE;
                maze = createMaze(rows, cols);

                printf("\n\n%d단계 미로를 시작합니다.\n", level);
                printf("미로를 시작하려면 'yes'를 입력하세요.\n");
                while (1)
                {
                    scanf("%s", input);
                    if (strcmp(input, "yes") == 0) break;
                    else printf("잘못된 입력입니다. 'yes'를 입력하세요.\n");
                }

                initializeMaze();
                generateMaze(startX, startY);
                setEndPoint();

                playerX = startX;
                playerY = startY;

                display();

                while (1)
                {
                    if (playerX == endX && playerY == endY)
                    {
                        printf("\n\n축하합니다! %d단계 미로를 클리어했습니다!\n", level);
                        break;
                    }

                    input[0] = _getch();
                    if (input[0] == 'q')
                    {
                        clock_t endTime = clock();
                        double playTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
                        printf("\n\n게임이 종료되었습니다. 총 플레이 시간: %.2f 초\n", playTime);
                        while (1)
                        {
                            printf("게임을 종료하려면 'quit'을 입력하세요.\n");
                            printf("게임을 다시 시작하려면 'continue'를 입력하세요.\n");
                            scanf("%s", input);
                            if (strcmp(input, "quit") == 0)
                            {
                                freeMaze(maze, rows);
                                return 0;
                            }
                            else if (strcmp(input, "continue") == 0)
                            {
                                startTime = clock();
                                level = 1;
                                break;
                            }
                            else
                            {
                                printf("잘못된 입력입니다. 'quit' 또는 'continue'를 입력하세요.\n");
                            }
                        }
                    }
                    movePlayer(input[0]);
                    printMaze();
                }

                freeMaze(maze, rows);
            }

            clock_t endTime = clock();
            double playTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
            printf("\n\n축하합니다! 모든 미로를 클리어했습니다!\n");
            printf("총 플레이 시간: %.2f 초\n", playTime);

            while (1)
            {
                printf("게임을 종료하려면 'quit'을 입력하세요.\n");
                printf("게임을 다시 시작하려면 'continue'를 입력하세요.\n");
                scanf("%s", input);
                if (strcmp(input, "quit") == 0) break;
                else if (strcmp(input, "continue") == 0)
                {
                    startTime = clock();
                    break;
                }
                else
                {
                    printf("잘못된 입력입니다. 'quit' 또는 'continue'를 입력하세요.\n");
                }
            }

            if (strcmp(input, "quit") == 0) break;
        }
        else if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0)
        {
            printf("게임을 종료합니다.\n");
            break;
        }
        else
        {
            printf("잘못된 입력입니다. 'start' 또는 'quit'을 입력하세요.\n");
        }
    }

    return 0;
}
