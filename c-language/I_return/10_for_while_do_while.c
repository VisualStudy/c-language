#include <stdio.h>

int main(void)
{
    int i, sum = 0;

	// for �ݺ���: 1���� 10���� �� ���ϱ�
	for ( i = 1; i <= 10; i++)
	{
		sum += i;
	}
	printf("1~10 sum: %d\n", sum);

	// while �ݺ���: ���� ������ ����
	int secret = 7, guess = 0;
	while (guess != secret)
	{
		printf("���� ���߱� (1���� 10����): ");
		scanf("%d", &guess);
	}
	printf("success\n");

	// do-while �ݺ���: �ּ� �� �� ���� �� ���� �˻�
	int num;
	do
	{
		printf("1 �̻� ���� �Է�: ");
		scanf("%d", &num);
	} while (num < 1); // ���������� ����
	printf("�Է��� ����: %d\n", num);

	// for: �ݺ� Ƚ���� ��Ȯ�� ��, while: ������ ���� ���� �ݺ�
	// do while: ���� ����, �� �˻�
	return 0;
}