#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h> // 문자열 관련 함수를 사용하려면
#include <memory.h> // 동적 할당하려면
#include <limits.h> // 자료형의 최대최소값을 지정하려면
#include <math.h>   // 수학공식을 사용하려면
#include <conio.h>  // getche() 함수 사용하려면
#pragma warning (disable:4996)  // VC++에서 C 문법을 오류 없이 사용하려면

#define PI 3.141592      // 자주 사용하는 상수를 기호 상수로 명시
#define N 101            // 이후부터는 N은 무조건 101로 사용됨

void chapter1()
{
    int i, menu, f, l, e, sum = 0, data[10], largest, smallest;
    while (1) // 무한 루프
    {
        printf("\n\n\n 메뉴 1)등차수열합  2)최대값  3) 4) 5) 6)  7)종료: ");
        scanf("%d", &menu);
        if (menu == 7) break; // 메뉴가 7이면 루프 종료
        switch (menu) {
        case 1:
            printf("\n 초항, 말항, 등차 입력 : ");
            scanf("%d%d%d", &f, &l, &e);
            for (i = f; i <= l; i = i + e)
                sum = sum + i;
            printf("\n %d~%d까지의 등차수열 합 = %d", f, l, sum);
            sum = 0;
            break;
        case 2:// 정수 10개 입력해서 그 중에서 최대/최소값 찾기
            printf("\n 정수 10개 입력 : ");
            for (i = 0; i <= 9; i++)
                scanf("%d", &data[i]);

            largest = data[0];
            smallest = data[0];
            for (i = 1; i <= 9; i++)
            {
                if (largest < data[i]) largest = data[i];
                else if (smallest > data[i]) smallest = data[i];
            }
            printf("\n 입력된 정수 10개 중에서 최대값 = %d", largest);
            printf("\n 입력된 정수 10개 중에서 최소값 = %d", smallest);

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default: printf("\n 메뉴 선택 오류. 다시 선택하시오...\n\n");
        }
    }
}

int minus(int num1, int num2)
{
    // num1과 num2를 뺄셈
    return num1 - num2;
}

void chapter3()
{
    int i, menu = -999;
    int su1, su2, sum, sub;

    int no[3], k[3], e[3], m[3], tot[3];
    float ave[3];
    char name[3][15];

    double r;  // 반지름 저장용

    int data[10], key;
    int in, year, month, day;

    while (1) // 무한 루프
    {
        printf("\n\n\n 메뉴 1)덧뺄셈  2)성적처리  3)순차탐색   4)원둘레면적  5)생년월일  6)   7)종료: ");
        scanf("%d", &menu);
        if (menu == 7) break; // 메뉴가 7이면 루프 종료

        switch (menu) {
        case 1: // 정수를 2개 입력해서, 덧셈과 뺄셈을 연산하고, 둘 다 출력
            printf("\n 정수 2개 입력 : ");
            scanf("%d %d", &su1, &su2);
            sum = su1 + su2;
            sub = minus(su1, su2);
            printf("\n %d + %d = %d, %d - %d = %d", su1, su2, sum, su1, su2, sub);
            break;
        case 2:// 3명의 학번, 이름, 국어, 영어, 수학 입력해서 총점, 평균 계산하고 모두 출력
            printf("\n <3명의 학생 정보 및 성적 입력>\n");
            for (i = 0; i < 3; i++)
            {
                printf("\n 학번 : ");  scanf("%d", &no[i]);
                printf("\n 이름 : ");  scanf("%s", name[i]);
                printf("\n 국어 : ");  scanf("%d", &k[i]);
                printf("\n 영어 : ");  scanf("%d", &e[i]);
                printf("\n 수학 : ");  scanf("%d", &m[i]);
                tot[i] = k[i] + e[i] + m[i];
                ave[i] = tot[i] / 3.0;  // 형 변환
            }

            printf("\n\n 학번  이름  국 영 수 총점 평균");
            printf("\n==============================");
            for (i = 0; i < 3; i++)
                printf("\n %4d %15s %3d %3d %3d %3d %6.1f",
                    no[i], name[i], k[i], e[i], m[i], tot[i], ave[i]);

            break;
        case 3:// 배열에 정수들을 입력 & 검색 값도 입력, 검색 값을 찾기(있으면 위치, 없으면 없음)
            printf("\n 10개의 정수 입력 :");
            for (i = 0; i < 10; i++)
                scanf("%d", &data[i]);
            printf("\n 검색하려는 값 입력 :");
            scanf("%d", &key);

            // 검색 반복 작업
            i = 0;  // for (i = 0; i < 10; i++)
            while (1)
            {
                if (i >= 10) break;
                if (key == data[i])
                {
                    printf("\n 검색 값 %d는 %d번째에 있음", key, i);
                    break;
                }
                i++;
            }
            if (i == 10) printf("\n 검색 값 %d는 없음", key);

            break;
        case 4:// 반지름을 입력해서 둘레, 면적을 출력
            printf("\n 원의 반지름 입력 : "); scanf("%lf", &r);
            printf("\n\n 반지름이 %.2lf일 때, 원의 둘레 = %lf", r, 2 * 3.141592 * r);
            printf("\n\n 반지름이 %.2lf일 때, 원의 면적 = %lf", r, 3.141592 * r * r);

            break;
        case 5:// 생년월일을 정수로 입력해서, 년월일 추출하기
            printf("\n 생년월일 입력(예 19980322) : ");
            scanf("%d", &in);
            year = in / 10000;
            month = (in - year * 10000) / 100;
            day = in % 100;

            printf("\n 귀하는 %d년 %d월 %d일에 태어났군요...", year, month, day);

            break;
        case 6:
            break;
        default: printf("\n 메뉴 선택 오류. 다시 선택하시오...\n\n");
        }
    }
}

void chapter4()
{
    int i, n, menu;
    unsigned int no; // 부호 없는 정수형 변수, 4B 
    char name[15];   // 15개까지의 문자를 저장, 15B
    char blood;      // 단일 문자를 저장, 2B
    char phone[11];  // 11개까지의 문자를 저장, 11B
    int  id;         // 정수로 입력(20041023), 4B 
    double tall;     // 실수를 저장, 8B

    const int my = 12345;  // constant number로 고정
    int x, y;
    float f1 = 1.2345678901234567890;
    double f2 = 1.2345678901234567890;

    char ID[10], pw[10];
    char bell;

    while (1) // 무한 루프
    {
        printf("\n\n\n 메뉴 1)개인정보  2)자료형  3)진법  4)실수형   5)문자형  6)제어문자  7)종료: ");
        scanf("%d", &menu);
        if (menu == 7) break; // 메뉴가 7이면 루프 종료

        switch (menu) {
        case 1: // 입력할 데이터 : 학번(부호 없는 정수), 이름(문자열), 혈액형(문자)
            //                전화번호(문자열), 생년월일(정수), 키(실수)
            //                출생학번(정수), 나이(정수), 성적(정수)
            printf("\n 학번 입력 : "); scanf("%d", &no);
            printf("\n 이름 입력 : "); scanf("%s", name);
            printf("\n 혈액형 입력 : "); scanf(" %c", &blood);
            printf("\n 전화번호 입력 : "); scanf("%s", phone);
            printf("\n 생년월일 입력(정수) : "); scanf("%d", &id);
            printf("\n 키 입력(실수) : "); scanf("%lf", &tall);

            // 입력받은 데이터를 화면에 출력
            printf("\n\n 학번 %u, 이름 %s, 혈액형 %c, 전화번호 %s, 생년월일 %d, 키 %.2lf", no, name, blood, phone, id, tall);

            break;
        case 2:// 자료형의 크기 출력
            printf("\n\n 자료형의 크기: \n");
            printf("char = %u byte \n", sizeof(char));
            printf("short = %u byte \n", sizeof(short));
            printf("int = %u byte \n", sizeof(int));
            printf("long = %u byte \n", sizeof(long));
            printf("float = %u byte \n", sizeof(float));
            printf("double = %u byte \n", sizeof(double));

            break;
        case 3: // 정수 2개를 입력받아 10진수, 8진수, 16진수로 출력
            printf("\n 정수 2개 입력 : ");
            scanf("%d %d", &x, &y);
            printf("\n 10진수: %d, %d \n", x, y);
            printf("8진수: %o, %o \n", x, y);
            printf("16진수: %x, %x \n", x, y);

            break;
        case 4:// 실수형 데이터의 크기와 소수점 이하 자릿수
            printf("\n 실수형 데이터의 크기 및 소수점 이하 자릿수 \n");
            printf("float : %.15f \n", f1);
            printf("double : %.15f \n", f2);

            break;
        case 5:// 문자열의 크기와 아스키코드 출력
            printf("\n 문자열 크기 및 아스키 코드 \n");
            printf("문자열 길이 = %d \n", strlen("hello"));
            printf("'A'의 아스키 코드 = %d \n", 'A');

            break;
        case 6:// 제어문자 사용하기
            printf("\n 제어문자 사용 예 \n");
            printf("백스페이스: Hello\b\b ");
            printf("탭 문자: \tHello ");
            printf("벨 문자: \a");

            break;
        default: printf("\n 메뉴 선택 오류. 다시 선택하시오...\n\n");
        }
    }
}

void chapter5()
{
    int i, n, menu, year;
    int cost, fee, change, c10000, c5000, c1000, c500, c100;
    c10000 = c5000 = c1000 = c500 = c100 = 0;

    unsigned int num, mask;

    double C, F;
    C = F = 0;


    while (1) //무한루프
    {
        printf("\n\n\n 메뉴 1)거스름돈  2)윤년계산  3)2의보수 4)2진수출력  5) 온도 계산 6)종료: ");		
        scanf("%d", &menu);
        if (menu == 6) break;

        switch (menu)
        {
        case 1: //물건값, 지불값 입력하면 거스름돈을 현존 화폐기준으로 최소개수로 지급 
            printf("\n 물건값   입력 : "); scanf("%d", &cost);
            printf("\n 지불금액 입력 : "); scanf("%d", &fee);
            change = fee - cost;
            if (change >= 100) {
                //화폐는 10000, 5000, 1000, 500, 100원 --> c10000, c5000, c1000, c500, c100
                c10000 = change / 10000;  //만원권 몇장?
                change = change % 10000;  //거스름돈은 천원 단위로 감소

                c5000 = change / 5000;    //오천원권 몇장?
                change = change % 5000;   //거스름돈은 천원 단위로 감소

                c1000 = change / 1000;    //천원권 몇장?
                change = change % 1000;   //거스름돈은 백원 단위로 감소

                c500 = change / 500;    //오백원권 몇장?
                change = change % 500;   //거스름돈은 백원 단위로 감소

                c100 = change / 100;    //백원권 몇장?
                change = change % 100;   //거스름돈은 백원 단위로 감소

                printf("\n\n 거스름돈 = %d", fee - cost);
                printf("\n 만원권 = %d장", c10000);
                printf("\n 오천원권 = %d장", c5000);
                printf("\n 천원권 = %d장", c1000);
                printf("\n 오백원권 = %d장", c500);
                printf("\n 백원권 = %d장", c100);
            }
            else printf("\n 지불금액이 물건 값보다 작아서 결제 불가!!!!!");

            break;
        case 2://연도를 입력해서 그해가 윤년인지 아닌지 출력
            printf("\n 연도 입력 : "); scanf("%d", &year);
            if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
                printf("\n %d년은 윤년이 맞다.", year);
            else  printf("\n %d년은 윤년이 아니다.", year);
            break;
        case 3://정수 입력해서 2의 보수로 변환한 결과를 출력
            printf("\n 정수 입력 : "); scanf("%d", &n);
            n = ~n;  //1의 보수로 변환(비트단위로 not)
            n++;     //1을 더하면 2의 보수로 변환
            printf("\n 2의 보수 = %d", n);

            break;
        case 4://십진 정수를 입력하면 비트단위 연산을 통해 이진수로 출력하기
            printf("\n 십진수 입력: "); 	scanf("%u", &num);
            mask = 1 << 31;   // mask = 1000000000000000000000000000000
            printf("\n 이진수 = ");

            for (i = 0; i <= 31; i++)
            {
                ((num & mask) == 0) ? printf("0") : printf("1");
                mask = mask >> 1;// 오른쪽으로 1비트 이동한다. 
            }
            break;

        case 5: // 화씨를 입력해서 섭씨로 변환 출력
            printf("\n 오늘 온도 화씨로 입력: ");
            scanf("%lf", &F);
            C = (double)5 / (double)9 * (F - 32);
            printf("\n 화씨 %.0lf = 섭씨 %.0f", F, C);
            break;

        default: printf("\n 메뉴선택 오류. 다시 선택하시오...\n\n");
        }
    }
}
void chapter6()
{
    int i, menu, p, r, m, f, tot;
    int lower = 0, upper = 0, digit = 0, spec = 0, chtot = 0;
    char ch;
    double  a, b, c;  //이차방정식의 3개 계수


    while (1) //무한루프
    {
        printf("\n\n 조건문 메뉴 1)대학성적  2)문자개수   3)이차방정식   4)대학성적-2   5)월별 일수   6)산출계산기   7)세율 계산기   8)종료: ");
        scanf("%d", &menu);
        if (menu == 8) break;
        switch (menu)
        {
        case 1://학점 판별하기
            printf("\n 출석 입력 : ");	scanf("%d", &p);
            if ((p >= 0 && p <= 10) == 0)
            {
                printf("\n 출석 입력 : ");	scanf("%d", &p);
            }
            printf("\n 과제 입력 : ");	scanf("%d", &r);
            if ((r >= 0 && r <= 20) == 0)
            {
                printf("\n 과제 입력 : ");  scanf("%d", &r);
            }
            printf("\n 중간 입력 : ");	scanf("%d", &m);
            if ((m >= 0 && r <= 30) == 0)
            {
                printf("\n 중간 입력 : ");  scanf("%d", &m);
            }
            printf("\n 기말 입력 : ");	scanf("%d", &f);
            if ((f >= 0 && f <= 40) == 0)
            {
                printf("\n 기말 입력 : ");  scanf("%d", &f);
            }
            tot = p + r + m + f;  //100점 만점으로 계산

            if (tot >= 95)      printf("\n귀하의 학점은 (%d점)A+입니다.", tot);
            else if (tot >= 90) printf("\n귀하의 학점은 (%d점)A0입니다.", tot);
            else if (tot >= 85) printf("\n귀하의 학점은 (%d점)B+입니다.", tot);
            else if (tot >= 80) printf("\n귀하의 학점은 (%d점)B0입니다.", tot);
            else if (tot >= 75) printf("\n귀하의 학점은 (%d점)C+입니다.", tot);
            else if (tot >= 70) printf("\n귀하의 학점은 (%d점)C0입니다.", tot);
            else if (tot >= 65) printf("\n귀하의 학점은 (%d점)D+입니다.", tot);
            else if (tot >= 60) printf("\n귀하의 학점은 (%d점)D0입니다.", tot);
            else                printf("\n귀하의 학점은 (%d점)F입니다.", tot);

            break;
        case 2: //임의로 문자열을 입력해서 소/대/숫/특수/총 문자 개수 출력
            ch = getchar();  //메뉴 번호 뒤의 엔터키를 버퍼에서 빼버림
            lower = upper = digit = spec = chtot = 0; //초기화

            printf("\n\n 문자열 입력 : ");
            while (1)
            {
                ch = getchar();  //입력한 문자들은 버퍼에 저장, 하나씩 빼와라
                if (ch == '\n') break;
                //소,대,숫,특수 종류별 카운팅
                chtot++;
                if (ch >= 'a' && ch <= 'z')      lower++;
                else if (ch >= 'A' && ch <= 'Z') upper++;
                else if (ch >= '0' && ch <= '9') digit++;
                else                             spec++;
            }
            //chtot = lower + upper + digit + spec;

            printf("\n\n 총개수 소문자  대문자  숫자문자 특수문자");
            printf("\n===========================================");
            printf("\n %6d %6d %6d %6d %6d",
                chtot, lower, upper, digit, spec);

            break;
        case 3: //실수계수 3개 입력해서 1차/2차 판별, 허근/실근 판별, 근의 공식으로 2개 출력
            printf("\n 계수 a 입력 : ");	scanf("%lf", &a);
            printf("\n 계수 b 입력 : ");	scanf("%lf", &b);
            printf("\n 계수 c 입력 : ");	scanf("%lf", &c);

            if (a == 0.0) printf("\n 근 = %.2lf", -c / b);
            else if (b * b - 4 * a * c < 0) printf("\n 근이 없음");
            else
            {
                printf("\n 근 = %.2lf", (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
                printf("\n 근 = %.2lf", (-b - sqrt(b * b - 4 * a * c)) / (2 * a));
            }

            break;
        case 4: // switch 문으로 성적계산하기
            printf("\n 출석을 입력하시오: ");
            scanf("%d", &p);
            if ((p >= 0 && p <= 10) == 0)
            {
                printf("\n 출석을 다시 입력하시오: ");
                scanf("%d", &p);
            }

            printf("\n 과제를 입력하시오: ");
            scanf("%d", &r);
            if ((m >= 0 && r <= 20) == 0)
            {
                printf("\n 과제를 다시 입력하시오: ");
                scanf("%d", &r);
            }

            printf("\n 중간고사 성적을 입력하시오: ");
            scanf("%d", &m);
            if ((m >= 0 && m <= 30) == 0)
            {
                printf("\n 중간고사 성적을 다시 입력하시오: ");
                scanf("%d", &m);
            }

            printf("\n 기말고사 성적을 입력하시오: ");
            scanf("%d", &f);
            if ((f >= 0 && f <= 40) == 0)
            {
                printf("\n 기말고사 성적을 다시 입력하시오: ");
                scanf("%d", &f);
            }

            tot = p + r + m + f; // 100점 만점으로 계산

            switch (tot/5)
            {
            case 20: 
            case 19: printf("\n 귀하는 (%d점) a+입니다.", tot); break;
            case 18: printf("\n 귀하는 (%d점) A입니다.", tot); break;
            case 17: printf("\n 귀하는 (%d점) B+입니다.", tot); break;
            case 16: printf("\n 귀하는 (%d점) B입니다.", tot); break;
            case 15: printf("\n 귀하는 (%d점) C+입니다.", tot); break;
            case 14: printf("\n 귀하는 (%d점) C입니다.", tot); break;
            case 13: printf("\n 귀하는 (%d점) D+입니다.", tot); break;
            case 12: printf("\n 귀하는 (%d점) D입니다.", tot); break;
            default: printf("\n 귀하는 (%d점) F입니다.", tot);
            }
            break;

        case 5: // 월 입력하면 switch문을 이용해서 며칠이 있는지 출력
            printf("\n몇월?: "); scanf("%d", &i);
            switch (i)
            {
            case 2:
                printf("\n &d월에는 28일까지 있습니다.", i);
                break;
            case 4: case 6: case 9: case 11:
                printf("\n %d월에는 30일까지 있습니다.", i);
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                printf("\n %d월에는 31일까지 있습니다.", i);
                break;
            }
            break;
        case 6: // 사칙연산식 (2 + 3;띄어쓰기o)을 입력받아서 계산결과를 출력하기 --> 공백이 있는 상태로 스캔에프를 만들어도 안 써도 작동함.
            printf("\n 사칙연산식 입력(예: 12 + 34) : ");
            scanf("%d %c $d", &p, &ch, &r);

            if (ch == '+') printf("\n 계산결과 = %d", p + r);
            else if (ch == '-') printf("\n 계산결과 = %d", p - r);
            else if (ch == '*') printf("\n 계산결과 = %d", p * r);
            else if (ch == '/') printf("\n 계산결과 = %d", p / r);
            else printf("\n 입력 사칙연산식의 오류");
            break;

        case 7: // 연봉을 입력받고, 소득구분에 따른 세율을 곱하고, 공제액을 빼서 출력
            printff("\n 연봉을 입력하세요: "); scanf("%d", &p);
            if (p < 12000000) printf("\n 산출세액 = %.1lf", p * 0.06);
            else if (p < 46000000) printf("\n 산출세액 = %.1lf", p * 0.15 - 1060000);
            else if (p < 88000000) printf("\n 산출세액 = %.1lf", p * 0.24 - 5220000);
            else if (p < 150000000) printf("\n 산출세액 = %.1lf", p * 0.35 - 14900000);
            break;

        default: printf("\n 메뉴선택 오류. 다시 선택하시오...\n\n");
        }
    }
}

void chapter7()
{
    int i, menu, p, r, m, f, tot;
    int n, d, sum;  //초항 i, 말항 n, 등차 d, 총합 sum
    int x, y; //최대공약수를 위한 변수
    double money = 1;

    //난수맞추기 메뉴의 변수
    int  answer, guess, cnt = 0;
    //소수 메뉴의 변수
    int count = 0, prime[N];
    //대소문자 변환 메뉴를 위한 변수
    char letter;

    while (1) //무한루프
    {
        printf("\n\n 반복문 메뉴 1)구구단 2)등차수열합 3)입력연습 4)최대공약수  5)dowhile문  6)난수 발생  7)별 도형  8)소수  9)대소문자 변환   10)종료 : ");
        scanf("%d", &menu);
        if (menu == 10) break;
        switch (menu)
        {
        case 1://구구단 출력하기
            printf("\n 단 입력 : ");	scanf("%d", &p);
            i = 1; //*1 ~ *9   for (i=1; i<=9; i++)
            while (i <= 9)
            {
                printf("\n %d * %d = %2d", p, i, p * i);
                i++;
            }
            break;
        case 2: //등차수열 합 : 초항, 말항, 등차 입력해서 계산
            sum = 0;  //초기화
            printf("\n 초항 입력 : ");	scanf("%d", &i);  //리셋
            printf("\n 말항 입력 : ");	scanf("%d", &n);
            printf("\n 등차 입력 : ");	scanf("%d", &d);  //리셋 

            for (p = i; p <= n; p = p + d)
            {
                sum = sum + p;
            }
            /*
            while (i <= n)
            {
                //if (i > n) break;
                sum = sum + i;
                i = i + d;
            }
            */
            printf("\n\n 1 +2+ ... + %d = %d", n, sum);
            break;
        case 3: // 정수를 무제한 입력해서 평균내라. 단, 음수가 입력되면 끝
            i = 0, sum = 0; //i는 카운터 역할
            while (1)
            {
                printf("\n 정수 입력 : ");
                scanf("%d", &n);

                if (n < 0) break;
                sum = sum + n;
                i++;
            }
            printf("\n\n 평균 = %.2lf", sum / (double)i);

            break;
        case 4://정수 2개 입력받아서 최대공약수를 출력
            printf("\n 정수 2개 입력(큰값 작은값) : ");
            scanf("%d%d", &x, &y);
            while (y != 0)
            {
                r = x % y;
                x = y;
                y = r;
            }//while문을 빠져나오는 순간, 최대공약수는 x

            printf("\n\n 최대공약수 = %d", x);
            break;
        case 5: //음수가 아닐동안 계속(do-while) 입력하고 덧셈해서 출력하라
            sum = 0;
            do {
                printf("\n 정수 입력 : "); 	scanf("%d", &n);
                if (n < 0) break;
                sum = sum + n;
            } while (n >= 0);   //음수가 아니면 반복

            printf("\n\n 합산 = %d", sum);
            break;
        case 6: //1~100 사이의 난수를 가정하고 이분검색 방식으로 찾아가기
            srand((unsigned)time(NULL));  //현재시간 기준 시드값 설정
            answer = (rand() % 100) + 1;
            cnt = 0;
            do {
                printf("\n 추측값 입력 : ");
                scanf("%d", &guess);
                if (answer < guess) printf("\n 너무 높게 봤네?");
                if (answer > guess) printf("\n 조금 더 써봐");
                cnt++;
            } while (answer != guess);
            //현재 상황? 빙고
            printf("\n 빙고.... 추측횟수 = %d", cnt);
            break;

        case 7: // 별 도형 출력
        {
            int i, j;
            for ( i = 1; i <= 10; i++)
            {
                for ( j = 0; j < i; j++)
                printf("*");
                printf("\n");
            }
        }
        break;

        case 8://소수
            for (i = 0; i < N; i++) // 배열요소에 1 입력(소수로 가정)
                prime[i] = 1;
            prime[0] = prime[1] = 0; //0~1은 소수에서 제외
            for (i = 2; i < N; i++) // 2부터 시작한다.
                if (prime[i] == 1) // 소수인 경우에만 작동
                    for (int j = 2; j < N; j++)
                        if (i * j < N) prime[i * j] = 0;
            for (i = 2; i < N; i++)
            {
                if (prime[i] == 1)  // i가 소수이면?
                {
                    printf("%3d ", i);
                    count++;
                    if (count % 10 == 0) printf("\n");
                }
            }

        case 9: //대문자는 소문자로, 소문자는 대문자로 변환. 나머지는 continue 
            letter = getchar(); //메뉴번호 다음의 엔터키 제거용
            while (1)
            {
                printf("\n\n 대/소문자 입력 : ");
                letter = getche();   //#include <conio.h>
                if (letter == '?') break;

                if (letter >= 'a' && letter <= 'z')
                    printf("\n 입력문자 %c는 대문자 %c로 변환", letter, letter - 32);
                else if (letter >= 'A' && letter <= 'Z')
                    printf("\n 입력문자 %c는 소문자 %c로 변환", letter, letter + 32);
            }
            break;
        default: printf("\n 메뉴선택 오류. 다시 선택하시오...\n\n");
        }
    }
}

int main()
{
    int ch;

    while (1) // 무한 루프
    {
        printf("\n\n\n 메뉴 1)챕터 1  2)챕터 2  3)챕터 3  4)챕터 4  5)챕터 5  6)챕터 6  7)챕터 7  8)종료: ");
        scanf("%d", &ch);
        if (ch == 8) break; // ch가 8이면 루프 종료
        switch (ch)
        {
        case 1:
            chapter1();
            break;
        case 2:
            //chapter2(); // 함수가 정의되지 않았음
            printf("챕터 2는 챕터 1과 함께~");
            break;
        case 3:
            chapter3();
            break;
        case 4:
            chapter4();
            break;
        case 5:
            chapter5();
            break;
        case 6:
            chapter6();
            break;
        case 7:
            chapter7();
            break;
        case 8:
            break;
        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }
    }
    return 0;
}
