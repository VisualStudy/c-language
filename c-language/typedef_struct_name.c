#include <stdio.h>

typedef struct Coordinate
{
    int x;
    int y;
} COORDINATE;
int main(void)
{
    COORDINATE c = {3, 4};
    printf("%d %d\n", c.x, c.y);

    return 0;
}