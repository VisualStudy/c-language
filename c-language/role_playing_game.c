#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    char name[50];
    int level;
    int hp;
    int max_hp;
    int attack;
    int defense;
    int experience;
    int gold;
} Character;

typedef struct 
{
    char name[50];
    int hp;
    int max_hp;
    int attack;
    int defense;
    int experience_reward;
    int gold_reward;
} Enemy;

void explainWorld() 
{
    printf("======================================\n");
    printf("Ǫ�� ������ ���� û���� ���ٱⰡ ���������� �Ƹ��ٿ� ��, ����\n\n");
    printf("�׷���, ��ȭ�� ���� ���� ���� ���̴�...\n\n");
    printf("��� ��, ������ ��ü�Ҹ��� �������� ��Ÿ����.");
    printf("======================================\n\n");
}

void createCharacter(Character* player) {
    printf("ĳ���� �̸��� �Է��ϼ���: ");
    fgets(player->name, 50, stdin);
    player->name[strcspn(player->name, "\n")] = '\0';

    player->level = 1;
    player->hp = 100;
    player->max_hp = 100;
    player->attack = 10;
    player->defense = 5;
    player->experience = 0;
    player->gold = 0;

    printf("ȯ���մϴ�, %s!\n", player->name);
}

void createEnemy(Enemy* enemy, int player_level) 
{
    strcpy(enemy->name, "���");
    enemy->max_hp = 50 + rand() % 20 + player_level * 5;
    enemy->hp = enemy->max_hp;
    enemy->attack = 8 + rand() % 5 + player_level * 2;
    enemy->defense = 3 + rand() % 3 + player_level;
    enemy->experience_reward = 20 + rand() % 10 + player_level * 5;
    enemy->gold_reward = 10 + rand() % 10 + player_level * 2;
}

void levelUp(Character* player) 
{
    if (player->experience >= player->level * 100) 
    {
        player->level++;
        player->max_hp += 20;
        player->hp = player->max_hp;
        player->attack += 5;
        player->defense += 3;
        player->experience = 0;
        printf("\n���� ��! ���� ����: %d\n", player->level);
        printf("HP: %d, ���ݷ�: %d, ����: %d\n", player->max_hp, player->attack, player->defense);
    }
}

void battle(Character* player, Enemy* enemy) 
{
    printf("\n������ ���۵Ǿ����ϴ�! %s vs %s\n", player->name, enemy->name);

    while (player->hp > 0 && enemy->hp > 0) 
    {
        int player_damage = player->attack - enemy->defense;
        if (player_damage < 0) player_damage = 0;
        enemy->hp -= player_damage;
        printf("%s��(��) %s���� %d�� ���ظ� �������ϴ�! %s�� HP: %d/%d\n",
            player->name, enemy->name, player_damage, enemy->name, enemy->hp, enemy->max_hp);

        if (enemy->hp <= 0) 
        {
            printf("%s��(��) �¸��߽��ϴ�!\n", player->name);
            player->experience += enemy->experience_reward;
            player->gold += enemy->gold_reward;
            printf("����ġ +%d, ��� +%d\n", enemy->experience_reward, enemy->gold_reward);
            levelUp(player);
            break;
        }

        int enemy_damage = enemy->attack - player->defense;
        if (enemy_damage < 0) enemy_damage = 0;
        player->hp -= enemy_damage;
        printf("%s��(��) %s���� %d�� ���ظ� �������ϴ�! %s�� HP: %d/%d\n",
            enemy->name, player->name, enemy_damage, player->name, player->hp, player->max_hp);

        if (player->hp <= 0) 
        {
            printf("%s��(��) ���������ϴ�...\n", player->name);
            printf("���� ����!\n");
            exit(0);
        }
    }
}

void adventure(Character* player) 
{
    printf("\n������ �����ϴ�...\n");

    Enemy enemy;
    createEnemy(&enemy, player->level);
    battle(player, &enemy);
}

void gameLoop(Character* player) 
{
    int choice;

    while (1) 
    {
        printf("\n������ �Ͻðڽ��ϱ�?\n");
        printf("1. ���� ������\n");
        printf("2. �� ���� ����\n");
        printf("3. ���� ����\n");
        printf("����: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
        {
        case 1:
            adventure(player);
            break;
        case 2:
            printf("\n%s�� ����:\n", player->name);
            printf("����: %d\n", player->level);
            printf("HP: %d/%d\n", player->hp, player->max_hp);
            printf("���ݷ�: %d\n", player->attack);
            printf("����: %d\n", player->defense);
            printf("����ġ: %d\n", player->experience);
            printf("���: %d\n", player->gold);
            break;
        case 3:
            printf("������ �����մϴ�. �ȳ��� ������!\n");
            exit(0);
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
}

int main() 
{
    srand(time(NULL));

    explainWorld(); // ����� ���� ���

    Character player;
    createCharacter(&player);
    gameLoop(&player);

    return 0;
}
