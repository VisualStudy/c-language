#include <stdio.h>

main() {
    int i = 1, n = 0;
    while (i <= 50) {
        if (i % 7 == 0)
            n += i;
        i++;
    }
    printf("%d", n);
}