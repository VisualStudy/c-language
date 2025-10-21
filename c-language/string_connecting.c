#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80] = {"Hello world"};
    char dst[50] = {" manners, maketh, man"};
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    int j;
    for (j = 0; dst[j] != '\0'; j++)
    {
        str[i + j] = dst[j];
    }
    str[i + j] = '\0';

    printf("%s\n", str);

    return 0;
}