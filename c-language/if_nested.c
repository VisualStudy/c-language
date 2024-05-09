// 중첩된 if 문 예시
#include <stdio.h>

int main(void)
{
    char name = 'C';
    int version = 22;

    if (name == 'C') // 첫 번째 조건 검사
    {
        if (version == 22) // 두 번째 조건 검사
        {
            printf("%c %d\n", name, version); // 두 조건 모두 만족 시 실행
        }
    }

    return 0;
}