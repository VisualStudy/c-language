#include <stdio.h>

int main(void)
{
    int money;

    printf("## 지폐로 교환할 돈은 ? ");
    scanf("%d", &money);

    int num50 = money / 50000;
    int num50_per = money % 50000;
    int num10 = num50_per / 10000;
    int num10_per = num50_per % 10000;
    int num5 = num10_per / 5000;
    int num5_per = num10_per % 5000;
    int num1 = num5_per / 1000;
    int num_ = num5_per % 1000;

    printf("\n오만 원짜리 => %d 장\n", num50);
    printf("만 원짜리 => %d 장\n", num10);
    printf("오천 원짜리 => %d 장\n", num5);
    printf("천 원짜리 => %d 장", num1);
    printf("지폐로 바꾸지 못한 잔돈 => %d 원", num_);

    return 0;
}