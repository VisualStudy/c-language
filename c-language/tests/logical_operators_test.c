#include <stdio.h>

int main(void) {
    int i = 5, j = 4, k = 1, L, m;
    L = i > 5 || j != 0; // L = 1
    m = j <= 4 && k < 1; // m = 0
    printf("%d, %d\n", L, m); // 1, 0
}