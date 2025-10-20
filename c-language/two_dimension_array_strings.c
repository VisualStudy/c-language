#include <stdio.h>

int main(void)
{
    char str[5][30] = {
        "Hello!",
        "Where are you from?",
        "I am from RaBaRaTa!",
        "Oh..! You too?",
        "Nice to meet you bro."
    };

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}