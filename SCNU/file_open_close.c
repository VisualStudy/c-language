#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    char naming[100];
    int age;
    char getname[100];
    int getage;

    FILE *fp;
    fp = fopen("scnu_file.txt", "w");
    if(fp == NULL)
    {
        printf("������ ����. ��� ����!\n");

        return 1;
    }
    fprintf(fp, "�̰��� ���ڿ� �ۼ��̤�r\n");
    fprintf(fp, "���� �� ����϶���!");

    while(1)
    {
        printf("���ݺ��� �Է� ���� ��. Ż�� ���ϸ� 0 �Է�\n");
        printf("�������� ������ �̸� �Է�: \n");
        strcpy(name, "��ٶ�Ÿ");
        printf("Ȧ��! strcpy�� ħ��! �ʰ� ���� �̸� �Է�: ");
        scanf("%s", naming);
        printf("��, �̸� �Է� �ھ�~ �޾Ҵ�. ���� �Է�: ");
        scanf("%d", &age);

        fprintf(fp, "\n �� ���� ���� ���� %s, %d\n", naming, age);

        if(age == 0)
        {
            break;
        }
    }

    fputc('a', fp);
    fputc('b', fp);
    fputc('c', fp);

    fclose(fp);

    fp = fopen("scnu_file.txt", "r");

    while(!feof(fp))
    {
        fscanf(fp, "%s, %d", getname, &age);
        printf("�ξƾƾƾ�! ���� ����ƾ�: %s\n", getname);
        printf("�����, �׾��� ����: %d\n", age);
    }

    fclose(fp);

    return 0;
}