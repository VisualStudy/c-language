#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = {"Hellokkj"};
    char str_2[] = {'h','e','l','l','o','\0'};
    char dst[] = {"world"};
    char x;
    int num;
    x = 'a';
    x = x + 1;
    strcpy(str,dst);

  /*  for (int i = 0; i < 10; i++)
    {
        printf("%c", str[i]);
    }*/

    printf("%s", str);

    return 0;
}