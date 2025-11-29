#include <stdio.h>

// point 구조체 선언
struct point
{
    int x; // x좌표
    int y; // y좌표
};

// struct point를 Point로 별칭(alias) 지정하는 형 정의
typedef struct point Point;

int main(void)
{
    Point p1; // Point 구조체 변수 p1 선언
    p1.x = 10; // p1의 x 좌표에 10 할당
    p1.y = 20; // p1의 y 좌표에 20 할당

    // p1의 x, y 좌표 출력
    printf("(%d, %d)\n", p1.x, p1.y);

    return 0;
}