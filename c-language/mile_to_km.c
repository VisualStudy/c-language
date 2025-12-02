#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    double km, mile;

    if (argc != 2)
    {
       printf("뭔가 잘못된 것 같습니다.");
        
       return 0;
    }

    mile = atof(argv[1]);
    km = mile * 1.609;

    printf("%f mile = %f km\n", mile , km);

    return 0;
}