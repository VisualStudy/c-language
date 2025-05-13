#include <stdio.h>

int main(void) 
{
    FILE* fp = fopen("hello.txt", "w"); // 쓰기 모드로 파일 열기
    // "r": 읽기 전용 / "w": 쓰기 전용 / "a": 추가 / "rb" "wb": 이진 파일 전용 모드
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다. 즉, 파일 열기 실패!\n");
        return 1; // 비정상 종료: 더 이상 진행해봤자 프로그램에 의미 X
                  // ex) 아, 책이 없네. 오늘 공부는 끝! >_<
    }

    fprintf(fp, "파일 포인터로 쓴 내용: 반가워요!"); // 파일에 작성
    fclose(fp); // 파일 닫기

    return 0;
}