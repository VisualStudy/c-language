#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h> //���ڿ� �����Լ��� ����Ϸ���
#include <memory.h> //���� �Ҵ��Ϸ���
#include <limits.h> //�ڷ����� �ִ��ּҰ��� �����Ϸ���
#include <math.h>   //���а����� ����Ϸ���
#include <conio.h>  //getche() �Լ� ����Ϸ���
#pragma warning (disable:4996)  //VC++���� C������ �������� ����Ϸ���

#define PI 3.141592      //���� ����ϴ� ����� ��ȣ����� ���
#define N 101            //���ĺ��ʹ� N�� ������ 101�� ����

void chapter1() 
{
    int i, menu, f, l, e, sum = 0, data[10], largest, smallest;
    while (1) //���ѷ���
    {
        printf("\n\n\n �޴� 1)����������  2)�ִ밪  3) 4) 5) 6)  7)����: ");
        scanf("%d", &menu);
        if (menu == 7) break;
        switch (menu) {
        case 1:
            printf("\n ����, ����, ���� �Է� : ");
            scanf("%d%d%d", &f, &l, &e);
            for (i = f; i <= l; i = i + e)
                sum = sum + i;
            printf("\n %d~%d������ �������� �� = %d", f, l, sum);
            sum = 0;
            break;
        case 2://���� 10�� �Է��ؼ� �� �߿��� �ִ�/�ּҰ� ã��
            printf("\n ���� 10�� �Է� : ");
            for (i = 0; i <= 9; i++)
                scanf("%d", &data[i]);

            largest = data[0];
            smallest = data[0];
            for (i = 1; i <= 9; i++)
            {
                if (largest < data[i]) largest = data[i];
                else if (smallest > data[i]) smallest = data[i];
            }
            printf("\n �Էµ� ���� 10�� �߿��� �ִ밪 = %d", largest);
            printf("\n �Էµ� ���� 10�� �߿��� �ּҰ� = %d", smallest);

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default: printf("\n �޴����� ����. �ٽ� �����Ͻÿ�...\n\n");
        }
    }
}

void chapter2()
{

}

int minus(int num1, int num2)
{
    int num1 = 0;
    int num2 = 0;

    return  num1 - num2;
}

void chapter3() 
{
    int i, menu = -999;
    int su1, su2, sum, sub;

    int no[3], k[3], e[3], m[3], tot[3];
    float ave[3];
    char name[3][15];

    double r;  //������ �����

    int data[10], key;
    int in, year, month, day;

    while (1) //���ѷ���
    {
        printf("\n\n\n �޴� 1)������  2)����ó��  3)����Ž��   4)���ѷ�����  5)�������  6)   7)����: ");
        scanf("%d", &menu);
        if (menu == 7) break;

        switch (menu) {
        case 1: //������ 2�� �Է��ؼ�, ������ ������ �����ϰ�, �Ѵ� �������
            printf("\n ���� 2�� �Է� : ");
            scanf("%d %d", &su1, &su2);
            sum = su1 + su2;
            sub = minus(su1, su2);
            printf("\n %d + %d = %d, %d - %d = %d", su1, su2, sum, su1, su2, sub);
            break;
        case 2://3���� �й�,�̸�,��,��,�� �Է��ؼ� ����, ��� ����ϰ� ��� ���
            printf("\n <3���� �л� ���� �� ���� �Է�>\n");
            for (i = 0; i < 3; i++)
            {
                printf("\n �й� : ");  scanf("%d", &no[i]);
                printf("\n �̸� : ");  scanf("%s", name[i]);
                printf("\n ���� : ");  scanf("%d", &k[i]);
                printf("\n ���� : ");  scanf("%d", &e[i]);
                printf("\n ���� : ");  scanf("%d", &m[i]);
                tot[i] = k[i] + e[i] + m[i];
                ave[i] = tot[i] / 3.0;  //�� ��ȯ
            }

            printf("\n\n �й�  �̸�  �� �� �� ���� ���");
            printf("\n==============================");
            for (i = 0; i < 3; i++)
                printf("\n %4d %15s %3d %3d %3d %3d %6.1f",
                    no[i], name[i], k[i], e[i], m[i], tot[i], ave[i]);

            break;
        case 3://�迭�� �������� �Է�&�˻����� �Է�, �˻����� ã��(������ ��ġ, ������ ����)
            printf("\n 10���� ���� �Է� :");
            for (i = 0; i < 10; i++)
                scanf("%d", &data[i]);
            printf("\n �˻��Ϸ��� �� �Է� :");
            scanf("%d", &key);

            //�˻� �ݺ��۾�
            i = 0;  // for (i = 0; i < 10; i++)
            while (1)
            {
                if (i >= 10) break;
                if (key == data[i])
                {
                    printf("\n �˻��� %d�� %d��°�� ����", key, i);
                    break;
                }
                i++;
            }
            if (i == 10) printf("\n �˻��� %d�� ����", key);

            break;
        case 4://�������� �Է��ؼ� �ѷ�, ������ ���
            printf("\n ���� ������ �Է� : "); scanf("%lf", &r);
            printf("\n\n �������� %.2lf�� ��, ���� �ѷ� = %lf", r, 2 * 3.141592 * r);
            printf("\n\n �������� %.2lf�� ��, ���� ���� = %lf", r, 3.141592 * r * r);

            break;
        case 5://��������� ������ �Է��ؼ�, ����� �����ϱ�
            printf("\n ������� �Է�(�� 19980322) : ");
            scanf("%d", &in);
            year = in / 10000;
            month = (in - year * 10000) / 100;
            day = in % 100;

            printf("\n ���ϴ� %d�� %d�� %d�Ͽ� �¾����...", year, month, day);





            break;
        case 6:
            break;
        default: printf("\n �޴����� ����. �ٽ� �����Ͻÿ�...\n\n");
        }
    }
}

void chapter4() 
{
    int i, n, menu;
    unsigned int no; //��ȣ���� ������ ����, 4B 
    char name[15];   //15�������� ���ڸ� ����, 15B
    char blood;      //���Ϲ��ڸ� ����, 2B
    char phone[11];  //11�������� ���ڸ� ����, 11B
    int  id;         //������ �Է�(20041023), 4B 
    double tall;     //�Ǽ��� ����, 8B

    const int my = 12345;  //constant number�� ����
    int x, y;
    float f1 = 1.2345678901234567890;
    double f2 = 1.2345678901234567890;

    char ID[10], pw[10];
    char bell;

    while (1) //���ѷ���
    {
        printf("\n\n\n �޴� 1)��������  2)�ڷ���  3)����  4)�Ǽ���   5)������  6)�����  7)����: ");
        scanf("%d", &menu);
        if (menu == 7) break;

        switch (menu) {
        case 1: //�Է��� ������ : �й�(��ȣ���� ����), �̸�(���ڿ�), ������(����)
            //                ��ȭ��ȣ(���ڿ�), �������(����), Ű(�Ǽ�), 
            // �Է� ���� �����ϰ� ����ϰ� ����Ϸ��� ������ � �ʿ��ұ�?
            printf("\n �й�     : "); scanf("%u", &no);
            printf("\n �̸�     : "); scanf("%s", name);
            //�Է¹��ۿ� �����ִ� ����Ű ���� --> ���� ���ڸ� �Է� ����
            blood = getchar();
            printf("\n ������   : "); scanf("%c", &blood);
            printf("\n ��ȭ��ȣ : "); scanf("%s", phone);
            printf("\n ������� : "); scanf("%d", &id);
            printf("\n ����     : "); scanf("%lf", &tall);

            //����� ���� & �� �� �� ���⵵ ����





            break;

        case 2://sizeof �����ڸ� ����ؼ� �� �ڷ����� ����Ʈ �� ���
            //��ȣ���� �ڷ����� ���, �����÷ο�&����÷ο� üũ
            printf("\n\n no�� ũ��     = %d����Ʈ", sizeof(no));
            printf("\n\n name[]�� ũ�� = %d����Ʈ", sizeof(name));
            printf("\n\n blood�� ũ��  = %d����Ʈ", sizeof(blood));
            printf("\n\n phone[]�� ũ��= %d����Ʈ", sizeof(phone));
            printf("\n\n id�� ũ��     = %d����Ʈ", sizeof(id));
            printf("\n\n tall�� ũ��   = %d����Ʈ", sizeof(tall));
            //�����÷ο� ����

            n = INT_MIN - 1;
            printf("\n n = %d", n);


            break;
        case 3://8����, 16������ 10������ �Բ� ����غ���
            x = 10, y = -10; //y�� 2�� �������·� ������ ����

            printf("\n x = %08X", x);
            printf("\n y = %08X", y);
            printf("\n x+y = %08X", x + y);


            break;
        case 4://float, double �Ǽ��� �����͸� ����غ���

            printf("\n f1 = %30.25f", f1);
            printf("\n f2 = %30.25lf", f2);

            f1 = 1.234e40;  //e38�� �ʰ��� ���̹Ƿ� �����÷ο�
            printf("\n f1 = %30.25f", f1);
            f2 = 1.234e40;
            printf("\n f2 = %30.25lf", f2);

            f2 = 1.23456e-300;  //����÷ο� üũ
            printf("\n f2 = %e", f2);



            break;
        case 5://char ������ �����͸� ����غ��� : ���̵� ��� �Է��ؼ� ����/���� ���
            //���̵� : abc	 ��� : 1234
                            //���̵�, ��� �Է�
            printf("\n ���̵� �Է� : ");
            scanf("%s", ID);
            printf("\n ��й�ȣ �Է� : ");
            scanf("%s", pw);

            while (1) //������ �ݺ�
            {//���� Ȯ��



                if (strcmp("abc", ID) == 0)
                    if (strcmp("1234", pw) == 0)
                    {
                        printf("\n �α��� ����. "); break;
                    }
                    else
                    {
                        printf("\n ��й�ȣ ����, ���Է�");
                        printf("\n ��й�ȣ �Է� : ");
                        scanf("%s", pw);
                    }
                else {
                    printf("\n ���̵� ����, ���Է�");
                    printf("\n ���̵� �Է� : ");
                    scanf("%s", ID);
                    printf("\n ��й�ȣ �Է� : ");
                    scanf("%s", pw);
                }
            }
            break;
        case 6://���� ����� ����غ���
            bell = '\a';
            printf("%c%c%c%c%c%c", bell, bell, bell, bell, bell, bell);
            printf("\n\n ������ ������ \"UCC\" �Ұ��մϴ�.");
            printf("\n\n \\�� ����ھ�");



            break;
        default: printf("\n �޴����� ����. �ٽ� �����Ͻÿ�...\n\n");
        }
    }
}

void chapter5() 
{
    int i, n, menu, year;
    int cost, fee, change, c10000, c5000, c1000, c500, c100;
    c10000 = c5000 = c1000 = c500 = c100 = 0;

    unsigned int num, mask;

    while (1) //���ѷ���
    {
        printf("\n\n\n �޴� 1)�Ž�����  2)������  3)2�Ǻ��� 4)2�������  5)  7)����: ");		scanf("%d", &menu);
        if (menu == 7) break;
        switch (menu)
        {
        case 1: //���ǰ�, ���Ұ� �Է��ϸ� �Ž������� ���� ȭ��������� �ּҰ����� ���� 
            printf("\n ���ǰ�   �Է� : "); scanf("%d", &cost);
            printf("\n ���ұݾ� �Է� : "); scanf("%d", &fee);
            change = fee - cost;
            if (change >= 100) {
                //ȭ��� 10000, 5000, 1000, 500, 100�� --> c10000, c5000, c1000, c500, c100
                c10000 = change / 10000;  //������ ����?
                change = change % 10000;  //�Ž������� õ�� ������ ����

                c5000 = change / 5000;    //��õ���� ����?
                change = change % 5000;   //�Ž������� õ�� ������ ����

                c1000 = change / 1000;    //õ���� ����?
                change = change % 1000;   //�Ž������� ��� ������ ����

                c500 = change / 500;    //������� ����?
                change = change % 500;   //�Ž������� ��� ������ ����

                c100 = change / 100;    //����� ����?
                change = change % 100;   //�Ž������� ��� ������ ����

                printf("\n\n �Ž����� = %d", fee - cost);
                printf("\n ������ = %d��", c10000);
                printf("\n ��õ���� = %d��", c5000);
                printf("\n õ���� = %d��", c1000);
                printf("\n ������� = %d��", c500);
                printf("\n ����� = %d��", c100);
            }
            else printf("\n ���ұݾ��� ���� ������ �۾Ƽ� ���� �Ұ�!!!!!");

            break;
        case 2://������ �Է��ؼ� ���ذ� �������� �ƴ��� ���
            printf("\n ���� �Է� : "); scanf("%d", &year);
            if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
                printf("\n %d���� ������ �´�.", year);
            else  printf("\n %d���� ������ �ƴϴ�.", year);
            break;
        case 3://���� �Է��ؼ� 2�� ������ ��ȯ�� ����� ���
            printf("\n ���� �Է� : "); scanf("%d", &n);
            n = ~n;  //1�� ������ ��ȯ(��Ʈ������ not)
            n++;     //1�� ���ϸ� 2�� ������ ��ȯ
            printf("\n 2�� ���� = %d", n);

            break;
        case 4://���� ������ �Է��ϸ� ��Ʈ���� ������ ���� �������� ����ϱ�
            printf("\n ������ �Է�: "); 	scanf("%u", &num);
            mask = 1 << 31;   // mask = 1000000000000000000000000000000
            printf("\n ������ = ");

            for (i = 0; i <= 31; i++)
            {
                ((num & mask) == 0) ? printf("0") : printf("1");
                mask = mask >> 1;// ���������� 1��Ʈ �̵��Ѵ�. 
            }
            break;

        default: printf("\n �޴����� ����. �ٽ� �����Ͻÿ�...\n\n");
        }
    }
}

void chapter6() 
{
    int i, menu, p, r, m, f, tot;
    int lower = 0, upper = 0, digit = 0, spec = 0, chtot = 0;
    char ch;
    double  a, b, c;  //������������ 3�� ���


    while (1) //���ѷ���
    {
        printf("\n\n ���ǹ� �޴� 1)���м���  2)���ڰ���   3)����������   4)���м���-2   5)���� �ϼ�   6)���⼼��   7)����: ");
        scanf("%d", &menu);
        if (menu == 7) break;
        switch (menu)
        {
        case 1://���� �Ǻ��ϱ�
            printf("\n �⼮ �Է� : ");	scanf("%d", &p);
            if ((p >= 0 && p <= 10) == 0)
            {
                printf("\n �⼮ �Է� : ");	scanf("%d", &p);
            }
            printf("\n ���� �Է� : ");	scanf("%d", &r);
            if ((r >= 0 && r <= 20) == 0)
            {
                printf("\n ���� �Է� : ");  scanf("%d", &r);
            }
            printf("\n �߰� �Է� : ");	scanf("%d", &m);
            if ((m >= 0 && r <= 30) == 0)
            {
                printf("\n �߰� �Է� : ");  scanf("%d", &m);
            }
            printf("\n �⸻ �Է� : ");	scanf("%d", &f);
            if ((f >= 0 && f <= 40) == 0)
            {
                printf("\n �⸻ �Է� : ");  scanf("%d", &f);
            }
            tot = p + r + m + f;  //100�� �������� ���

            if (tot >= 95)      printf("\n������ ������ (%d��)A+�Դϴ�.", tot);
            else if (tot >= 90) printf("\n������ ������ (%d��)A0�Դϴ�.", tot);
            else if (tot >= 85) printf("\n������ ������ (%d��)B+�Դϴ�.", tot);
            else if (tot >= 80) printf("\n������ ������ (%d��)B0�Դϴ�.", tot);
            else if (tot >= 75) printf("\n������ ������ (%d��)C+�Դϴ�.", tot);
            else if (tot >= 70) printf("\n������ ������ (%d��)C0�Դϴ�.", tot);
            else if (tot >= 65) printf("\n������ ������ (%d��)D+�Դϴ�.", tot);
            else if (tot >= 60) printf("\n������ ������ (%d��)D0�Դϴ�.", tot);
            else                printf("\n������ ������ (%d��)F�Դϴ�.", tot);

            break;
        case 2: //���Ƿ� ���ڿ��� �Է��ؼ� ��/��/��/Ư��/�� ���� ���� ���
            ch = getchar();  //�޴� ��ȣ ���� ����Ű�� ���ۿ��� ������
            lower = upper = digit = spec = chtot = 0; //�ʱ�ȭ

            printf("\n\n ���ڿ� �Է� : ");
            while (1)
            {
                ch = getchar();  //�Է��� ���ڵ��� ���ۿ� ����, �ϳ��� ���Ͷ�
                if (ch == '\n') break;
                //��,��,��,Ư�� ������ ī����
                chtot++;
                if (ch >= 'a' && ch <= 'z')      lower++;
                else if (ch >= 'A' && ch <= 'Z') upper++;
                else if (ch >= '0' && ch <= '9') digit++;
                else                             spec++;
            }
            //chtot = lower + upper + digit + spec;

            printf("\n\n �Ѱ��� �ҹ���  �빮��  ���ڹ��� Ư������");
            printf("\n===========================================");
            printf("\n %6d %6d %6d %6d %6d",
                chtot, lower, upper, digit, spec);

            break;
        case 3: //�Ǽ���� 3�� �Է��ؼ� 1��/2�� �Ǻ�, ���/�Ǳ� �Ǻ�, ���� �������� 2�� ���
            printf("\n ��� a �Է� : ");	scanf("%lf", &a);
            printf("\n ��� b �Է� : ");	scanf("%lf", &b);
            printf("\n ��� c �Է� : ");	scanf("%lf", &c);

            if (a == 0.0) printf("\n �� = %.2lf", -c / b);
            else if (b * b - 4 * a * c < 0) printf("\n ���� ����");
            else
            {
                printf("\n �� = %.2lf", (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
                printf("\n �� = %.2lf", (-b - sqrt(b * b - 4 * a * c)) / (2 * a));
            }

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default: printf("\n �޴����� ����. �ٽ� �����Ͻÿ�...\n\n");
        }
    }
}

void chapter7()
{
    int i, menu, p, r, m, f, tot;
    int n, d, sum;  //���� i, ���� n, ���� d, ���� sum
    int x, y; //�ִ������� ���� ����
    double money = 1;

    //�������߱� �޴��� ����
    int  answer, guess, cnt = 0;
    //�Ҽ� �޴��� ����
    int count = 0, prime[N];
    //��ҹ��� ��ȯ �޴��� ���� ����
    char letter;

    while (1) //���ѷ���
    {
        printf("\n\n �ݺ��� �޴� 1)������ 2)���������� 3)�Է¿��� 4)�ִ�����  5)dowhile��  6)�������߱�  7)�Ҽ�  8)��ҹ��� ��ȯ   9)���� : ");
        scanf("%d", &menu);
        if (menu == 9) break;
        switch (menu)
        {
        case 1://������ ����ϱ�
            printf("\n �� �Է� : ");	scanf("%d", &p);
            i = 1; //*1 ~ *9   for (i=1; i<=9; i++)
            while (i <= 9)
            {
                printf("\n %d * %d = %2d", p, i, p * i);
                i++;
            }
            break;
        case 2: //�������� �� : ����, ����, ���� �Է��ؼ� ���
            sum = 0;  //�ʱ�ȭ
            printf("\n ���� �Է� : ");	scanf("%d", &i);  //����
            printf("\n ���� �Է� : ");	scanf("%d", &n);
            printf("\n ���� �Է� : ");	scanf("%d", &d);  //���� 

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
        case 3: // ������ ������ �Է��ؼ� ��ճ���. ��, ������ �ԷµǸ� ��
            i = 0, sum = 0; //i�� ī���� ����
            while (1)
            {
                printf("\n ���� �Է� : ");
                scanf("%d", &n);

                if (n < 0) break;
                sum = sum + n;
                i++;
            }
            printf("\n\n ��� = %.2lf", sum / (double)i);

            break;
        case 4://���� 2�� �Է¹޾Ƽ� �ִ������� ���
            printf("\n ���� 2�� �Է�(ū�� ������) : ");
            scanf("%d%d", &x, &y);
            while (y != 0)
            {
                r = x % y;
                x = y;
                y = r;
            }//while���� ���������� ����, �ִ������� x

            printf("\n\n �ִ����� = %d", x);
            break;
        case 5: //������ �ƴҵ��� ���(do-while) �Է��ϰ� �����ؼ� ����϶�


            sum = 0;
            do {
                printf("\n ���� �Է� : "); 	scanf("%d", &n);
                if (n < 0) break;
                sum = sum + n;
            } while (n >= 0);   //������ �ƴϸ� �ݺ�

            printf("\n\n �ջ� = %d", sum);
            break;
        case 6: //1~100 ������ ������ �����ϰ� �̺а˻� ������� ã�ư���
            srand((unsigned)time(NULL));  //����ð� ���� �õ尪 ����
            answer = (rand() % 100) + 1;
            cnt = 0;
            do {
                printf("\n ������ �Է� : ");
                scanf("%d", &guess);
                if (answer < guess) printf("\n �ʹ� ���� �ó�?");
                if (answer > guess) printf("\n ���� �� ���");
                cnt++;
            } while (answer != guess);
            //���� ��Ȳ? ����
            printf("\n ����.... ����Ƚ�� = %d", cnt);
            break;
        case 7://��ǥ �簢��(10 X 50) �׸���
            for (i = 0; i < N; i++) // �迭��ҿ� 1 �Է�(�Ҽ��� ����)
                prime[i] = 1;
            prime[0] = prime[1] = 0; //0~1�� �Ҽ����� ����
            for (i = 2; i < N; i++) // 2���� �����Ѵ�.
                if (prime[i] == 1) // �Ҽ��� ��쿡�� �۵�
                    for (int j = 2; j < N; j++)
                        if (i * j < N) prime[i * j] = 0;
            for (i = 2; i < N; i++)
            {
                if (prime[i] == 1)  // i�� �Ҽ��̸�?
                {
                    printf("%3d ", i);
                    count++;
                    if (count % 10 == 0) printf("\n");
                }
            }

        case 8: //�빮�ڴ� �ҹ��ڷ�, �ҹ��ڴ� �빮�ڷ� ��ȯ. �������� continue 
            letter = getchar(); //�޴���ȣ ������ ����Ű ���ſ�
            while (1)
            {
                printf("\n\n ��/�ҹ��� �Է� : ");
                letter = getche();   //#include <conio.h>
                if (letter == '?') break;

                if (letter >= 'a' && letter <= 'z')
                    printf("\n �Է¹��� %c�� �빮�� %c�� ��ȯ", letter, letter - 32);
                else if (letter >= 'A' && letter <= 'Z')
                    printf("\n �Է¹��� %c�� �ҹ��� %c�� ��ȯ", letter, letter + 32);
            }
            break;
        default: printf("\n �޴����� ����. �ٽ� �����Ͻÿ�...\n\n");
        }
    }
}

void main()
{
    int menu;
    while (1) //���ѷ���
    {
        printf("\n\n\n �޴� 1)1��  2)2��  3)3��  4)4��  5)5��  6)6��  7)7��  8)����: ");
        scanf("%d", &menu);
        if (menu == 8) break;
        switch (menu) {
        case 1:
            chapter1();
            break;
        case 2:
            chapter2();
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
        default:
            printf("\n �޴����� ����. �ٽ� �����Ͻÿ�...\n\n");
        }
    }
}
