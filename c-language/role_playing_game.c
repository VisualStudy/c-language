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
    printf("Ǫ�� ������ ���� û���� ���ٱⰡ ���������� �Ƹ��ٿ� ��, ����\n\n");
    printf("======================================\n\n");
}

void createCharacter(Character* player) {
    clearScreen();
    printf("ĳ���� �̸��� �Է��ϼ���: ");
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

    printf("ȯ���մϴ�, %s!\n", player->name);
    printf("ĳ���� ���� �Ϸ�!\n");
    printf("��� �� ������ ���۵˴ϴ�...\n");
    sleep(2);
    clearScreen();
}

void createEnemy(Enemy* enemy, int player_level) {
    strcpy(enemy->name, "���");
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
        printf("\n���� ��! ���� ����: %d\n", player->level);
        printf("HP: %d, MP: %d, ���ݷ�: %d, ����: %d, ��ø��: %d, ����: %d\n",
            player->max_hp, player->max_mp, player->attack, player->defense, player->agility, player->intelligence);
    }
}

void usePotion(Character* player) {
    if (player->potions > 0) {
        int heal_amount = player->intelligence * 10;
        player->hp += heal_amount;
        if (player->hp > player->max_hp) player->hp = player->max_hp;
        player->potions--;
        printf("%s��(��) ������ ����Ͽ� %d�� HP�� ȸ���߽��ϴ�! ���� ����: %d\n",
            player->name, heal_amount, player->potions);
    }
    else {
        printf("������ �����ϴ�!\n");
    }
}

void attackEnemy(Character* player, Enemy* enemy) {
    int damage = player->attack - enemy->defense;
    if (damage < 0) damage = 0;
    enemy->hp -= damage;
    printf("%s��(��) %s���� %d�� ���ظ� �������ϴ�! %s�� HP: %d/%d\n",
        player->name, enemy->name, damage, enemy->name, enemy->hp, enemy->max_hp);
}

void defend(Character* player, Enemy* enemy) {
    int reduced_damage = enemy->attack - player->defense * 2;
    if (reduced_damage < 0) reduced_damage = 0;
    player->hp -= reduced_damage;
    printf("%s��(��) ����߽��ϴ�! %s�� ������ �޾� %d�� ���ظ� �Ծ����ϴ�. HP: %d/%d\n",
        player->name, enemy->name, reduced_damage, player->hp, player->max_hp);
}

void dodge(Character* player, Enemy* enemy) {
    int dodge_chance = player->agility * 5;
    if (rand() % 100 < dodge_chance) {
        printf("%s��(��) %s�� ������ ȸ���߽��ϴ�!\n", player->name, enemy->name);
    }
    else {
        int damage = enemy->attack - player->defense;
        if (damage < 0) damage = 0;
        player->hp -= damage;
        printf("%s��(��) ȸ�ǿ� �����Ͽ� %d�� ���ظ� �Ծ����ϴ�! HP: %d/%d\n",
            player->name, damage, player->hp, player->max_hp);
    }
}

void fireball(Character* player, Enemy* enemy) {
    if (player->mp >= 20) {
        player->mp -= 20;
        int damage = player->intelligence * 3 - enemy->defense;
        if (damage < 0) damage = 0;
        enemy->hp -= damage;
        printf("%s��(��) ȭ������ ����Ͽ� %s���� %d�� ���ظ� �������ϴ�! ���� MP: %d\n",
            player->name, enemy->name, damage, player->mp);
    }
    else {
        printf("MP�� �����մϴ�!\n");
    }
}

void healing(Character* player, Enemy* enemy) {
    if (player->mp >= 15) {
        player->mp -= 15;
        int heal_amount = player->intelligence * 5;
        player->hp += heal_amount;
        if (player->hp > player->max_hp) player->hp = player->max_hp;
        printf("%s��(��) ȸ�� �ֹ��� ����Ͽ� %d�� HP�� ȸ���߽��ϴ�! ���� MP: %d\n",
            player->name, heal_amount, player->mp);
    }
    else {
        printf("MP�� �����մϴ�!\n");
    }
}

void useSkill(Character* player, Enemy* enemy) {
    if (player->skill_count == 0) {
        printf("����� �� �ִ� ��ų�� �����ϴ�!\n");
        return;
    }

    printf("����� ��ų�� �����ϼ���:\n");
    for (int i = 0; i < player->skill_count; i++) {
        printf("%d. %s (MP �Ҹ�: %d)\n", i + 1, player->skills[i]->name, player->skills[i]->mp_cost);
    }

    int choice;
    printf("����: ");
    scanf("%d", &choice);
    getchar();

    if (choice < 1 || choice > player->skill_count) {
        printf("�߸��� �����Դϴ�!\n");
        return;
    }

    Skill* skill = player->skills[choice - 1];
    skill->effect(player, enemy);
}

void addSkill(Character* player, Skill* skill) {
    if (player->skill_count < 10) {
        player->skills[player->skill_count++] = skill;
        printf("%s��(��) ��ų '%s'��(��) ������ϴ�!\n", player->name, skill->name);
    }
    else {
        printf("�� �̻� ��ų�� ��� �� �����ϴ�!\n");
    }
}

void battle(Character* player, Enemy* enemy) {
    printf("������ ���۵˴ϴ�! ���: %s (HP: %d, ���ݷ�: %d)\n", enemy->name, enemy->hp, enemy->attack);
    while (enemy->hp > 0 && player->hp > 0) {
        printf("\n1. ����\n2. ���\n3. ȸ��\n4. ��ų ���\n5. ���� ���\n����: ");
        int choice;
        scanf("%d", &choice);

        // ���� ���� ����
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
            printf("�߸��� �����Դϴ�!\n");
            continue;
        }

        if (enemy->hp > 0) {
            int damage = enemy->attack - player->defense;
            if (damage < 0) damage = 0;
            player->hp -= damage;
            printf("%s��(��) %s�� ������ �޾� %d�� ���ظ� �Ծ����ϴ�! HP: %d/%d\n",
                player->name, enemy->name, damage, player->hp, player->max_hp);
        }
    }

    if (player->hp <= 0) {
        printf("\n%s��(��) ���������ϴ�...\n", player->name);
    }
    else if (enemy->hp <= 0) {
        printf("\n%s��(��) %s��(��) �����ƽ��ϴ�!\n", player->name, enemy->name);
        player->experience += enemy->experience_reward;
        player->gold += enemy->gold_reward;
        if (rand() % 100 < enemy->drop_potion_chance) {
            player->potions++;
            printf("����ǰ���� ������ ������ϴ�! ����: %d\n", player->potions);
        }
        levelUp(player);
    }
}


int main() {
    srand(time(NULL));

    Character player;
    Enemy enemy;

    Skill fireball_skill = { "ȭ����", 20, fireball };
    Skill healing_skill = { "ȸ�� �ֹ�", 15, healing };

    createCharacter(&player);
    addSkill(&player, &fireball_skill);
    addSkill(&player, &healing_skill);

    explainWorld();

    while (player.hp > 0) {
        createEnemy(&enemy, player.level);
        battle(&player, &enemy);

        if (player.hp > 0) {
            printf("\n������ ����Ͻðڽ��ϱ�? (y/n): ");
            char choice;
            scanf("%c", &choice);
            getchar();

            if (choice == 'n' || choice == 'N') {
                printf("������ ��Ĩ�ϴ�...\n");
                break;
            }
        }
        else {
            printf("������ �������ϴ�...\n");
        }
    }

    printf("������ �����մϴ�. �����մϴ�!\n");

    return 0;
}
