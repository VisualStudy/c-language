#include <stdio.h>

void main()
{
    char str[10]="VisualC++";
    int i;
    for (i = 0; i < 9; i += 2)
    {
        printf("%c", str[i]);
    }
}