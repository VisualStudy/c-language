#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

typedef struct Character Character;
typedef struct Enemy Enemy;

typedef struct {
    char name[50];
    int mp_cost;
    void (*effect)(Character*, Enemy*);
} Skill;

struct Character {
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
    Skill* skills[10];
};

struct Enemy {
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
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void explainWorld() {
    clearScreen();
    printf("======================================\n");
    printf("푸른 녹음과 맑고 청명한 물줄기가 가로지르는 아름다운 땅, 엘라\n\n");
    printf("======================================\n\n");
}

void createCharacter(Character* player) {
    clearScreen();
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
    player->skill_count = 0;

    printf("환영합니다, %s!\n", player->name);
    printf("캐릭터 생성 완료!\n");
    printf("잠시 후 게임이 시작됩니다...\n");
    sleep(2);
    clearScreen();
}

void createEnemy(Enemy* enemy, int player_level) {
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

void levelUp(Character* player) {
    if (player->experience >= player->level * 100) {
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
        printf("HP: %d, MP: %d, 공격력: %d, 방어력: %d, 민첩성: %d, 지능: %d\n",
            player->max_hp, player->max_mp, player->attack, player->defense, player->agility, player->intelligence);
    }
}

void usePotion(Character* player) {
    if (player->potions > 0) {
        int heal_amount = player->intelligence * 10;
        player->hp += heal_amount;
        if (player->hp > player->max_hp) player->hp = player->max_hp;
        player->potions--;
        printf("%s이(가) 포션을 사용하여 %d의 HP를 회복했습니다! 남은 포션: %d\n",
            player->name, heal_amount, player->potions);
    }
    else {
        printf("포션이 없습니다!\n");
    }
}

void attackEnemy(Character* player, Enemy* enemy) {
    int damage = player->attack - enemy->defense;
    if (damage < 0) damage = 0;
    enemy->hp -= damage;
    printf("%s이(가) %s에게 %d의 피해를 입혔습니다! %s의 HP: %d/%d\n",
        player->name, enemy->name, damage, enemy->name, enemy->hp, enemy->max_hp);
}

void defend(Character* player, Enemy* enemy) {
    int reduced_damage = enemy->attack - player->defense * 2;
    if (reduced_damage < 0) reduced_damage = 0;
    player->hp -= reduced_damage;
    printf("%s이(가) 방어했습니다! %s의 공격을 받아 %d의 피해를 입었습니다. HP: %d/%d\n",
        player->name, enemy->name, reduced_damage, player->hp, player->max_hp);
}

void dodge(Character* player, Enemy* enemy) {
    int dodge_chance = player->agility * 5;
    if (rand() % 100 < dodge_chance) {
        printf("%s이(가) %s의 공격을 회피했습니다!\n", player->name, enemy->name);
    }
    else {
        int damage = enemy->attack - player->defense;
        if (damage < 0) damage = 0;
        player->hp -= damage;
        printf("%s이(가) 회피에 실패하여 %d의 피해를 입었습니다! HP: %d/%d\n",
            player->name, damage, player->hp, player->max_hp);
    }
}

void fireball(Character* player, Enemy* enemy) {
    if (player->mp >= 20) {
        player->mp -= 20;
        int damage = player->intelligence * 3 - enemy->defense;
        if (damage < 0) damage = 0;
        enemy->hp -= damage;
        printf("%s이(가) 화염구를 사용하여 %s에게 %d의 피해를 입혔습니다! 남은 MP: %d\n",
            player->name, enemy->name, damage, player->mp);
    }
    else {
        printf("MP가 부족합니다!\n");
    }
}

void healing(Character* player, Enemy* enemy) {
    if (player->mp >= 15) {
        player->mp -= 15;
        int heal_amount = player->intelligence * 5;
        player->hp += heal_amount;
        if (player->hp > player->max_hp) player->hp = player->max_hp;
        printf("%s이(가) 회복 주문을 사용하여 %d의 HP를 회복했습니다! 남은 MP: %d\n",
            player->name, heal_amount, player->mp);
    }
    else {
        printf("MP가 부족합니다!\n");
    }
}

void useSkill(Character* player, Enemy* enemy) {
    if (player->skill_count == 0) {
        printf("사용할 수 있는 스킬이 없습니다!\n");
        return;
    }

    printf("사용할 스킬을 선택하세요:\n");
    for (int i = 0; i < player->skill_count; i++) {
        printf("%d. %s (MP 소모: %d)\n", i + 1, player->skills[i]->name, player->skills[i]->mp_cost);
    }

    int choice;
    printf("선택: ");
    scanf("%d", &choice);
    getchar();

    if (choice < 1 || choice > player->skill_count) {
        printf("잘못된 선택입니다!\n");
        return;
    }

    Skill* skill = player->skills[choice - 1];
    skill->effect(player, enemy);
}

void addSkill(Character* player, Skill* skill) {
    if (player->skill_count < 10) {
        player->skills[player->skill_count++] = skill;
        printf("%s이(가) 스킬 '%s'을(를) 배웠습니다!\n", player->name, skill->name);
    }
    else {
        printf("더 이상 스킬을 배울 수 없습니다!\n");
    }
}

void battle(Character* player, Enemy* enemy) {
    printf("전투가 시작됩니다! 상대: %s (HP: %d, 공격력: %d)\n", enemy->name, enemy->hp, enemy->attack);
    while (enemy->hp > 0 && player->hp > 0) {
        printf("\n1. 공격\n2. 방어\n3. 회피\n4. 스킬 사용\n5. 포션 사용\n선택: ");
        int choice;
        scanf("%d", &choice);

        // 개행 문자 제거
        while (getchar() != '\n');

        switch (choice) {
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
            useSkill(player, enemy);
            break;
        case 5:
            usePotion(player);
            break;
        default:
            printf("잘못된 선택입니다!\n");
            continue;
        }

        if (enemy->hp > 0) {
            int damage = enemy->attack - player->defense;
            if (damage < 0) damage = 0;
            player->hp -= damage;
            printf("%s이(가) %s의 공격을 받아 %d의 피해를 입었습니다! HP: %d/%d\n",
                player->name, enemy->name, damage, player->hp, player->max_hp);
        }
    }

    if (player->hp <= 0) {
        printf("\n%s이(가) 쓰러졌습니다...\n", player->name);
    }
    else if (enemy->hp <= 0) {
        printf("\n%s이(가) %s을(를) 물리쳤습니다!\n", player->name, enemy->name);
        player->experience += enemy->experience_reward;
        player->gold += enemy->gold_reward;
        if (rand() % 100 < enemy->drop_potion_chance) {
            player->potions++;
            printf("전리품으로 포션을 얻었습니다! 포션: %d\n", player->potions);
        }
        levelUp(player);
    }
}


int main() {
    srand(time(NULL));

    Character player;
    Enemy enemy;

    Skill fireball_skill = { "화염구", 20, fireball };
    Skill healing_skill = { "회복 주문", 15, healing };

    createCharacter(&player);
    addSkill(&player, &fireball_skill);
    addSkill(&player, &healing_skill);

    explainWorld();

    while (player.hp > 0) {
        createEnemy(&enemy, player.level);
        battle(&player, &enemy);

        if (player.hp > 0) {
            printf("\n모험을 계속하시겠습니까? (y/n): ");
            char choice;
            scanf("%c", &choice);
            getchar();

            if (choice == 'n' || choice == 'N') {
                printf("모험을 마칩니다...\n");
                break;
            }
        }
        else {
            printf("모험이 끝났습니다...\n");
        }
    }

    printf("게임을 종료합니다. 감사합니다!\n");

    return 0;
}
