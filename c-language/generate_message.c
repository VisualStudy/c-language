#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���� �޽����� �����ϱ� ���� �Լ�
void generateMessage(char* buffer, size_t size) {
    const char* greetings[] = { "�ȳ��ϼ���", "�ݰ����ϴ�", "�ȳ��Ͻʴϱ�", "���� �Ϸ� �Ǽ���" };
    const char* names[] = { "ȫ�浿", "��ö��", "�̿���", "�ڹμ�" };
    const char* actions[] = { "���� �Ϸ絵", "�̹� �ָ���", "�̹� �ֵ�", "�����ε�" };
    const char* wishes[] = { "�ູ�ϼ���", "�ǰ��ϼ���", "��ſ� �ð� �Ǽ���", "��������" };

    // �迭�� ũ�� ���
    size_t greetingsSize = sizeof(greetings) / sizeof(greetings[0]);
    size_t namesSize = sizeof(names) / sizeof(names[0]);
    size_t actionsSize = sizeof(actions) / sizeof(actions[0]);
    size_t wishesSize = sizeof(wishes) / sizeof(wishes[0]);

    // ���� �ε��� ����
    int greetIndex = rand() % greetingsSize;
    int nameIndex = rand() % namesSize;
    int actionIndex = rand() % actionsSize;
    int wishIndex = rand() % wishesSize;

    // �޽��� ����
    snprintf(buffer, size, "%s, %s! %s %s.", greetings[greetIndex], names[nameIndex], actions[actionIndex], wishes[wishIndex]);
}

int main() {
    // ���� �õ� ����
    srand(time(NULL));

    // �޽��� ����
    char message[100];

    // �޽��� ����
    generateMessage(message, sizeof(message));

    // ������ �޽��� ���
    printf("%s\n", message);

    return 0;
}
