#include <stdio.h>

struct Position
{
    int x;
    int y;
};

typedef struct Position Pos;

int main(void)
{
    Pos p = {5, 6};
    printf("%d %d\n", p.x, p.y);

    return 0;
}