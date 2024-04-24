#include <stdio.h>

int main(void)
{
    char c = 200; 
    // 1100 1000 -> 1의 보수 : 0011 0111 ->  
    // 2의 보수 : 0011 1000 -> 10진수 -> 56 -> 부호 -56
    
    printf("%d", c);

    return 0;
}