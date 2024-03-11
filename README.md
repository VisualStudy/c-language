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
