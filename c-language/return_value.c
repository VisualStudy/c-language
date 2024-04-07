#include <stdio.h>

char* get_string()
{
    return "Return Value";
}

int main(void)
{
    char* return_value = get_string();
    printf("%s\n", return_value);

    return 0;
}