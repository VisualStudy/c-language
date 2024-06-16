#include <stdio.h>
#pragma warning(disable:4996)

// 시그마 계산 함수
int sigma(int 시작값, int 끝값) 
{
    int 합 = 0;
    for (int i = 시작값; i <= 끝값; i++) 
    {
        합 += i;  // 현재 값을 더함
    }
    return 합;  // 최종 합을 반환
}

// 메인 함수
int main(void) 
{
    int _, 시작값, 끝값;

    // 사용자로부터 시작 값과 끝 값을 입력받음
    printf("시작 값을 입력하세요: ");
    _ = scanf("%d", &시작값);
    printf("끝 값을 입력하세요: ");
    _ = scanf("%d", &끝값);

    // 유효성 검사
    if (시작값 > 끝값) 
    {
        printf("시작 값은 끝 값보다 작거나 같아야 합니다.\n");
        return 1;
    }

    // 시그마 계산 함수 호출
    int 결과 = sigma(시작값, 끝값);

    // 결과 출력
    printf("Σ(i=%d 부터 %d) i = %d\n", 시작값, 끝값, 결과);

    return 0;
}
