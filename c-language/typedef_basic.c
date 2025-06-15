#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

int main(void)
{
    Point p = {1, 2}
    printf("%d %d\n", p.x, p.y);

    return 0;
}