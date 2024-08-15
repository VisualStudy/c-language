#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Skill 구조체 정의
typedef struct
{
    char name[50];
    int mp_cost;
    int power;
    void (*effect)(struct Character*, struct Enemy*);
} Skill;

typedef struct
{
    char name[50];
    int level;
    int hp;
    int max_hp;
    int mp;
    int max_mp;
    int attack;
    int defense;
    int agility;
    int intelligence;
    int experience;
    int gold;
    int potions;
    int skill_count;
    Skill* skills[10]; // Skill 구조체에 대한 포인터 배열
} Character;

typedef struct
{
    char name[50];
    int hp;
    int max_hp;
    int attack;
    int defense;
    int agility;
    int intelligence;
    int experience_reward;
    int gold_reward;
    int drop_potion_chance;
} Enemy;

void explainWorld()
{
    printf("======================================\n");
    printf("푸른 녹음과 맑고 청명한 물줄기가 가로지르는 아름다운 땅, 엘라\n\n");
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
    player->mp = 50;
    player->max_mp = 50;
    player->attack = 10;
    player->defense = 5;
    player->agility = 5;
    player->intelligence = 5;
    player->experience = 0;
    player->gold = 0;
    player->potions = 1;
    player->skill_count = 0; // 처음엔 스킬이 없음

    printf("환영합니다, %s!\n", player->name);
}

void createEnemy(Enemy* enemy, int player_level)
{
    strcpy(enemy->name, "고블린");
    enemy->max_hp = 50 + rand() % 20 + player_level * 5;
    enemy->hp = enemy->max_hp;
    enemy->attack = 8 + rand() % 5 + player_level * 2;
    enemy->defense = 3 + rand() % 3 + player_level;
    enemy->agility = 3 + rand() % 3 + player_level;
    enemy->intelligence = 3 + rand() % 3 + player_level;
    enemy->experience_reward = 20 + rand() % 10 + player_level * 5;
    enemy->gold_reward = 10 + rand() % 10 + player_level * 2;
    enemy->drop_potion_chance = 20;
}

void levelUp(Character* player)
{
    if (player->experience >= player->level * 100)
    {
        player->level++;
        player->max_hp += 20;
        player->max_mp += 10;
        player->hp = player->max_hp;
        player->mp = player->max_mp;
        player->attack += 5;
        player->defense += 3;
        player->agility += 2;
        player->intelligence += 2;
        player->experience = 0;
        printf("\n레벨 업! 현재 레벨: %d\n", player->level);
        printf("HP: %d, MP: %d, 공격력: %d, 방어력: %d, 민첩성: %d, 지능: %d\n", player->max_hp, player->max_mp, player->attack, player->defense, player->agility, player->intelligence);
    }
}

void usePotion(Character* player)
{
    if (player->potions > 0)
    {
        int heal_amount = player->intelligence * 10;
        player->hp += heal_amount;
        if (player->hp > player->max_hp) player->hp = player->max_hp;
        player->potions--;
        printf("%s이(가) 포션을 사용하여 %d의 HP를 회복했습니다! 남은 포션: %d\n", player->name, heal_amount, player->potions);
    }
    else
    {
        printf("포션이 없습니다!\n");
    }
}

void attackEnemy(Character* player, Enemy* enemy)
{
    int damage = player->attack - enemy->defense;
    if (damage < 0) damage = 0;
    enemy->hp -= damage;
    printf("%s이(가) %s에게 %d의 피해를 입혔습니다! %s의 HP: %d/%d\n", player->name, enemy->name, damage, enemy->name, enemy->hp, enemy->max_hp);
}

void defend(Character* player, Enemy* enemy)
{
    int reduced_damage = enemy->attack - player->defense * 2;
    if (reduced_damage < 0) reduced_damage = 0;
    player->hp -= reduced_damage;
    printf("%s이(가) 방어했습니다! %s의 공격을 받아 %d의 피해를 입었습니다. HP: %d/%d\n", player->name, enemy->name, reduced_damage, player->hp, player->max_hp);
}

void dodge(Character* player, Enemy* enemy)
{
    int dodge_chance = player->agility * 5;
    if (rand() % 100 < dodge_chance)
    {
        printf("%s이(가) %s의 공격을 회피했습니다!\n", player->name, enemy->name);
    }
    else
    {
        int damage = enemy->attack - player->defense;
        if (damage < 0) damage = 0;
        player->hp -= damage;
        printf("%s이(가) 회피에 실패하여 %d의 피해를 입었습니다! HP: %d/%d\n", player->name, damage, player->hp, player->max_hp);
    }
}

void fireball(Character* player, Enemy* enemy)
{
    if (player->mp >= 20)
    {
        player->mp -= 20;
        int damage = player->intelligence * 3 - enemy->defense;
        if (damage < 0) damage = 0;
        enemy->hp -= damage;
        printf("%s이(가) 화염구를 사용하여 %d의 피해를 입혔습니다! %s의 HP: %d/%d\n", player->name, damage, enemy->name, enemy->hp, enemy->max_hp);
    }
    else
    {
        printf("MP가 부족합니다!\n");
    }
}

void healing(Character* player, Enemy* enemy)
{
    if (player->mp >= 15)
    {
        player->mp -= 15;
        int heal_amount = player->intelligence * 4;
        player->hp += heal_amount;
        if (player->hp > player->max_hp) player->hp = player->max_hp;
        printf("%s이(가) 치유를 사용하여 %d의 HP를 회복했습니다! 현재 HP: %d/%d\n", player->name, heal_amount, player->hp, player->max_hp);
    }
    else
    {
        printf("MP가 부족합니다!\n");
    }
}

void skillMenu(Character* player, Enemy* enemy)
{
    if (player->skill_count == 0)
    {
        printf("사용 가능한 스킬이 없습니다!\n");
        return;
    }

    printf("\n[스킬 메뉴]\n");
    for (int i = 0; i < player->skill_count; i++)
    {
        printf("%d. %s (필요 MP: %d)\n", i + 1, player->skills[i]->name, player->skills[i]->mp_cost);
    }
    int skill_choice;
    printf("스킬 선택: ");
    scanf("%d", &skill_choice);
    getchar();

    if (skill_choice > 0 && skill_choice <= player->skill_count)
    {
        Skill* chosen_skill = player->skills[skill_choice - 1];
        if (player->mp >= chosen_skill->mp_cost)
        {
            printf("%s이(가) %s을(를) 사용했습니다!\n", player->name, chosen_skill->name);
            chosen_skill->effect(player, enemy);
        }
        else
        {
            printf("MP가 부족합니다!\n");
        }
    }
    else
    {
        printf("잘못된 선택입니다.\n");
    }
}

void addSkill(Character* player, Skill* new_skill)
{
    if (player->skill_count < 10)
    {
        player->skills[player->skill_count++] = new_skill;
        printf("%s 스킬을 배웠습니다!\n", new_skill->name);
    }
    else
    {
        printf("더 이상 스킬을 배울 수 없습니다!\n");
    }
}

void flee(Character* player, Enemy* enemy)
{
    int flee_chance = player->agility * 3;
    if (rand() % 100 < flee_chance)
    {
        printf("%s이(가) 전투에서 도망쳤습니다!\n", player->name);
        exit(0); // 도망치면 게임을 종료합니다.
    }
    else
    {
        int damage = enemy->attack - player->defense;
        if (damage < 0) damage = 0;
        player->hp -= damage;
        printf("도망치지 못했습니다! %s이(가) %s에게 %d의 피해를 입었습니다! HP: %d/%d\n", player->name, enemy->name, damage, player->hp, player->max_hp);
        // 도망치지 못했을 때 y/n을 묻지 않고 전투를 이어갑니다.
    }
}

void battle(Character* player, Enemy* enemy)
{
    printf("\n전투 시작! %s vs %s\n", player->name, enemy->name);

    while (player->hp > 0 && enemy->hp > 0)
    {
        printf("\n[플레이어 상태] HP: %d/%d, MP: %d/%d\n", player->hp, player->max_hp, player->mp, player->max_mp);
        printf("1. 공격\n2. 방어\n3. 회피\n4. 스킬\n5. 포션 사용\n6. 도망\n선택: ");
        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            attackEnemy(player, enemy);
            break;
        case 2:
            defend(player, enemy);
            break;
        case 3:
            dodge(player, enemy);
            break;
        case 4:
            skillMenu(player, enemy);
            break;
        case 5:
            usePotion(player);
            break;
        case 6:
            flee(player, enemy);
            if (player->hp <= 0 || enemy->hp <= 0) return; // 도망 성공 시 함수 종료
            break;
        default:
            printf("잘못된 선택입니다.\n");
            continue;
        }

        if (enemy->hp > 0)
        {
            int damage = enemy->attack - player->defense;
            if (damage < 0) damage = 0;
            player->hp -= damage;
            printf("%s이(가) %s에게 %d의 피해를 입혔습니다! %s의 HP: %d/%d\n", enemy->name, player->name, damage, player->name, player->hp, player->max_hp);
        }
    }

    if (player->hp > 0)
    {
        printf("\n%s이(가) 승리했습니다!\n", player->name);
        player->experience += enemy->experience_reward;
        player->gold += enemy->gold_reward;
        if (rand() % 100 < enemy->drop_potion_chance)
        {
            player->potions++;
            printf("포션을 획득했습니다! 현재 포션 개수: %d\n", player->potions);
        }
        levelUp(player);
    }
    else
    {
        printf("\n%s이(가) 패배했습니다...\n", player->name);
    }
}

int main()
{
    srand(time(0));

    Character player;
    Enemy enemy;

    explainWorld();
    createCharacter(&player);

    // 스킬은 기본적으로 없으므로 직접 추가해주는 부분이 필요
    // Skill fireball_skill = {"화염구", 20, 50, fireball}; // 스킬을 나중에 배울 수 있도록 예시로 추가했습니다.
    // addSkill(&player, &fireball_skill);

    char choice;
    do
    {
        createEnemy(&enemy, player.level);
        battle(&player, &enemy);

        printf("계속하시겠습니까? (y/n): ");
        choice = getchar();
        getchar();
    } while (choice == 'y' || choice == 'Y');

    printf("게임을 종료합니다.\n");
    return 0;
}
