# c-language

# C 언어 소개

## 1. C 언어란?

C 언어는 1970년대 초 데니스 리치(Dennis Ritchie)가 개발한 프로그래밍 언어입니다.  
운영체제, 임베디드 시스템, 하드웨어 제어, 시스템 프로그램 개발 등에 널리 사용되는 대표적인 절차지향 프로그래밍 언어입니다.

C 언어는 비교적 오래된 언어이지만, 컴퓨터 구조와 메모리 동작 원리를 이해하는 데 매우 중요한 언어입니다.  
그래서 많은 프로그래밍 입문 수업에서 C 언어를 기본 언어로 다룹니다.

---

## 2. C 언어의 특징

### 2.1 절차지향 언어

C 언어는 프로그램을 순서대로 실행되는 절차 중심으로 작성합니다.  
즉, 문제를 여러 단계로 나누고 그 순서에 따라 명령을 실행하는 방식입니다.

### 2.2 빠른 실행 속도

C 언어는 컴퓨터 하드웨어와 가까운 수준에서 동작하기 때문에 실행 속도가 빠릅니다.  
이러한 특징 때문에 운영체제나 게임 엔진, 임베디드 프로그램처럼 성능이 중요한 분야에서 많이 사용됩니다.

### 2.3 메모리 제어 가능

C 언어는 포인터를 사용하여 메모리에 직접 접근할 수 있습니다.  
이를 통해 세밀한 제어가 가능하지만, 잘못 사용하면 오류가 발생하기 쉽기 때문에 주의가 필요합니다.

### 2.4 이식성이 좋음

C 언어로 작성된 프로그램은 다양한 운영체제와 컴퓨터 환경에서 비교적 쉽게 사용할 수 있습니다.  
이러한 장점 때문에 여러 플랫폼에서 활용됩니다.

---

## 3. C 언어의 기본 구조

C 언어 프로그램은 보통 `main()` 함수에서 시작합니다.

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, C Language!\n");
    return 0;
}
```

### 코드 설명

- `#include <stdio.h>`  
  표준 입출력 기능을 사용하기 위한 헤더 파일을 포함합니다.

- `int main(void)`  
  프로그램이 시작되는 함수입니다.

- `printf()`  
  화면에 문장을 출력하는 함수입니다.

- `return 0;`  
  프로그램이 정상적으로 종료되었음을 의미합니다.

---

## 4. C 언어에서 배우는 주요 개념

C 언어를 공부하면서 다음과 같은 기본 개념을 익힐 수 있습니다.

- 변수와 자료형
- 연산자
- 조건문
- 반복문
- 배열
- 함수
- 포인터
- 구조체
- 파일 입출력
- 메모리 관리

이러한 개념들은 다른 프로그래밍 언어를 배울 때도 기초가 됩니다.

---

## 5. C 언어의 활용 분야

C 언어는 다음과 같은 분야에서 많이 사용됩니다.

| 분야 | 설명 |
|---|---|
| 운영체제 | Windows, Linux 같은 운영체제의 핵심 부분 개발 |
| 임베디드 시스템 | 자동차, 가전제품, IoT 기기 제어 |
| 시스템 프로그램 | 컴파일러, 드라이버, 네트워크 프로그램 개발 |
| 게임 개발 | 성능이 중요한 게임 엔진 및 그래픽 처리 |
| 알고리즘 학습 | 자료구조와 알고리즘 학습에 활용 |

---

## 6. C 언어를 배우는 이유

C 언어를 배우면 컴퓨터가 프로그램을 어떻게 실행하는지 깊이 이해할 수 있습니다.  
특히 메모리, 주소, 포인터, 함수 호출 구조 등을 배우면서 프로그래밍의 기초 체력을 기를 수 있습니다.

또한 C 언어는 C++, C#, Java, JavaScript 등 여러 언어에 영향을 준 언어이기 때문에, C 언어를 잘 이해하면 다른 언어를 배우는 데도 도움이 됩니다.

---

## 7. 정리

C 언어는 오래되었지만 여전히 중요한 프로그래밍 언어입니다.  
문법은 간결하지만, 컴퓨터의 내부 동작을 이해하는 데 큰 도움이 됩니다.

따라서 C 언어는 단순히 하나의 프로그래밍 언어를 배우는 것을 넘어,  
프로그래밍의 기본 원리와 컴퓨터 시스템의 구조를 이해하는 데 중요한 역할을 합니다.


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
## 쓰레기값
```C
#include <stdio.h>
int main(void) 
{ 
    int number; 
    number = 1234; 
    printf("%d\n", number); 

    return 0;
}
```
## Constant demo
```
#include <stdio.h>

int main(void)
{
    const int MAX = 100;
    const double PI = 3.14;
    const char GRADE = 'A';

    printf("%d, %.6lf, %c\n", MAX, PI, GRADE);

    return 0;
}
```

# 함수(Function)를 이용한 뺄셈 프로그램

## 📌 프로그램 설명

이 프로그램은 사용자 정의 함수 `myfun()`을 사용하여 두 정수의 차를 계산하고 출력하는 간단한 C 언어 예제입니다.

---

## 📄 전체 코드

```c
#include <stdio.h>

int myfun(int a, int b) {
    int result = 0;
    result = a - b;
    return result;
}

int main(void)
{
    int a;

    a = myfun(5, 2);

    printf("%d", a);

    return 0;
}


























