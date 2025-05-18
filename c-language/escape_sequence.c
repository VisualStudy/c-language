#include <stdio.h>

int main(void)
{
    printf("Escpae Seqeunce Exaples: \n\n");

    printf("1. New Line (\\n): \n");
    printf("Hello\nWorld\n\n");

    printf("2. Tab (\\t): \n");
    printf("Name\tAge\tCity\n");
    printf("John\t25\tSeoul\n\n");

    printf("3. Backslash (\\\\): \n");
    printf("C:\\program Files\\MyApp\n\n");

    printf("4. Double Quote (\\\"): \n");
    printf("\"Hello, World!\"\n\n");

    printf("5. Single Quote (\\\'): \n");
    printf("\'A\' is the first letter. \n\n");

    printf("6. Carriage Return (\\r): \n");
    printf("12345\rABCDE\n\n"); // �Ϻ� �ý��ۿ����� �� �� ������ ���

    printf("7. Backspace (\\b): \n");
    printf("Oops! \b \n\n"); // ������ ���� ����.

    return 0;
}