#include <stdio.h>

int main(void)
{
    int arr[3] = {10, 20, 30};
    int *p = arr; // 배열 이름은 배열의 시작 주소 -> 포인터로 사용 가능

    printf("arr[0] = %d\n", arr[0]); // [ ]: 배열의 첫 번째 "값"
    printf("*(arr) = %d\n", *(arr)); // *: 배열 이름은 주소 -> 그 주소의 값
    printf("*p = %d\n", *p); // *: p는 arr와 같음 -> arr[0]
    
    printf("&arr[0] = %p\n", (void *)&arr[0]); // &: 첫 번째 요소의 주소
    printf("arr = %p\n", (void *)arr); // arr 자체가 주소 (== &arr[0]) 첫 번째 인덱스!
    printf("p = %p\n", (void *)p); // p는 arr와 동일한 주소 가지는 중

    printf("arr[1] = %d\n", arr[1]); // [ ]: 두 번째 요소의 값
    printf("*(arr + 1) = %d\n", *(arr + 1)); // * + : 두 번째 요소의 값
    printf("p[2] = %d\n", p[2]); // [ ]: 포인터도 배열처럼 접근 가능

    return 0;
}