// continue문: 반복문에서 아래 실행문을 실행하지 않고 다음 구문으로 이동
#include <stdio.h>

int main(void)
{
    int sum = 0;

    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0)
        {
            continue; // 3의 배수이면 [i++] 코드 영역으로 이동하기
        }
        sum += i;
    }

    printf("SUM: %d\n", sum);

    return 0;
}