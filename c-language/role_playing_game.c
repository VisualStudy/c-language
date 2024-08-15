#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Skill ����ü ����
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
    Skill* skills[10]; // Skill ����ü�� ���� ������ �迭
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
    printf("Ǫ�� ������ ���� û���� ���ٱⰡ ���������� �Ƹ��ٿ� ��, ����\n\n");
    printf("======================================\n\n");
}

void createCharacter(Character* player)
{
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
    player->skill_count = 0; // ó���� ��ų�� ����

    printf("ȯ���մϴ�, %s!\n", player->name);
}

void createEnemy(Enemy* enemy, int player_level)
{
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
        printf("\n���� ��! ���� ����: %d\n", player->level);
        printf("HP: %d, MP: %d, ���ݷ�: %d, ����: %d, ��ø��: %d, ����: %d\n", player->max_hp, player->max_mp, player->attack, player->defense, player->agility, player->intelligence);
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
        printf("%s��(��) ������ ����Ͽ� %d�� HP�� ȸ���߽��ϴ�! ���� ����: %d\n", player->name, heal_amount, player->potions);
    }
    else
    {
        printf("������ �����ϴ�!\n");
    }
}

void attackEnemy(Character* player, Enemy* enemy)
{
    int damage = player->attack - enemy->defense;
    if (damage < 0) damage = 0;
    enemy->hp -= damage;
    printf("%s��(��) %s���� %d�� ���ظ� �������ϴ�! %s�� HP: %d/%d\n", player->name, enemy->name, damage, enemy->name, enemy->hp, enemy->max_hp);
}

void defend(Character* player, Enemy* enemy)
{
    int reduced_damage = enemy->attack - player->defense * 2;
    if (reduced_damage < 0) reduced_damage = 0;
    player->hp -= reduced_damage;
    printf("%s��(��) ����߽��ϴ�! %s�� ������ �޾� %d�� ���ظ� �Ծ����ϴ�. HP: %d/%d\n", player->name, enemy->name, reduced_damage, player->hp, player->max_hp);
}

void dodge(Character* player, Enemy* enemy)
{
    int dodge_chance = player->agility * 5;
    if (rand() % 100 < dodge_chance)
    {
        printf("%s��(��) %s�� ������ ȸ���߽��ϴ�!\n", player->name, enemy->name);
    }
    else
    {
        int damage = enemy->attack - player->defense;
        if (damage < 0) damage = 0;
        player->hp -= damage;
        printf("%s��(��) ȸ�ǿ� �����Ͽ� %d�� ���ظ� �Ծ����ϴ�! HP: %d/%d\n", player->name, damage, player->hp, player->max_hp);
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
        printf("%s��(��) ȭ������ ����Ͽ� %d�� ���ظ� �������ϴ�! %s�� HP: %d/%d\n", player->name, damage, enemy->name, enemy->hp, enemy->max_hp);
    }
    else
    {
        printf("MP�� �����մϴ�!\n");
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
        printf("%s��(��) ġ���� ����Ͽ� %d�� HP�� ȸ���߽��ϴ�! ���� HP: %d/%d\n", player->name, heal_amount, player->hp, player->max_hp);
    }
    else
    {
        printf("MP�� �����մϴ�!\n");
    }
}

void skillMenu(Character* player, Enemy* enemy)
{
    if (player->skill_count == 0)
    {
        printf("��� ������ ��ų�� �����ϴ�!\n");
        return;
    }

    printf("\n[��ų �޴�]\n");
    for (int i = 0; i < player->skill_count; i++)
    {
        printf("%d. %s (�ʿ� MP: %d)\n", i + 1, player->skills[i]->name, player->skills[i]->mp_cost);
    }
    int skill_choice;
    printf("��ų ����: ");
    scanf("%d", &skill_choice);
    getchar();

    if (skill_choice > 0 && skill_choice <= player->skill_count)
    {
        Skill* chosen_skill = player->skills[skill_choice - 1];
        if (player->mp >= chosen_skill->mp_cost)
        {
            printf("%s��(��) %s��(��) ����߽��ϴ�!\n", player->name, chosen_skill->name);
            chosen_skill->effect(player, enemy);
        }
        else
        {
            printf("MP�� �����մϴ�!\n");
        }
    }
    else
    {
        printf("�߸��� �����Դϴ�.\n");
    }
}

void addSkill(Character* player, Skill* new_skill)
{
    if (player->skill_count < 10)
    {
        player->skills[player->skill_count++] = new_skill;
        printf("%s ��ų�� ������ϴ�!\n", new_skill->name);
    }
    else
    {
        printf("�� �̻� ��ų�� ��� �� �����ϴ�!\n");
    }
}

void flee(Character* player, Enemy* enemy)
{
    int flee_chance = player->agility * 3;
    if (rand() % 100 < flee_chance)
    {
        printf("%s��(��) �������� �����ƽ��ϴ�!\n", player->name);
        exit(0); // ����ġ�� ������ �����մϴ�.
    }
    else
    {
        int damage = enemy->attack - player->defense;
        if (damage < 0) damage = 0;
        player->hp -= damage;
        printf("����ġ�� ���߽��ϴ�! %s��(��) %s���� %d�� ���ظ� �Ծ����ϴ�! HP: %d/%d\n", player->name, enemy->name, damage, player->hp, player->max_hp);
        // ����ġ�� ������ �� y/n�� ���� �ʰ� ������ �̾�ϴ�.
    }
}

void battle(Character* player, Enemy* enemy)
{
    printf("\n���� ����! %s vs %s\n", player->name, enemy->name);

    while (player->hp > 0 && enemy->hp > 0)
    {
        printf("\n[�÷��̾� ����] HP: %d/%d, MP: %d/%d\n", player->hp, player->max_hp, player->mp, player->max_mp);
        printf("1. ����\n2. ���\n3. ȸ��\n4. ��ų\n5. ���� ���\n6. ����\n����: ");
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
            if (player->hp <= 0 || enemy->hp <= 0) return; // ���� ���� �� �Լ� ����
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
            continue;
        }

        if (enemy->hp > 0)
        {
            int damage = enemy->attack - player->defense;
            if (damage < 0) damage = 0;
            player->hp -= damage;
            printf("%s��(��) %s���� %d�� ���ظ� �������ϴ�! %s�� HP: %d/%d\n", enemy->name, player->name, damage, player->name, player->hp, player->max_hp);
        }
    }

    if (player->hp > 0)
    {
        printf("\n%s��(��) �¸��߽��ϴ�!\n", player->name);
        player->experience += enemy->experience_reward;
        player->gold += enemy->gold_reward;
        if (rand() % 100 < enemy->drop_potion_chance)
        {
            player->potions++;
            printf("������ ȹ���߽��ϴ�! ���� ���� ����: %d\n", player->potions);
        }
        levelUp(player);
    }
    else
    {
        printf("\n%s��(��) �й��߽��ϴ�...\n", player->name);
    }
}

int main()
{
    srand(time(0));

    Character player;
    Enemy enemy;

    explainWorld();
    createCharacter(&player);

    // ��ų�� �⺻������ �����Ƿ� ���� �߰����ִ� �κ��� �ʿ�
    // Skill fireball_skill = {"ȭ����", 20, 50, fireball}; // ��ų�� ���߿� ��� �� �ֵ��� ���÷� �߰��߽��ϴ�.
    // addSkill(&player, &fireball_skill);

    char choice;
    do
    {
        createEnemy(&enemy, player.level);
        battle(&player, &enemy);

        printf("����Ͻðڽ��ϱ�? (y/n): ");
        choice = getchar();
        getchar();
    } while (choice == 'y' || choice == 'Y');

    printf("������ �����մϴ�.\n");
    return 0;
}
