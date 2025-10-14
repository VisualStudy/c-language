#include <stdio.h>

int main(void)
{
    char menu[5][10] = {
        "apple",
        "banana",
        "mango",
        "blueberry",
        "melon"
    };

    for (int i = 0; i < 2 * 10; i++)
    {
        int row = i / 10;
        int col = i % 10;

        if (menu[row][col] == '\0')
        {
            continue;
        }

        printf("%c", menu[row][col]);
    }

    printf("\n");
    
    return 0;
}
