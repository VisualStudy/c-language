#include <stdio.h>

int main(void)
{
    FILE *f;
    f = fopen("file_pointer_test.txt", "w");
    if(f == NULL)
    {
        printf("�㿣��~ ������ �� ����~~");
        return 1;
    }

    fprintf(f, "���Ͽ� ��.��.��!");
    fclose(f);

    return 0;
}