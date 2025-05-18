#include <stdio.h>
#define RA 100

int main(void)
{
    FILE* f;
    f = fopen("file_pointer_test.txt", "w");
    if (f == NULL)
    {
        printf("쥐엔장~ 파일이 안 열려~~");
        return 1;
    }

    fprintf(f, "파일에 적.는.다! RA");
    fclose(f);

    return 0;
}