#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

int main(void)
{
    int a = true;
    int b = false;

    printf("%d, %d\n", a, b);    

    printf("%d\n", 3 < 5); // 1(True)

    printf("%d\n", 3 > 5); // 0 (False)

    printf("%d\n", 3 <= 5); // 1 (True)
    
    printf("%d\n", 3 >= 5); // 0 (False)
    
    printf("%d\n", 3 == 5); // 0 (False)
    
    printf("%d\n", 3 != 5); // 1 (True)
    
    return 0;
}