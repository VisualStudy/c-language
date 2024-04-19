#include <stdio.h>
#include <float.h>

int main(void)
{
    float f = 3.14f;
    double d = 3.14;
    long double ld = 3.14l;

    printf("%.6f %.6lf %.6Lf\n", f, d, ld);
    printf("%e %e %Le\n", f, d, ld);
    printf("%llu %llu %llu\n", sizeof(float), sizeof(double), sizeof(long double));

    
}