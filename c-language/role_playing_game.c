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
    int agility;
    int intelligence;
    int experience;
    int gold;
    int potions; // ȸ�� ������ ����
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
    int drop_potion_chance; // ���� ��� Ȯ��
} Enemy;

void explainWorld()
{
    printf("======================================\n");
    printf("Ǫ�� ������ ���� û���� ���ٱⰡ ���������� �Ƹ��ٿ� ��, ����\n\n");
    printf("�׷���, ��ȭ�� ���� ���� ���� ���̴�...\n\n");
    printf("��� ��, ������ ��ü�Ҹ��� �������� ��Ÿ����.\n");
    printf("����� �������� �˸� �޸� �ϴ� �����...\n");
    printf("�׵�� �¼� ����� �����ڰ� ���� �������� ź���Ѵ�!\n");
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
    player->attack = 10;
    player->defense = 5;
    player->agility = 5;
    player->intelligence = 5;
    player->experience = 0;
    player->gold = 0;
    player->potions = 1; // �ʱ� ���� 1�� ����

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
    enemy->drop_potion_chance = 20; // ���� ��� Ȯ�� 20%
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
        player->agility += 2;
        player->intelligence += 2;
        player->experience = 0;
        printf("\n���� ��! ���� ����: %d\n", player->level);
        printf("HP: %d, ���ݷ�: %d, ����: %d, ��ø��: %d, ����: %d\n", player->max_hp, player->attack, player->defense, player->agility, player->intelligence);
    }
}

void usePotion(Character* player)
{
    if (player->potions > 0)
    {
        int heal_amount = player->intelligence * 10; // INT�� ����� ȸ��
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
    int dodge_chance = player->agility * 5; // AGI�� ���� ȸ�� Ȯ�� ����
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

void skillMenu(Character* player, Enemy* enemy)
{
    // ������ ��ų ���� �߰�
    printf("\n[��ų �޴�]\n");
    printf("1. ��Ÿ (�ʿ� MP: 10)\n");
    printf("2. ȭ���� (�ʿ� MP: 20)\n");
    int skill_choice;
    printf("��ų ����: ");
    scanf("%d", &skill_choice);
    getchar();

    switch (skill_choice)
    {
    case 1:
        printf("%s��(��) ��Ÿ�� ����߽��ϴ�!\n", player->name);
        attackEnemy(player, enemy);
        break;
    case 2:
        printf("%s��(��) ȭ������ ����߽��ϴ�!\n", player->name);
        attackEnemy(player, enemy); // ������ ������ �߰��� �� ����
        break;
    default:
        printf("�߸��� �����Դϴ�.\n");
    }
}

void runAway(Character* player, Enemy* enemy)
{
    int run_chance = player->agility * 5; // AGI�� ���� ���� Ȯ�� ����
    if (rand() % 100 < run_chance)
    {
        printf("%s��(��) ���������� �����ƽ��ϴ�!\n", player->name);
        return;
    }
    else
    {
        printf("%s��(��) ����ġ�� ������ �����߽��ϴ�!\n", player->name);
        int damage = enemy->attack - player->defense;
        if (damage < 0) damage = 0;
        player->hp -= damage;
        printf("%s��(��) %d�� ���ظ� �Ծ����ϴ�. HP: %d/%d\n", player->name, damage, player->hp, player->max_hp);
    }
}

void battle(Character* player, Enemy* enemy)
{
    printf("\n������ ���۵Ǿ����ϴ�! %s vs %s\n", player->name, enemy->name);

    while (player->hp > 0 && enemy->hp > 0)
    {
        int choice;
        printf("\n1) ���� 2) ��� 3) ȸ�� 4) ȸ�� 5) ��ų 6) ����\n");
        printf("����: ");
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
            usePotion(player);
            break;
        case 5:
            skillMenu(player, enemy);
            break;
        case 6:
            runAway(player, enemy);
            return;
        default:
            printf("�߸��� �����Դϴ�.\n");
            continue;
        }

        if (enemy->hp <= 0)
        {
            printf("%s��(��) �¸��߽��ϴ�!\n", player->name);
            player->experience += enemy->experience_reward;
            player->gold += enemy->gold_reward;
            printf("����ġ +%d, ��� +%d\n", enemy->experience_reward, enemy->gold_reward);
            levelUp(player);

            if (rand() % 100 < enemy->drop_potion_chance)
            {
                player->potions++;
                printf("������ ȹ���߽��ϴ�! ���� ���� ����: %d\n", player->potions);
            }
            break;
        }

        int enemy_damage = enemy->attack - player->defense;
        if (enemy_damage < 0) enemy_damage = 0;
        player->hp -= enemy_damage;
        printf("%s��(��) %s���� %d�� ���ظ� �������ϴ�! %s�� HP: %d/%d\n", enemy->name, player->name, enemy_damage, player->name, player->hp, player->max_hp);

        if (player->hp <= 0)
        {
            printf("%s��(��) ���������ϴ�...\n", player->name);
            printf("���� ����!\n");
            exit(0);
        }
    }
}

void tutorial(Character* player)
{
    printf("\n[Ʃ�丮��]\n");
    printf("�̰��� ������ ���� �����Դϴ�.\n");
    printf("����� ���� ������ ���� ������ ������ �غ� �Ǿ����ϴ�.\n");
    printf("�켱 �⺻���� ���� ����� ������ô�.\n");

    Enemy enemy;
    createEnemy(&enemy, player->level);
    battle(player, &enemy);

    printf("\n�����ϴ�! �������� �¸��߽��ϴ�.\n");
    printf("�������� ������ ������ ������ �� �ֽ��ϴ�.\n");
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
        printf("3. ���� ����ϱ�\n");
        printf("4. ���� ����\n");
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
            printf("��ø��: %d\n", player->agility);
            printf("����: %d\n", player->intelligence);
            printf("����ġ: %d\n", player->experience);
            printf("���: %d\n", player->gold);
            printf("����: %d\n", player->potions);
            break;
        case 3:
            usePotion(player);
            break;
        case 4:
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

    tutorial(&player); // Ʃ�丮�� ���Ǽҵ�

    gameLoop(&player); // �������� ���� ����

    return 0;
}
