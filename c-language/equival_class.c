#include <stdio.h>

int main(void)
{
    // ���� A�� ���� R ����
    int A[4] = {1,2,3,4};
    int R[6][2] = {{1,1}, {1,2}, {2,1}, {2,2}, {3,3}, {4,4}};

    // �ݻ� ���� �˻�
    int reflexive = 1;

    for (int i = 0; i < 4; i++)
    {
        int a = A[i];
        int found = 0;

        for (int j = 0; j < 6; j++)
        {
            if (R[j][0] == a && R[j][1] == a)
            {
                found = 1;
            }
        }

        if (found)
        {
            printf("�ݻ�: (%d,%d) ���� -> ��\n", a, a);
        }

        else
        {
            printf("�ݻ�: (%d,%d) ���� -> ����\n", a, a);
            reflexive = 0;
        }
    }

    if (reflexive)
    {
        printf("�ݻ� ���� ���� ����: ����\n\n");
    }

    else
    {
        printf("�ݻ� ���� ���� ����: �Ҽ���\n\n");
    }

    // ��Ī ���� �˻�
    int symmetric = 1;

    for (int i = 0; i < 6; i++)
    {
        int a = R[i][0];
        int b = R[i][1];
        int found = 0;

        for (int j = 0; j < 6; j++)
        {
            if (R[j][0] == b && R[j][1] == a)
            {
                found = 1;
            }
        }

        if (found)
        {
            printf("��Ī: (%d,%d)�� ���� (%d,%d) ���� -> ��\n", a, b, b, a);
        }

        else
        {
            printf("��Ī: (%d,%d)�� ���� (%d,%d) ���� -> ����\n", a, b, b, a);
            symmetric = 0;
        }
    }

    if (symmetric)
    {
        printf("��Ī ���� ���� ����: ����\n\n");
    }

    else
    {
        printf("��Ī ���� ���� ����: �Ҽ���\n\n");
    }

    // ���� ���� �˻�
    int transitive = 1;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (R[i][1] == R[j][0])
            {
                int a = R[i][0];
                int b = R[i][1];
                int c = R[j][1];

                int found = 0;

                for (int k = 0; k < 6; k++)
                {
                    if (R[k][0] == a && R[k][1] == c)
                    {
                        found = 1;
                    }
                }

                if (found)
                {
                    printf("����: (%d,%d)�� (%d,%d) -> (%d,%d) ���� -> ��\n", a, b, b, c, a, c);
                }

                else
                {
                    printf("����: (%d,%d)�� (%d,%d) -> (%d,%d) ���� -> ����\n", a, b, b, c, a, c);
                    transitive = 0;
                }
            }
        }
    }

    if (transitive)
    {
        printf("���� ���� ���� ����: ����\n\n");
    }

    else
    {
        printf("���� ���� ���� ����: �Ҽ���\n\n");
    }

    // ��ġ ���� ���� �� ��ġ�� ���
    if (reflexive && symmetric && transitive)
    {
        printf("���� R�� ��ġ �����Դϴ�.\n");
        printf("��ġ�� ���:\n");

        // ���� �� 1..4�� �ε����� ���
        int used[5] = {0};

        for (int i = 0; i < 4; i++)
        {
            int a = A[i];

            if (!used[a])
            {
                printf("[%d] = { ", a);

                for (int j = 0; j < 4; j++)
                {
                    int b = A[j];
                    int ab = 0;
                    int ba = 0;

                    for (int k = 0; k < 6; k++)
                    {
                        if (R[k][0] == a && R[k][1] == b)
                        {
                            ab = 1;
                        }

                        if (R[k][0] == b && R[k][1] == a)
                        {
                            ba = 1;
                        }
                    }

                    if (ab && ba)
                    {
                        printf("%d ", b);
                        used[b] = 1;
                    }
                }

                printf("}\n");
            }
        }
    }

    else
    {
        printf("���� R�� ��ġ ���谡 �ƴմϴ�.\n");
    }

    return 0;
}
