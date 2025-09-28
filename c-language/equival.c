#include <stdio.h>

int main(void)
{
    int A[4] = {1,2,3,4};
    int R[6][2] = { {1,1}, {1,2}, {2,1}, {2,2}, {3,3}, {4,4} };

    // 반사 관계 검사
    int reflexive = 1;

    for (int i = 0; i < 4; i++)
    {
        int a = A[i];
        int found = 0;

        printf("반사 관계 확인: (%d,%d)\n", a, a);

        for (int j = 0; j < 6; j++)
        {
            if (R[j][0] == a && R[j][1] == a)
            {
                found = 1;
            }
        }

        if (found == 0)
        {
            reflexive = 0;
        }
    }

    if (reflexive)
    {
        printf("반사 관계 성립\n\n");
    }

    else
    {
        printf("반사 관계 불성립\n\n");
    }

    // 대칭 관계 검사
    int symmetric = 1;

    for (int i = 0; i < 6; i++)
    {
        int a = R[i][0];
        int b = R[i][1];
        int found = 0;

        printf("대칭 관계 확인: (%d,%d)가 있으면 (%d,%d)도 있어야 함\n", a, b, b, a);

        for (int j = 0; j < 6; j++)
        {
            if (R[j][0] == b && R[j][1] == a)
            {
                found = 1;
            }
        }

        if (found == 0)
        {
            symmetric = 0;
        }
    }

    if (symmetric)
    {
        printf("대칭 관계 성립\n\n");
    }

    else
    {
        printf("대칭 관계 불성립\n\n");
    }

    // 추이 관계 검사
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

                printf("추이 관계 확인: (%d,%d)와 (%d,%d)가 있으면 (%d,%d)도 있어야 함\n", a, b, b, c, a, c);

                for (int k = 0; k < 6; k++)
                {
                    if (R[k][0] == a && R[k][1] == c)
                    {
                        found = 1;
                    }
                }

                if (found == 0)
                {
                    transitive = 0;
                }
            }
        }
    }

    if (transitive)
    {
        printf("추이 관계 성립\n\n");
    }

    else
    {
        printf("추이 관계 불성립\n\n");
    }

    // 동치 관계 판정 및 동치류 출력
    if (reflexive && symmetric && transitive)
    {
        printf("따라서 R은 동치 관계임\n");
        printf("동치류:\n");

        int used[5] = { 0 }; // 원소 사용 여부 체크

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
        printf("따라서 R은 동치 관계가 아님\n");
    }

    return 0;
}
