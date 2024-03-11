#include <stdio.h>

int main(void)
{
    char* message = "HELLO.\012My name is VisualStudy";
    printf("%s\n", message);

    message = "HOWDY.\012123456789\0";
    printf("%s\n", message);

    return 0;
}