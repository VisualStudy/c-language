#include <stdio.h>

int main(void)
{
    char message[] = "C Language";

    printf("%s\n", message);

    printf("string_length: %llu\n", sizeof(message));

    printf("%c\n", message[0]);

    message[0] = 'Z';

    printf("%s\n", message);

    return 0;
}