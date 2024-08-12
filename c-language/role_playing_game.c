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
    int potions; // 회복 아이템 수량
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
    int drop_potion_chance; // 포션 드롭 확률
} Enemy;

void explainWorld()
{
    printf("======================================\n");
    printf("푸른 녹음과 맑고 청명한 물줄기가 가로지르는 아름다운 땅, 엘라\n\n");
    printf("그러나, 평화는 오래 가지 못할 것이다...\n\n");
    printf("어느 날, 돌연히 정체불명의 괴수들이 나타났다.\n");
    printf("평범한 마물과는 궤를 달리 하는 존재들...\n");
    printf("그들과 맞설 운명의 대적자가 작은 마을에서 탄생한다!\n");
    printf("======================================\n\n");
}

void createCharacter(Character* player)
{
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
    player->potions = 1; // 초기 포션 1개 지급

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
    enemy->drop_potion_chance = 20; // 포션 드롭 확률 20%
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

void usePotion(Character* player)
{
    if (player->potions > 0)
    {
        player->hp = player->max_hp;
        player->potions--;
        printf("%s이(가) 포션을 사용하여 HP를 전부 회복했습니다! 남은 포션: %d\n", player->name, player->potions);
    }
    else
    {
        printf("포션이 없습니다!\n");
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

            if (rand() % 100 < enemy->drop_potion_chance)
            {
                player->potions++;
                printf("포션을 획득했습니다! 현재 포션 수량: %d\n", player->potions);
            }
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

void tutorial(Character* player)
{
    printf("\n[튜토리얼]\n");
    printf("이곳은 엘라의 작은 마을입니다.\n");
    printf("당신은 마을 밖으로 나가 모험을 시작할 준비가 되었습니다.\n");
    printf("우선 기본적인 전투 방법을 배워봅시다.\n");

    Enemy enemy;
    createEnemy(&enemy, player->level);
    battle(player, &enemy);

    printf("\n좋습니다! 전투에서 승리했습니다.\n");
    printf("이제부터 진정한 모험을 시작할 수 있습니다.\n");
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
        printf("3. 포션 사용하기\n");
        printf("4. 게임 종료\n");
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
            printf("포션: %d\n", player->potions);
            break;
        case 3:
            usePotion(player);
            break;
        case 4:
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

    tutorial(&player); // 튜토리얼 에피소드

    gameLoop(&player); // 본격적인 게임 시작

    return 0;
}
