#include <stdio.h>

int main(void)
{
    char x[5] = {"yaho"};
    char str[3][20] = 
    {
        "lets",
        "go",
        "together"
    };

    printf("%s\n", x);
    printf("%s\n", &*(x + 0));
    printf("%c\n", x[0]);
    printf("%c\n", *(x + 0));
    
    printf("%c\n", x[1]);
    printf("%c\n", *(x + 1));
   

    printf("%s\n", str[0]);
    printf("%s\n", &*(str[0] + 0));
    printf("%s\n", str[1]);
    printf("%s\n", &*(str[1] + 0));
    
    printf("%c\n", str[0][1]);
    printf("%c\n", *(str[0] + 1));

    return 0;
}