#include <stdio.h>

main() {
    int c = 1;
    switch (3) {
        case 1: c += 3;
        case 2: c++;
        case 3: c = 0; // 0
        case 4: c += 3; // 0 + 3
        case 5: c -= 10;  // 3 - 10 = -7
        default: c--; // -7
    } // - 8
    printf("%d", c); // -8
}