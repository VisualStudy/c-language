#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30 , 40 ,50};
    int *p = arr; // 배열 이름은 첫 번째 요소(원소: element)의 주소

    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("*(p + 2) = %d\n", *(p + 2));
    printf("&arr[2] = %p\n", (void*)&arr[2]);
    printf("arr + 2 = %p\n", (void*)(arr + 2));
    // (void*)로 타입 모르는 포인터로 변경 -> %p와 적합. 경고 방지.
    printf("*&arr[2] = %d\n", *&arr[2]);
    printf("*&*&arr[2] = %d\n", *&*&arr[2]);
    printf("*(&arr[2]) = %d\n", *(&arr[2]));

    // 포인터 간 비교
    int x = 42;
    printf("x = %d\n", x);
    printf("*&x = %d\n", *&x);
    printf("*&*&x = %d\n", *&*&x);

    //    출력 결과:
    //    arr[2] = 30
    //    *(arr + 2) = 30
    //    * (p + 2) = 30
    //    & arr[2] = 00000014A690FBF0
    //    arr + 2 = 00000014A690FBF0
    //    * &arr[2] = 30
    //    * &*&arr[2] = 30
    //    * (&arr[2]) = 30
    //    x = 42
    //    * &x = 42
    //    * &*&x = 42

    return 0;
}