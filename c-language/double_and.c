#include <stdio.h>

main()
{
    printf("%d\n", (-2 && 3));
    printf("%d\n", (3 && 1));
    printf("%d\n", (-2 && 3 && 1));
    printf("%d\n", (-2 && 0));
}
