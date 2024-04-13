# c-language
## 변수 만들고 사용하기

```c
// variable
#include <stdio.h>

int main(void)
{
    int number;
    number = 7;
    printf("%d\n", number);
    return 0;
}
```

 ```output
7
```

## 문자 변수 선언하기

```C
#include <stdio.h>

int main(void)
{
    char grade = 'A';
    char num = -128;
    unsigned char age = 255;

    printf("%c\n", grade);
    printf("%d\n", num);
    printf("%d\n", age);

    return 0;
}
```

```output
A
-128
255
```

## 이스케이프 시퀀스
```C
#include <stdio.h>

int main(void)
{
    char ch1 = 'A';
    char ch2 = 'B';
    char newLine = '\n';
    printf("%c%c%c\n", ch1, newLine, ch2);

    return 0;
}
```

```output
A
B
```

## 백 슬래시 012
```C
#include <stdio.h>

int main(void)
{
    char* message = "HELLO.\012My name is VisualStudy";
    printf("%s\n", message);

    message = "HOWDY.\012123456789\0";
    printf("%s\n", message);

    return 0;
}
```
```output
HELLO.
My name is VisualStudy
HOWDY.
123456789
```

## 스트링 위드 캐릭터 어레이
```C
#include <stdio.h>

int main(void)
{
    char s[5] = "Code";

    printf("%s\n", s);

    return 0;
}
```
```output
Code
```

## 스트링

```C
#include <stdio.h>

int main(void)
{
    char message[] = "C Language";

    printf("%s\n", message);

    printf("string_length: %llu\n", sizeof(message));

    printf("%c\n", message[0]);

    message[0] = 'Z';

    printf("%s\n", message);

    return 0;
}
```
```output
C Language
string_length: 11
C
Z Language
```
## 주소 연산자
```C
#include <stdio.h>

int main(void)
{
    int number = 1234;

    printf("%d, %p\n", number, &number);

    return 0;
}
```






























