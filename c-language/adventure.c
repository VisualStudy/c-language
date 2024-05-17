#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 탐험가 구조체 정의
typedef struct {
    int x;
    int y;
    int health;
    int attack;
} Explorer;

// 미로 지형을 나타내는 상수 정의
#define MAZE_SIZE 5

// 미로 배열 정의
char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#'}
};

// 보물 위치를 랜덤하게 생성하는 함수
void placeTreasure() {
    int tx, ty;
    do {
        tx = rand() % (MAZE_SIZE - 2) + 1;
        ty = rand() % (MAZE_SIZE - 2) + 1;
    } while (maze[ty][tx] != ' ');
    maze[ty][tx] = 'T';
}

// 미로 출력 함수
void printMaze(Explorer player) {
    for (int y = 0; y < MAZE_SIZE; y++) {
        for (int x = 0; x < MAZE_SIZE; x++) {
            if (player.x == x && player.y == y)
                printf("P ");
            else
                printf("%c ", maze[y][x]);
        }
        printf("\n");
    }
}

// 게임 메인 함수
int main() {
    srand((unsigned int)time(NULL)); // 난수 시드 초기화

    // 탐험가 초기화
    Explorer player = { 1, 1, 100, 10 };

    // 보물 위치 설정
    placeTreasure();

    // 게임 루프
    while (player.health > 0) {
        system("cls"); // 화면 지우기 (Windows에서는 "cls" 사용)
        printMaze(player);

        // 게임 로직은 여기에 추가
        printf("이동 방향을 선택하세요 (w: 위, a: 왼쪽, s: 아래, d: 오른쪽): ");
        char input;
        scanf_s(" %c", &input, sizeof(input)); // 반환값을 사용하지 않음

        int nx = player.x, ny = player.y;
        switch (input) {
        case 'w': ny--; break;
        case 'a': nx--; break;
        case 's': ny++; break;
        case 'd': nx++; break;
        default: printf("잘못된 입력입니다.\n"); continue;
        }

        // 이동한 위치가 미로 범위 내에 있는지 확인
        if (nx >= 0 && nx < MAZE_SIZE && ny >= 0 && ny < MAZE_SIZE) {
            // 이동한 위치가 벽이 아니면 탐험가 이동
            if (maze[ny][nx] != '#') {
                player.x = nx;
                player.y = ny;

                // 보물을 찾았는지 확인
                if (maze[ny][nx] == 'T') {
                    printf("축하합니다! 보물을 찾았습니다!\n");
                    break; // 게임 종료
                }
            }
            else {
                printf("벽입니다. 다른 방향을 선택하세요.\n");
            }
        }
        else {
            printf("미로 범위를 벗어났습니다. 다른 방향을 선택하세요.\n");
        }
    }

    // 게임 종료 메시지
    if (player.health <= 0)
        printf("탐험가가 죽었습니다. 게임 오버!\n");

    return 0;
}
