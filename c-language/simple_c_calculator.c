#include <stdio.h>

// �Լ� ����
void printMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main(voide)
{
    float num1, num2, result;
    int choice, _;

    while (1)
    {
        printMenu(); // �޴� ���

        printf("���ϴ� ������ �����Ͻÿ� (1-4) �Ǵ� 0�� �Է��Ͽ� ����:  ");
        _ = scanf("%d", &choice);

        if (choice == 0)
        {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        printf("ù ��° ���ڸ� �Է��ϼ���: ");
        _ = scanf("%f", &num1);
        printf("�� ��° ���ڸ� �Է��ϼ���: ");
        _ = scanf("%f", &num2);

       // ���õ� ���� ����
        switch (choice)
        {
            case 1:
                result = add(num1, num2);
                printf("���: %.2f\n", result);
                break;

            case 2:
                result = subtract(num1, num2);
                printf("���: %.2f\n", result);
                break;

            case 3:
                result = multiply(num1, num2);
                printf("���: %.2f\n", result);
                break;

            case 4:
                if (num2 != 0)
                {
                    result = divide(num1, num2);
                    printf("���: %.2f\n", result);
                }

                else
                {
                    printf("����: 0���� ���� �� �����ϴ�.\n");
                }
                break;

            default:
                printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
                break;
        }
    }

    return 0;
}

// �Լ� ����
void printMenu()
{
    printf("================ ���� ================\n");
    printf("1. ���ϱ�\n");
    printf("2. ����\n");
    printf("3. ���ϱ�\n");
    printf("4. ������\n");
    printf("==========================================\n");
}

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}