#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���� ũ�� ��� ����
#define BOARD_SIZE 5

// ���� ���� �迭 ����
char board[BOARD_SIZE][BOARD_SIZE];

// ���� ��ġ ����ü ����
typedef struct {
    int x;
    int y;
} Gem;

// ������ ��ġ�� �����ϰ� �����ϴ� �Լ�
Gem placeGem() {
    Gem gem;
    gem.x = rand() % BOARD_SIZE;
    gem.y = rand() % BOARD_SIZE;
    return gem;
}

// ���带 �ʱ�ȭ�ϴ� �Լ�
void initializeBoard() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board[y][x] = '.';
        }
    }
}

// ���带 ����ϴ� �Լ�
void printBoard() {
    for (int y = BOARD_SIZE - 1; y >= 0; y--) { // ���� �ϴܿ������� ���
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%c ", board[y][x]);
        }
        printf("\n");
    }
}

// ���� ���� �Լ�
int main() {
    srand((unsigned int)time(NULL)); // ���� �õ� �ʱ�ȭ

    initializeBoard(); // ���� �ʱ�ȭ

    // ���� ��ġ ����
    Gem gem = placeGem();
    board[gem.y][gem.x] = 'G';

    printf("������ ã���ּ���! (������ ��ġ: %d, %d)\n", gem.x, gem.y); // ��ǥ ���

    // ���� ����
    while (1) {
        printBoard(); // ���� ���

        // �÷��̾� �Է� �ޱ�
        int x, y;
        printf("������ ��ġ�� �Է��ϼ��� (x y): ");
        if (scanf_s("%d %d", &x, &y) != 2) {
            printf("�ùٸ� �������� �Է��ϼ���.\n");
            while (getchar() != '\n'); // �Է� ���� ����
            continue;
        }

        // �Է��� ��ġ�� ���� ��ġ�� ��ġ�ϴ��� Ȯ��
        if (x == gem.x && y == gem.y) {
            printf("������ ã�ҽ��ϴ�! ���� ����!\n");
            break; // ���� ����
        }
        else {
            printf("������ ���� ���� �ʽ��ϴ�. �ٽ� ã�ƺ�����!\n");
        }
    }

    return 0;
}
