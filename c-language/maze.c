#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // 플레이 타임 계산
#include <conio.h>  // Windows 전용 헤더 파일
#include <string.h> // 문자열 비교를 위한 헤더 파일

#define ROWS 10
#define COLS 10
#define TOTAL_LEVELS 5

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
// DFS(Depth-First Search)를 이용하여 미로를 생성합니다.
// 현재 위치에서 무작위로 방향을 선택하고, 해당 방향으로 2칸 이동하여 길을 만듭니다.
// 이동한 위치에서 다시 무작위 방향으로 길을 만듭니다. 더 이상 이동할 수 없을 때까지 반복합니다.
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
    // 화면 지우기 대신에, 현재 위치와 지우기 정보를 기록하여 변경된 부분만 업데이트
    static int prevPlayerX = -1, prevPlayerY = -1;

    if (prevPlayerX != -1 && prevPlayerY != -1) 
    {
        // 이전 플레이어 위치를 지움
        printf("\033[%d;%dH□", prevPlayerX + 1, prevPlayerY * 2 + 1);
    }

    // 새로운 플레이어 위치를 출력
    printf("\033[%d;%dHP", playerX + 1, playerY * 2 + 1);

    // 화면 커서 이동을 위한 위치 기록
    prevPlayerX = playerX;
    prevPlayerY = playerY;
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
            clock_t startTime = clock(); // 전체 게임 시작 시간 기록
            for (int level = 1; level <= TOTAL_LEVELS; level++) 
            {
                printf("%d단계 미로를 시작합니다.\n", level);
                printf("미로를 시작하려면 'yes'를 입력하세요.\n");
                while (1) 
                {
                    scanf("%s", input);
                    if (strcmp(input, "yes") == 0) break;
                    else printf("잘못된 입력입니다. 'yes'를 입력하세요.\n");
                }

                initializeMaze();
                generateMaze(startX, startY);
                setEndPoint(); // 목표 지점 설정

                playerX = startX; // 플레이어 초기 위치 설정
                playerY = startY;

                // 화면 초기화 및 미로 출력
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
                            printf("□ ");
                        else
                            printf("■ ");
                    }
                    printf("\n");
                }

                while (1)
                {
                    printMaze();
                    if (playerX == endX && playerY == endY)
                    {
                        printf("\n\n축하합니다! %d단계 미로를 클리어했습니다!\n", level);
                        break;
                    }

                    input[0] = _getch(); // 방향키 입력 대기
                    if (input[0] == 'q') 
                    {
                        clock_t endTime = clock(); // 게임 종료 시간 기록
                        double playTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
                        printf("게임이 종료되었습니다. 총 플레이 시간: %.2f 초\n", playTime);
                        while (1) 
                        {
                            printf("게임을 종료하려면 'quit'을 입력하세요.\n");
                            printf("게임을 다시 시작하려면 'continue'를 입력하세요.\n");
                            scanf("%s", input);
                            if (strcmp(input, "quit") == 0) return 0;
                            else if (strcmp(input, "continue") == 0) 
                            {
                                startTime = clock(); // 게임 다시 시작 시간 기록
                                level = 1; // 첫 번째 단계부터 다시 시작
                                break;
                            }
                            else 
                            {
                                printf("잘못된 입력입니다. 'quit' 또는 'continue'를 입력하세요.\n");
                            }
                        }
                    }
                    movePlayer(input[0]);
                }
            }

            clock_t endTime = clock(); // 전체 게임 종료 시간 기록
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
                    startTime = clock(); // 게임 다시 시작 시간 기록
                    break;
                }
                else {
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
