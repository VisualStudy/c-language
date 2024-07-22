#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 랜덤 메시지를 생성하기 위한 함수
void generateMessage(char* buffer, size_t size) {
    const char* greetings[] = { "안녕하세요", "반갑습니다", "안녕하십니까", "좋은 하루 되세요" };
    const char* names[] = { "홍길동", "김철수", "이영희", "박민수" };
    const char* actions[] = { "오늘 하루도", "이번 주말도", "이번 주도", "앞으로도" };
    const char* wishes[] = { "행복하세요", "건강하세요", "즐거운 시간 되세요", "힘내세요" };

    // 배열의 크기 계산
    size_t greetingsSize = sizeof(greetings) / sizeof(greetings[0]);
    size_t namesSize = sizeof(names) / sizeof(names[0]);
    size_t actionsSize = sizeof(actions) / sizeof(actions[0]);
    size_t wishesSize = sizeof(wishes) / sizeof(wishes[0]);

    // 랜덤 인덱스 선택
    int greetIndex = rand() % greetingsSize;
    int nameIndex = rand() % namesSize;
    int actionIndex = rand() % actionsSize;
    int wishIndex = rand() % wishesSize;

    // 메시지 조합
    snprintf(buffer, size, "%s, %s! %s %s.", greetings[greetIndex], names[nameIndex], actions[actionIndex], wishes[wishIndex]);
}

int main() {
    // 랜덤 시드 설정
    srand(time(NULL));

    // 메시지 버퍼
    char message[100];

    // 메시지 생성
    generateMessage(message, sizeof(message));

    // 생성된 메시지 출력
    printf("%s\n", message);

    return 0;
}
