#include <stdio.h>
#include "twice.h"

int main(int argc, char* argv[])
{
    double my_number = 12.34;

    double twice_number = twice(my_number);

    printf("twice_number = %lf\n", twice_number);
}