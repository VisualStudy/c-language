// �迭 �ε����� ���� ������ ����ϱ�
#include <stdio.h>

int main(void)
{
    // array �̸����� 1���� �迭 ����� ���ÿ� 1, 2, 3���� �� �ʱ�ȭ
    int array[] = { 1, 2, 3 };
    int index = 0; // �迭�� �ε����� 0���� �����ϱ⿡ 0���� index ���� �ʱ�ȭ

    printf("%d\t", array[index++]); // array[0] ��� ��, index == 1�� ����
    printf("%d\t", array[index++]); // array[1] ��� ��, index == 2�� ����
    printf("%d\n", array[index++]); // array[2] ��� ��, index == 3�� ����

    printf("%d\t", array[--index]); // index == 2�� ���� ��, array[2] ���
    printf("%d\t", array[--index]); // index == 1�� ���� ��, array[1] ���
    printf("%d\n", array[--index]); // index == 0�� ���� ��, array[0] ���

    return 0;
}