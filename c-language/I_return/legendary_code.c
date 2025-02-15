#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void delay(int milliseconds)
{
    Sleep(milliseconds);
}

int main(void)
{
    char* actions[] = 
    {
        "니징어가 울부짖었다!",
        "니징어 앞을 가로막는 전설의 레모레모니가 등장했다!",
        "니징어가 강력한 물기를 시전했다!!!",
        "꾸오아아왕! 우렁찬 파동 소리가 울려퍼졌다! 레모레모니가 강타당했다!",
        "이럴 수가! 그럼에도 레모레모니는 공격을 버텨냈다!",
        "너무 막강한 공격에 레모레모니가 휘청거리고 있다!",
        "니징어의 강력한 뒷차기!",
        "파라라랑!",
        "레모레모니가 나뭇가지 마냥 박살났다!",
        "니징어는 압도적 존재였다..."
    };

    printf("==== 니징전 ====\n");
    delay(1000);

    for (int i = 0; i < 9; i++)
    {
        printf("%s\n", actions[i]);
        delay(1500); // 긴장감 연출
    }

    printf("\n전설적인 순간 도달!\n");
    
    return 0;
}