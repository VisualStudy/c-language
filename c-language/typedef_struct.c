#include <stdio.h>
#include <string.h>

struct dongnae {
    int num;
    float size;
    char name[100];
};

struct nae {
    struct dongnae don;
    double a;
};

typedef struct nae NAE;

int main(void)
{
    struct dongnae dong;
    dong.num = 10;
    dong.size = 300.12;
    strcpy(dong.name, "yongdang");

    printf("����: %d\n ũ��: %.2f\n �̸�: %s\n", dong.num, dong.size, dong.name);

    NAE n;
    n.don.num = 30;
    printf("%d\n", n.don.num);

    return 0;
}