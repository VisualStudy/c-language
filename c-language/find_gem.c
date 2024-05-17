#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 보드 크기 상수 정의
#define BOARD_SIZE 5

// 게임 보드 배열 정의
char board[BOARD_SIZE][BOARD_SIZE];

// 보석 위치 구조체 정의
typedef struct {
    int x;
    int y;
} Gem;

// 보석의 위치를 랜덤하게 생성하는 함수
Gem placeGem() {
    Gem gem;
    gem.x = rand() % BOARD_SIZE;
    gem.y = rand() % BOARD_SIZE;
    return gem;
}

// 보드를 초기화하는 함수
void initializeBoard() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board[y][x] = '.';
        }
    }
}

// 보드를 출력하는 함수
void printBoard() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%c ", board[y][x]);
        }
        printf("\n");
    }
}

// 게임 메인 함수
int main() {
    srand((unsigned int)time(NULL)); // 난수 시드 초기화

    initializeBoard(); // 보드 초기화

    // 보석 위치 설정
    Gem gem = placeGem();
    board[gem.y][gem.x] = 'G';

    printf("보석을 찾아주세요! (보석의 위치: %d, %d)\n", gem.x, gem.y);

    // 게임 루프
    while (1) {
        printBoard(); // 보드 출력

        // 플레이어 입력 받기
        int x, y;
        printf("보석의 위치를 입력하세요 (x y): ");
        if (scanf_s("%d %d", &x, &y) != 2) {
            printf("올바른 형식으로 입력하세요.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }

        // 입력한 위치가 보석 위치와 일치하는지 확인
        if (x == gem.x && y == gem.y) {
            printf("보석을 찾았습니다! 게임 종료!\n");
            break; // 게임 종료
        }
        else {
            printf("보석이 여기 있지 않습니다. 다시 찾아보세요!\n");
            printf("입력한 위치: %d, %d\n", x, y);
            printf("보석의 위치: %d, %d\n", gem.x, gem.y);
        }
    }

    return 0;
}
