#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = {"Hello"};

    char src2[2][6] = {
    "Hello",
    "World"
    };

    char src3[2][7] = {"minjae", "jae"};

    for (int i = 0; i < 5; i++)
    {
        if (src[i] != '\0')
        {
            printf("%c", src[i]);
        }
    }
    int size = strlen("hello");
    printf("\n\n%d", size);

    return 0;
}