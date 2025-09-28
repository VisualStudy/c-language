#include <stdio.h>

int main(void)
{
    // 집합 A와 관계 R 정의
    int A[4] = {1,2,3,4};
    int R[6][2] = {{1,1}, {1,2}, {2,1}, {2,2}, {3,3}, {4,4}};

    // 반사 관계 검사
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
            printf("반사: (%d,%d) 존재 -> 참\n", a, a);
        }

        else
        {
            printf("반사: (%d,%d) 없음 -> 거짓\n", a, a);
            reflexive = 0;
        }
    }

    if (reflexive)
    {
        printf("반사 관계 최종 판정: 성립\n\n");
    }

    else
    {
        printf("반사 관계 최종 판정: 불성립\n\n");
    }

    // 대칭 관계 검사
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
            printf("대칭: (%d,%d)에 대해 (%d,%d) 존재 -> 참\n", a, b, b, a);
        }

        else
        {
            printf("대칭: (%d,%d)에 대해 (%d,%d) 없음 -> 거짓\n", a, b, b, a);
            symmetric = 0;
        }
    }

    if (symmetric)
    {
        printf("대칭 관계 최종 판정: 성립\n\n");
    }

    else
    {
        printf("대칭 관계 최종 판정: 불성립\n\n");
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

                for (int k = 0; k < 6; k++)
                {
                    if (R[k][0] == a && R[k][1] == c)
                    {
                        found = 1;
                    }
                }

                if (found)
                {
                    printf("추이: (%d,%d)와 (%d,%d) -> (%d,%d) 존재 -> 참\n", a, b, b, c, a, c);
                }

                else
                {
                    printf("추이: (%d,%d)와 (%d,%d) -> (%d,%d) 없음 -> 거짓\n", a, b, b, c, a, c);
                    transitive = 0;
                }
            }
        }
    }

    if (transitive)
    {
        printf("추이 관계 최종 판정: 성립\n\n");
    }

    else
    {
        printf("추이 관계 최종 판정: 불성립\n\n");
    }

    // 동치 관계 판정 및 동치류 출력
    if (reflexive && symmetric && transitive)
    {
        printf("따라서 R은 동치 관계입니다.\n");
        printf("동치류 출력:\n");

        // 원소 값 1..4를 인덱스로 사용
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
        printf("따라서 R은 동치 관계가 아닙니다.\n");
    }

    return 0;
}
