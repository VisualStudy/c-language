#include <stdio.h>

main() {
    int num = 35, evencnt = 0, oddcnt = 0;
    for (int i = 1; i <= num; i++) {
        if (i % 2 == 0)
            evencnt++;
        else
            oddcnt++;
    }
    printf("%d %d", evencnt, oddcnt); // 17 18
}