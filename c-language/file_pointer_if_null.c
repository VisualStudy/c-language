#include <stdio.h>
#define RA 100

int main(void)
{
    FILE* f;
    f = fopen("file_pointer_test.txt", "w");
    if (f == NULL)
    {
        printf("�㿣��~ ������ �� ����~~");
        return 1;
    }

    fprintf(f, "���Ͽ� ��.��.��! RA");
    fclose(f);

    return 0;
}