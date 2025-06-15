#include <stdio.h>

// temp 변수를 이용해 변수 두 개의 값을 서로 바꿔보자!
int main(void)
{
    int a, b, temp;
    a = 1000;
    b = 10;
    // a = 1000, b = 10이다. 그러나, temp에 힘을 사용하여 a를 파산시켜 보자!
    temp = b;
    b = a;
    a = temp;

    printf("과연 a는 파산했을까: %d\n", a);
    if (a == 10)
    {
        printf("오호! a 파산시키기 성공!\n");
    }
    else
    {
        printf("뭔가 잘못된 것 같습니다.\n");
    }
    if (b == 1000)
    {
        printf("이제 b는 갑부다!\n");
    }
    else
    {
        printf("뭔가 잘못된 것 같습니다. Somethings wrong!\n");
    }

    return 0;
}