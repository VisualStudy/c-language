#include <stdio.h>

int main(void)
{
    int kor = 100;
    int eng = 90;

    int tot = kor + eng; // ÃÑÁ¡ ±¸ÇÏ±â
    double avg = tot / 2.0; // Æò±Õ ±¸ÇÏ±â
    
    printf("ÃÑÁ¡: %d\n", tot);
    printf("Æò±Õ: %.2f\n", avg);

    return 0;
}