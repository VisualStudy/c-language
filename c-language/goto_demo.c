#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

int main(void)
{
    int chapter = 0;
    int r = 0;

    printf("start\n");

Start:
    printf("0, 1, 2 :   _\a");
    r = scanf("%d", &chapter);

    if (chapter == 1)
    {
        goto Chapter1;
    }
    else if (chapter == 2)
    {
        goto Chapter2;
    }
    else
    {
        goto End;
    }

Chapter1:
    printf("1page.\n");
Chapter2:
    printf("2page.\n");
    goto Start;

End:
    printf("END\n");

    return 0;
}