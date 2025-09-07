#include <stdio.h>

int main(void)
{
    int U[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int A[4] = { 0,1,8,9 };
    int B[3] = { 2,4,6 };
    int C[4] = { 1,4,5,7 };
    int i, j;

    // (1) A ∩ B
    printf("(1) A ∩ B = { ");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (A[i] == B[j])
                printf("%d ", A[i]);
        }
    }
    printf("}\n");

    // (3) A - B
    printf("(3) A - B = { ");
    for (i = 0; i < 4; i++) {
        int found = 0;
        for (j = 0; j < 3; j++) {
            if (A[i] == B[j]) found = 1;
        }
        if (!found)
            printf("%d ", A[i]);
    }
    printf("}\n");

    // (5) A △ B (대칭차집합)
    printf("(5) A ⊕ B = { ");
    for (i = 0; i < 4; i++) {   // A에만 있는 원소
        int found = 0;
        for (j = 0; j < 3; j++) {
            if (A[i] == B[j]) found = 1;
        }
        if (!found) printf("%d ", A[i]);
    }
    for (i = 0; i < 3; i++) {   // B에만 있는 원소
        int found = 0;
        for (j = 0; j < 4; j++) {
            if (B[i] == A[j]) found = 1;
        }
        if (!found) printf("%d ", B[i]);
    }
    printf("}\n");

    // (7) (A ∩ B)c = U에서 빼기
    printf("(7) (A ∩ B)' = { ");
    for (i = 0; i < 10; i++) {
        int inA = 0, inB = 0;
        for (j = 0; j < 4; j++) if (U[i] == A[j]) inA = 1;
        for (j = 0; j < 3; j++) if (U[i] == B[j]) inB = 1;
        if (!(inA && inB)) printf("%d ", U[i]);
    }
    printf("}\n");

    // (9) (A ∩ B) ∪ C
    printf("(9) (A ∩ B) ∪ C = { ");
    // A ∩ B
    int inter[10], interSize = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (A[i] == B[j]) {
                inter[interSize++] = A[i];
            }
        }
    }
    // inter 출력 + C 합치기
    for (i = 0; i < interSize; i++) printf("%d ", inter[i]);
    for (i = 0; i < 4; i++) printf("%d ", C[i]);
    printf("}\n");

    return 0;
}
