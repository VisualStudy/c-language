// 부호 있는 정수 데이터 타입 사용하기 
#include <stdio.h>
#include <limits.h> // 정수 데이터 타입의 최댓값과 최솟값에 대한 상수 정의

int main(void)
{
    //[1] 정수 데이터 타입 변수 선언
    short s = 32767;
    int i = 2147483647;
    long l = 2147483647;
    long long ll = 9223372036854775807;

    //[2] 자리 표시자: short(%d), int(%d), long(%ld), long long(%lld) 
    //32767 2147483647 2147483647 9223372036854775807
    printf("%d %d %ld %lld\n", s, i, l, ll);

    //[3] 정수 데이터 타입 크기: sizeof로 데이터 타입 크기를 알 수 있고 %llu로 출력
    // 리눅스 환경의 GCC 컴파일러에서는 서식 지정자로 %llu 대신에 %lu로 출력해야 함
    printf("%llu %llu %llu %llu\n",
        sizeof(short), // 2
        sizeof(int), // 4
        sizeof(long), // 4
        sizeof(long long) // 8
    );

    //[4] 정수 데이터 타입의 범위: 큰 숫자이므로 지수 표기법으로 출력
    //short: -32768 ~32767
    printf("short: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    //int : -2147483648 ~2147483647
    printf("int: %d ~ %d\n", INT_MIN, INT_MAX);
    //long : -2147483648 ~2147483647
    printf("long: %ld ~ %ld\n", LONG_MIN, LONG_MAX);
    //long long : -9223372036854775808 ~9223372036854775807
    printf("long long: %lld ~ %lld\n", LLONG_MIN, LLONG_MAX);

    return 0;
}