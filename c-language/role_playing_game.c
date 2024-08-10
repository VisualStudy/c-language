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
    printf("푸른 녹음과 맑고 청명한 물줄기가 가로지르는 아름다운 땅, 엘라\n\n");
    printf("그러나, 평화는 오래 가지 못할 것이다...\n\n");
    printf("어느 날, 돌연히 정체불명의 괴수들이 나타났다.");
    printf("======================================\n\n");
}

void createCharacter(Character* player) {
    printf("캐릭터 이름을 입력하세요: ");
    fgets(player->name, 50, stdin);
    player->name[strcspn(player->name, "\n")] = '\0';

    player->level = 1;
    player->hp = 100;
    player->max_hp = 100;
    player->attack = 10;
    player->defense = 5;
    player->experience = 0;
    player->gold = 0;

    printf("환영합니다, %s!\n", player->name);
}

void createEnemy(Enemy* enemy, int player_level) 
{
    strcpy(enemy->name, "고블린");
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
        printf("\n레벨 업! 현재 레벨: %d\n", player->level);
        printf("HP: %d, 공격력: %d, 방어력: %d\n", player->max_hp, player->attack, player->defense);
    }
}

void battle(Character* player, Enemy* enemy) 
{
    printf("\n전투가 시작되었습니다! %s vs %s\n", player->name, enemy->name);

    while (player->hp > 0 && enemy->hp > 0) 
    {
        int player_damage = player->attack - enemy->defense;
        if (player_damage < 0) player_damage = 0;
        enemy->hp -= player_damage;
        printf("%s이(가) %s에게 %d의 피해를 입혔습니다! %s의 HP: %d/%d\n",
            player->name, enemy->name, player_damage, enemy->name, enemy->hp, enemy->max_hp);

        if (enemy->hp <= 0) 
        {
            printf("%s이(가) 승리했습니다!\n", player->name);
            player->experience += enemy->experience_reward;
            player->gold += enemy->gold_reward;
            printf("경험치 +%d, 골드 +%d\n", enemy->experience_reward, enemy->gold_reward);
            levelUp(player);
            break;
        }

        int enemy_damage = enemy->attack - player->defense;
        if (enemy_damage < 0) enemy_damage = 0;
        player->hp -= enemy_damage;
        printf("%s이(가) %s에게 %d의 피해를 입혔습니다! %s의 HP: %d/%d\n",
            enemy->name, player->name, enemy_damage, player->name, player->hp, player->max_hp);

        if (player->hp <= 0) 
        {
            printf("%s이(가) 쓰러졌습니다...\n", player->name);
            printf("게임 오버!\n");
            exit(0);
        }
    }
}

void adventure(Character* player) 
{
    printf("\n모험을 떠납니다...\n");

    Enemy enemy;
    createEnemy(&enemy, player->level);
    battle(player, &enemy);
}

void gameLoop(Character* player) 
{
    int choice;

    while (1) 
    {
        printf("\n무엇을 하시겠습니까?\n");
        printf("1. 모험 떠나기\n");
        printf("2. 내 상태 보기\n");
        printf("3. 게임 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
        {
        case 1:
            adventure(player);
            break;
        case 2:
            printf("\n%s의 상태:\n", player->name);
            printf("레벨: %d\n", player->level);
            printf("HP: %d/%d\n", player->hp, player->max_hp);
            printf("공격력: %d\n", player->attack);
            printf("방어력: %d\n", player->defense);
            printf("경험치: %d\n", player->experience);
            printf("골드: %d\n", player->gold);
            break;
        case 3:
            printf("게임을 종료합니다. 안녕히 가세요!\n");
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
}

int main() 
{
    srand(time(NULL));

    explainWorld(); // 세계관 설명 출력

    Character player;
    createCharacter(&player);
    gameLoop(&player);

    return 0;
}
