#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ž�谡 ����ü ����
typedef struct {
    int x;
    int y;
    int health;
    int attack;
} Explorer;

// �̷� ������ ��Ÿ���� ��� ����
#define MAZE_SIZE 5

// �̷� �迭 ����
char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#'}
};

// ���� ��ġ�� �����ϰ� �����ϴ� �Լ�
void placeTreasure() {
    int tx, ty;
    do {
        tx = rand() % (MAZE_SIZE - 2) + 1;
        ty = rand() % (MAZE_SIZE - 2) + 1;
    } while (maze[ty][tx] != ' ');
    maze[ty][tx] = 'T';
}

// �̷� ��� �Լ�
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

// ���� ���� �Լ�
int main() {
    srand((unsigned int)time(NULL)); // ���� �õ� �ʱ�ȭ

    // Ž�谡 �ʱ�ȭ
    Explorer player = { 1, 1, 100, 10 };

    // ���� ��ġ ����
    placeTreasure();

    // ���� ����
    while (player.health > 0) {
        system("cls"); // ȭ�� ����� (Windows������ "cls" ���)
        printMaze(player);

        // ���� ������ ���⿡ �߰�
        printf("�̵� ������ �����ϼ��� (w: ��, a: ����, s: �Ʒ�, d: ������): ");
        char input;
        scanf_s(" %c", &input, sizeof(input)); // ��ȯ���� ������� ����

        int nx = player.x, ny = player.y;
        switch (input) {
        case 'w': ny--; break;
        case 'a': nx--; break;
        case 's': ny++; break;
        case 'd': nx++; break;
        default: printf("�߸��� �Է��Դϴ�.\n"); continue;
        }

        // �̵��� ��ġ�� �̷� ���� ���� �ִ��� Ȯ��
        if (nx >= 0 && nx < MAZE_SIZE && ny >= 0 && ny < MAZE_SIZE) {
            // �̵��� ��ġ�� ���� �ƴϸ� Ž�谡 �̵�
            if (maze[ny][nx] != '#') {
                player.x = nx;
                player.y = ny;

                // ������ ã�Ҵ��� Ȯ��
                if (maze[ny][nx] == 'T') {
                    printf("�����մϴ�! ������ ã�ҽ��ϴ�!\n");
                    break; // ���� ����
                }
            }
            else {
                printf("���Դϴ�. �ٸ� ������ �����ϼ���.\n");
            }
        }
        else {
            printf("�̷� ������ ������ϴ�. �ٸ� ������ �����ϼ���.\n");
        }
    }

    // ���� ���� �޽���
    if (player.health <= 0)
        printf("Ž�谡�� �׾����ϴ�. ���� ����!\n");

    return 0;
}
