#include <stdio.h>

void show_message(char* message)
{
    puts(message);
}

int main(void)
{
    show_message("parameter");
    show_message("arguement");

    return 0;
}