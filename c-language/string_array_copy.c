#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[30] = {"banana"};
    char dst[20] = {"Mango"};
    char strstr[30] = {"banana"};
    char strdst[20] = {"Mango"};

    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        dst[i] = str[i];
    }
    dst[i] = '\0';

    printf("%s\n", dst);

    strcpy(strdst, strstr);
    printf("%s\n", strdst);

    return 0;
}