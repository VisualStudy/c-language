#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

#define WIDTH 10 /**< 게임 영역의 가로 크기 */
#define HEIGHT 20 /**< 게임 영역의 세로 크기 */
#define POS_X 4 /**< 초기 블록 생성 위치의 X 좌표 */
#define POS_Y 2 /**< 초기 블록 생성 위치의 Y 좌표 */
#define DELAY 100 /**< 블록이 떨어지는 데 대기하는 시간(밀리초) */

// 함수 원형
void CursorVisible(bool blnCursorVisible); /**< [1] 커서의 가시성 설정 함수 */
void SetCursorPosition(int cursorLeft, int cursorTop); /**< [2] 커서 위치 설정 함수 */
COORD GetCursorPosition(void); /**< [3] 커서의 현재 위치 정보를 가져오는 함수 */
void ClearScreen(void); /**< [4] 화면을 지우고 커서를 (0, 0) 위치로 이동시키는 함수 */
void StartScreen(void); /**< [5] 게임 시작 화면 출력 함수 */
void StartGame(void); /**< [6] 게임을 시작하고 주요 로직을 처리하는 함수 */
int CreateBlock(void); /**< [7] 새 블록을 생성하는 함수 */
bool CanPositionedAt(int rotation, int move1, int move2); /**< [8] 블록이 위치할 수 있는지 확인하는 함수 */
void WriteBlock(int rotation); /**< [9] 현재 위치에 블록을 출력하는 함수 */
void PlaceBlockOnBoard(int n, int move1, int move2); /**< [10] 보드에 블록을 배치하는 함수 */
void DrawField(void); /**< [11] 게임 영역을 그리는 함수 */
void ClearBlock(int rotation, int move1, int move2); /**< [12] 현재 블록을 지우는 함수 */
void Stepper(int column); /**< [13] 블록을 이동하는 함수 */
void RemoveLine(void); /**< [14] 완성된 라인을 제거하고 점수를 계산하는 함수 */
void CountScore(void); /**< [15] 점수를 계산하는 함수 */
void ShowPoint(void); /**< [16] 점수를 출력하는 함수 */
void CheckGameWin(void); /**< [17] 게임 승리를 확인하는 함수 */
void EndScreen(void); /**< [18] 게임 종료 화면 출력하는 함수 */

/**
 * @brief 테트리스 게임에서 사용자 입력으로 받아들일 키의 상수값들을 정의한 열거형.
 *
 * 각 키는 해당 키보드 키의 ASCII 값에 해당합니다.
 */
enum Key
{
    UP = 72, /**< 위쪽 화살표 키 */
    DOWN = 80, /**< 아래쪽 화살표 키 */
    LEFT = 75, /**< 왼쪽 화살표 키 */
    RIGHT = 77, /**< 오른쪽 화살표 키 */
    SPACE = 32, /**< 스페이스바 키 */
    ENTER = 10 /**< 엔터 키 */
};

static int _; /**< 불필요한 값을 받아 저장하는 더미 변수 */
static int _level = 1; /**< 현재 게임 레벨(1부터 10까지 가능) */
static int _points = 0; /**< 사용자의 현재 점수 */
static int _speed = 300; /**< 게임의 현재 속도(밀리초 단위) */

// 게임 블록이 표시되는 2D 컨테이너
int _container[HEIGHT + 1][WIDTH + 2] = { 0, }; /**< 2차원 게임 영역 컨테이너, 0은 블록이 없음을, 1은 블록이 있음을 나타냄 */

// 콘솔 테트리스 게임에서 사용되는 7개의 블록 모양을 4개의 회전 상태로 표현한 배열
// 각 블록은 4x4 크기의 그리드 안에 표현되며, 1은 블록이 존재함을 나타냅니다.
int _blocks[28][4][4] =
{
    // 0: I (막대 모양)
    // #### -> 0번째 인덱스가 기준 블록
    {
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 1, 1, 1 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 1, 1, 1 },
        { 0, 0, 0, 0 }
    },

    // 1: O (사각형 모양)
    // ## -> 4번째 인덱스가 기준 블록
    // ##
    {
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },

    // 2: T (T자 모양)
    //  #  -> 8번째 인덱스가 기준 블록
    // ###
    {
        { 0, 0, 0, 0 },
        { 0, 1, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 1, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 1, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 0, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 1, 0, 0 }
    },

    // 3: S
    //  ## -> 12번째 인덱스가 기준 블록
    // ##
    {
        { 0, 0, 0, 0 },
        { 0, 1, 1, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 0, 1, 1, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 0 }
    },

    // 4: Z
    // ##   -> 16번째 인덱스가 기준 블록
    //  ##
    {
        { 0, 0, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 0, 1, 0 },
        { 0, 1, 1, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 1, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },

    // 5: J
    // ###  -> 20번째 인덱스가 기준 블록
    //   #
    {
        { 0, 0, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 0, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 1, 0, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 1, 1, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 0, 0 }
    },

    // 6: L
    // ###   -> 24번째 인덱스가 기준 블록
    // #
    {
        { 0, 0, 0, 0 },
        { 1, 1, 1, 0 },
        { 1, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 1, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 0, 0, 0 },
        { 0, 0, 1, 0 },
        { 1, 1, 1, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 }
    }
}; // end _blocks[][][]

//[1] 커서 보이기/숨기기: true(보이기), false(숨기기)
/**
 * @brief 커서를 보이거나 숨기는 함수
 *
 * 이 함수는 windows API를 사용하여 콘솔에서 커서의 가시성을 제어합니다.
 * 커서를 보이게 하려면 true를, 숨기려면 false를 매개변수로 전달하면 됩니다.
 *
 * @param blnCursorVisible 커서를 보이게 하려면 true, 숨기려면 false
 */
void CursorVisible(bool blnCursorVisible)
{
    CONSOLE_CURSOR_INFO info; // 커서 정보를 저장할 구조체 선언

    // 현재 커서 정보를 가져옴
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    // 커서의 가시성을 설정함
    info.bVisible = blnCursorVisible;

    // 설정된 커서 정보를 적용함
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

//[2] 콘솔 내의 커서 위치 설정: 예전 Turbo C에서는 gotoxy(x, y)
/**
 * @brief 콘솔 내의 커서 위치를 설정하는 함수
 *
 * 이 함수는 Windows API를 사용하여 콘솔의 커서 위치를 설정합니다.
 * 설정하려는 커서의 좌표를 매개변수로 전달하면 됩니다.
 *
 * @param cursorLeft 설정할 커서의 X 좌표
 * @param cursorTop 설정할 커서의 Y 좌표
 */
void SetCursorPosition(int cursorLeft, int cursorTop)
{
    COORD pos = { cursorLeft, cursorTop }; // 콘솔 창의 좌표를 나타내는 구조체 생성
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 커서 위치 설정
}

//[3] 커서의 현재 위치 정보 얻기
/**
 * @brief 커서의 현재 위치 정보를 얻는 함수
 *
 * 이 함수는 Windows API를 사용하여 현재 콘솔의 커서 위치를 얻어옵니다.
 * 함수의 반환 값은 커서의 현재 위치를 나타내는 COORD 구조체입니다.
 *
 * @return 현재 커서의 위치를 나타내는 COORD 구조체
 */
COORD GetCursorPosition(void)
{
    COORD cursor; // 현재 커서의 위치를 저장할 COORD 구조체 선언
    CONSOLE_SCREEN_BUFFER_INFO cursorInfo; // 콘솔 스크린 버퍼 정보를 저장할 구조체 선언

    // 콘솔 스크린 버퍼 정보를 얻어 cursorInfo 구조체에 저장
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    // 현재 커서 위치를 cursor 구조체에 저장
    cursor.X = cursorInfo.dwCursorPosition.X;
    cursor.Y = cursorInfo.dwCursorPosition.Y;

    return cursor; // 현재 커서 위치를 나타내는 COORD 구조체 반환
} // end GetCursorPosition()

//[4] 화면 지우고 커서를 (0, 0) 위치로 이동
/**
 * @brief 화면을 지우고 커서를 (0, 0) 위치로 이동하는 함수
 *
 * 이 함수는 콘솔의 화면을 지우고 커서의 위치를 (0, 0)으로 이동시킵니다.
 * 이 작업은 콘솔 화면의 내용을 초기화하고 커서를 화면의 시작점으로 이동하는 데 사용됩니다.
 */
void ClearScreen()
{
    system("cls"); // 콘솔 창의 화면을 지움
    CursorVisible(false); // 커서 숨기기
    SetCursorPosition(0, 0); // 커서의 좌표를 (0, 0)으로 설정
}

//[5] 시작 화면
/**
 * @brief 게임의 시작 화면을 출력하는 함수
 *
 * 이 함수는 게임의 시작 화면을 출력하고, 사용자의 키 입력을 기다립니다.
 * 키 입력이 있으면 게임이 시작됩니다.
 */
void StartScreen()
{
    printf(
        " C언어 콘솔 테트리스\n\n"
        "======================================\n"
        " 조작법: \n"
        "======================================\n"
        " [→]\t\t블록을 오른쪽으로 이동\n"
        " [←]\t\t블록을 왼쪽으로 이동\n"
        " [↑]\t\t블록을 왼쪽으로 회전하기\n"
        " [↓]\t\t블록을 아래로 1칸 내리기\n"
        " [Space]\t블록을 아래로 떨어뜨리기\n"
        "======================================\n\n"
        "아무키나 누르면 시작됩니다.\n"
    );

    _getch(); // 사용자의 키 입력을 받음
}

//[6] 게임 시작 및 주요 로직 처리 함수
/**
 * @brief 게임을 시작하고 주요 로직을 처리하는 함수
 *
 * 이 함수는 게임의 시작부터 종료까지 주요 로직을 반복적으로 처리합니다.
 * 이 함수 안에서 블록 생성, 게임 승리 체크, 블록 이동 및 회전 등의 작업이 이루어집니다.
 */
void StartGame(void)
{
    int n;
    int kb;
    int c = 2;

    // 게임 시작부터 종료까지 반복
    while (1)
    {
        // 블록 생성 위치 좌표(13, 2)에서 시작
        SetCursorPosition(13, 2);

        n = CreateBlock(); // 블록 인덱스 생성 함수 호출

        CheckGameWin(); // 게임 승리 처리 함수 호출

        // 블록이 더 이상 놓일 수 없는 경우 게임 종료
        if (CanPositionedAt(n, 0, 0) == false)
            break; //게임 끝                       

        // 블록 한 칸 위에서부터 아래로 이동하는 로직
        while (1)
        {
            int blockReachedBottom = 0;
            int k = 0;

            /*블록 아래로 이동*/
            while (!_kbhit())
            {
                //블록 쇼
                WriteBlock(n);
                // 딜레이 타임
                Sleep(DELAY + _speed);
                //아래이동시 1있는지 확인
                if (CanPositionedAt(n, 0, 1) == false)
                {
                    blockReachedBottom = 1;
                    PlaceBlockOnBoard(n, 0, 0);//보드 벽돌 배열 1추가
                    RemoveLine();
                    break;
                }
                ClearBlock(n, 0, 1);  //board배열 +1행
            }
            /*CanPositionedAt함수에서 배열값 1발견시 중지*/
            if (blockReachedBottom == 1)
                break;

            kb = _getch(); // 키보드 입력을 받음

            /*방향키 처리*/
            switch (kb)
            {
            case LEFT:
                // 블록을 왼쪽으로 이동
                ClearBlock(n, -2, 0); // -1로 넣고 차이점 확인하세요.
                WriteBlock(n);
                break;
            case RIGHT:
                // 블록을 오른쪽으로 이동
                ClearBlock(n, 2, 0); // 1로 넣고 차이점 확인하세요.
                WriteBlock(n);
                break;
            case UP:
                // 블록을 회전
                k = n / 4;
                k *= 4;

                // 다음 회전 상태로 전환
                if ((n + 1) <= (k + 3))
                {
                    k = n + 1;
                }

                // 회전이 가능한지 확인
                if (CanPositionedAt(k, 0, 0) == true)
                {
                    ClearBlock(n, 0, 0);
                    n = k;
                    WriteBlock(n);
                    break;
                }
                break;
            case DOWN:
                // 블록을 아래로 이동
                ClearBlock(n, 0, 2);
                break;
            case SPACE:// 스페이스바 누르면 블록이 아래로 떨어지는 로직
                while (1)
                {
                    ClearBlock(n, 0, 1);
                    if (CanPositionedAt(n, 0, 1) == false)
                    {
                        WriteBlock(n);
                        PlaceBlockOnBoard(n, 0, 0);
                        break;
                    }
                }
            default: break;
            } // end switch
        } // end while(블록)          
    } // end while(게임)
}

//[7] 블록 생성 함수
/**
 * @brief 무작위 블록을 생성하는 함수
 *
 * 이 함수는 0~6 사이의 난수를 생성하여 해당 인덱스의 블록을 생성합니다.
 *
 * @return 생성된 블록의 인덱스
 */
int CreateBlock(void)
{
    int blockIndex;

    // 0~6까지의 인덱스 생성: 블록 종류 결정
    // 이 인덱스는 다음과 같은 블록을 나타냅니다.
    // 0: I, 1: O, 2: T, 3: S, 4: Z, 5: J, 6: L
    blockIndex = rand() % 7;

    // 각 블록의 첫번째 블록(0, 4, 8, 12, 16, 20, 24)을 기준으로 출력
    // 예를 들어, blockIndex가 2이면 T 블록을 생성하고 싶다면,
    // T 블록의 첫 번째 좌표가 8인 위치를 찾아야 합니다.
    blockIndex = blockIndex * 4;

    return blockIndex;
}

//[8] 사용 가능 위치 체크
/**
 * @brief 사용 가능한 위치인지 체크하는 함수
 *
 * 이 함수는 현재 회전 상태의 블록이 이동하려는 위치에 들어갈 수 있는지 확인합니다.
 *
 * @param rotation 현재 회전 상태
 * @param move1 X 좌표 이동 값
 * @param move2 Y 좌표 이동 값
 * @return 사용 가능한 위치면 true, 그렇지 않으면 false
 */
bool CanPositionedAt(int rotation, int move1, int move2)
{
    int x, y;
    int arrX, arrY; // 배열 좌표 저장
    COORD pos = GetCursorPosition();

    arrX = pos.X + move1; // 콘솔 상의 x 좌표에 이동 값을 더함
    arrY = pos.Y + move2; // 콘솔 상의 y 좌표에 이동 값을 더함

    arrX = (arrX / 2) - 2; // 배열 상의 x 좌표로 변환
    arrY = arrY - POS_Y; // 배열 상의 y 좌표로 변환

    // 4x4 블록 배열을 순회하면서 겹치는지 확인
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            // 현재 회전 상태의 블록이 1(존재)이고, container에도 블록이 있는 경우
            if ((_blocks[rotation][y][x] == 1) && _container[arrY + y][arrX + x] == 1)
                return false; // 겹친다고 판단하고 false 반환
        }
    }
    return true; // 겹치지 않는다고 판단하고 true 반환
}

//[9] 현재 위치에 블록 출력
/**
 * @brief 현재 위치에 블록을 출력하는 함수
 *
 * 이 함수는 현재 회전 상태의 블록을 화면에 출력합니다.
 * 블록이 출력 가능한 위치에 있어야 출력됩니다.
 *
 * @param rotation 현재 회전 상태
 */
void WriteBlock(int rotation)
{
    int i, j;
    COORD cursor = GetCursorPosition();

    if (CanPositionedAt(rotation, 0, 0) == true)
    {
        //콘솔창위치 설정, 배열값에서 1은 ■출력, 0은 출력없음
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)// 열 반복
            {
                SetCursorPosition(cursor.X + (j * 2), cursor.Y + i);
                if (_blocks[rotation][i][j] == 1)
                {
                    printf("■");
                }
            }
        }
        SetCursorPosition(cursor.X, cursor.Y);
    }
}

//[10] PlaceBlockOnBoard 함수
/**
 * @brief 보드판에 블록을 배치하고 초기화하는 함수
 *
 * 이 함수는 지정된 블록을 게임 보드에 배치하고, 해당 위치에 블록이 있다는 것을 나타내는
 * _container 배열을 업데이트합니다.
 *
 * @param n 배치하려는 블록의 인덱스
 * @param move1 초기 열 위치 조정
 * @param move2 초기 행 위치 조정
 */
void PlaceBlockOnBoard(int n, int move1, int move2)
{
    COORD pos = GetCursorPosition(); // 현재 커서 위치를 가져옴

    int arrX = pos.X + move1; // 콘솔 좌표를 열 위치로 변환
    int arrY = pos.Y + move2; // 콘솔 좌표를 행 위치로 변환
    int x, y;

    // 커서 위치 정보를 배열 위치 정보로 변경
    arrX = arrX / 2 - 2; // 콘솔 좌표를 배열 열 위치로 변환
    arrY = arrY - 2;     // 콘솔 좌표를 배열 행 위치로 변환

    // 보드판에서 블록 이동 시 1인식
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            // 현재 블록 위치가 1인 경우, _container에 블록 배치
            if (_blocks[n][y][x] == 1)
            {
                _container[arrY + y][arrX + x] = 1;
            }
        }
    }
}

//[11] 게임 영역에 대한 그리기 함수
/**
 * @brief 게임 영역의 테두리를 그리는 함수
 *
 * 이 함수는 게임 영역의 왼쪽, 오른쪽, 하단 테두리를 그립니다.
 * 이 작업은 게임의 플레이 영역을 사용자에게 표시하는 데 사용됩니다.
 */
void DrawField()
{
    // 왼쪽 라인 그리기
    for (int y = 0; y < HEIGHT + 1; y++)
    {
        _container[y][0] = 1; // 블록이 있음을 표시
        SetCursorPosition(POS_X, POS_Y + y);
        printf(" □"); // 원하는 테두리 모양 사용
    }
    // 오른쪽 라인 그리기
    for (int y = 0; y < HEIGHT + 1; y++)
    {
        _container[y][WIDTH + 1] = 1; // 블록이 있음을 표시
        SetCursorPosition(POS_X + (WIDTH + 1) * 2, POS_Y + y);
        printf(" □");
    }
    // 아래 라인 그리기
    for (int x = 1; x < WIDTH + 1; x++)
    {
        _container[HEIGHT][x] = 1; // 블록이 있음을 표시
        SetCursorPosition(POS_X + x * 2, POS_Y + HEIGHT);
        printf(" □");
    }
} // end DrawField()

//[12] 현재 블록 클리어
/**
 * @brief 현재 블록을 화면에서 지우는 함수
 *
 * 이 함수는 블록을 이동하거나 회전하기 전에 현재 블록을 화면에서 지웁니다.
 *
 * @param rotation 현재 블록의 회전 상태
 * @param move1 X 좌표 이동 값
 * @param move2 Y 좌표 이동 값
 */
void ClearBlock(int rotation, int move1, int move2)
{
    int x, y;

    COORD cursor = GetCursorPosition(); // 현재 커서 위치를 얻음

    // 블록이 회전하거나 이동할 수 있는지 확인
    if (CanPositionedAt(rotation, move1, move2) == true)
    {
        // 4x4 블록의 모든 셀을 순회하면서
        for (y = 0; y < 4; y++)
        {
            for (x = 0; x < 4; x++)
            {
                // 해당 셀에 블록이 존재하면
                if (_blocks[rotation][y][x] == 1)
                {
                    // 커서 위치를 이동시키고 블록을 지움
                    SetCursorPosition(cursor.X + (x * 2), cursor.Y + y);
                    printf("  "); // 스페이스 두 칸
                }
            }
        }
        // 커서 위치를 이동할 위치로 변경
        SetCursorPosition(cursor.X + move1, cursor.Y + move2);
    }
} // end ClearBlock()

//[13] 배열, 블록 옮김
/**
 * @brief 완성된 줄을 제거하고, 그 위의 줄들을 한 칸씩 아래로 이동시키는 함수
 *
 * 이 함수는 완성된 줄을 제거하고, 그 위의 줄들을 한 칸씩 아래로 이동시킵니다.
 * 이동 후에는 게임 보드를 다시 그립니다.
 *
 * @param column 줄을 제거할 컬럼
 */
void Stepper(int column)
{
    int y, x;

    // 게임 보드의 행을 위쪽에서 아래쪽으로 이동시키는 반복문
    for (y = column; y >= 0; y--)
    {
        for (x = 1; x <= 10; x++)
        {
            _container[y][x] = _container[y - 1][x]; // 현재 행의 값을 바로 위 행의 값으로 설정
        }
    }

    // 게임 보드의 맨 위쪽 행(0행)에 0을 삽입하여 새로운 빈 공간을 만드는 반복문
    for (x = 1; x <= 10; x++)
    {
        _container[0][x] = 0;
    }

    // 수정된 게임 보드를 화면에 출력하는 반복문
    for (y = 1; y <= 19; y++)
    {
        for (x = 1; x <= 10; x++)
        {
            SetCursorPosition((POS_X)+x * 2 + 1, y + POS_Y);
            if (_container[y][x] == 1)
                printf("■"); // 블록이 있는 경우 출력
            else
                printf("  "); // 블록이 없는 경우 공백 출력(스페이스 두 칸)
        }
    }
}

//[14] 라인이 완성되면 삭제하고, 라인 위의 블록을 내린 후 점수를 계산하는 함수
/**
 * @brief 완성된 라인을 제거하고, 그 위의 블록들을 내리는 함수
 *
 * 이 함수는 완성된 모든 라인을 검사하여 제거하고, 그 위의 블록들을 내립니다.
 * 그런 다음 점수를 계산하고 게임 필드를 다시 그립니다.
 */
void RemoveLine(void)
{
    int i;
    int x, y;
    int z = 0;

    // 19행부터 시작해서 1행까지 반복
    for (y = 19; y >= 1; y--)
    {
        //행기준으로 4번 반복 (한 라인이 사라지면 라인 위의 블록들이 내려오기 때문에 여러 라인을 동시에 검사)
        for (z = 0; z < 4; z++)
        {
            i = 0;
            //1열부터 10열까지 증가
            for (x = 1; x < 11; x++)
            {
                //행기준으로 블록이 있는지 확인
                if (_container[y][x] == 1)
                {
                    i++;
                    //1이 10개면 행 블록 삭제 (한 행이 꽉 찼을 때)
                    if (i == 10)
                    {
                        for (x = 1; x < 11; x++)
                        {
                            SetCursorPosition((x + 2) * 2, y + 2);
                            printf("  "); // 블록을 지움(스페이스 두 칸)
                        }
                        //행 기준으로 블록 내리기 (사라진 라인 위의 블록들을 한 칸씩 아래로 내림)
                        CountScore(); // 점수 계산
                        Stepper(y); // 블록을 내리는 함수 호출
                    } // end if
                } // end if
            }
        }
    } // end for

    DrawField(); // 게임 필드를 다시 그림
} // end RemoveLine()

//[15] 레벨 스코어 계산
/**
 * @brief 점수를 계산하고, 레벨 및 게임 속도를 조절하는 함수
 *
 * 이 함수는 한 줄을 제거할 때마다 호출되어 점수를 증가시키고,
 * 필요한 경우 레벨을 증가시키고 게임 속도를 조절합니다.
 */
void CountScore(void)
{
    _points += 10; // 점수 10점 증가
    if (_points % 30 == 0) // 점수가 30의 배수일 때
    {
        _level += 1;       // 레벨 1 증가
        _speed -= 30;      // 레벨 1증가시마다 스피드는 30 밀리초 빨라짐
    }
    ShowPoint(); // 점수 및 레벨 표시를 업데이트하는 함수 호출
} // end CountScore()

//[16] 점수 출력 화면
/**
 * @brief 점수를 화면에 출력하는 함수
 *
 * 이 함수는 현재 게임의 단계와 점수를 화면에 출력합니다.
 * 이 정보는 게임의 진행 상황을 사용자에게 표시하는 데 사용됩니다.
 */
void ShowPoint()
{
    SetCursorPosition(32, 3);
    printf("C언어 콘솔 테트리스");
    SetCursorPosition(32, 5);
    printf("단계: %d 단계", _level);
    SetCursorPosition(32, 7);
    printf("점수: %d 점", _points);
}

// [17] 게임 승리 체크 함수
/**
 * @brief 게임 승리 조건을 체크하는 함수
 *
 * 이 함수는 게임의 레벨이 10에 도달했는지 확인하여 게임 승리 조건을 체크합니다.
 */
void CheckGameWin(void)
{
    if (_level == 10) // 레벨이 10에 도달하면 게임 승리
    {
        SetCursorPosition(32, 15); // 커서 위치를 (32, 15)로 이동하여 출력 위치 설정
        printf("게임 클리어"); // "게임 클리어" 메시지 출력하여 사용자에게 게임 승리 상황 알림
        _ = getchar(); // 사용자의 입력을 기다림 (키보드의 아무 키나 누르면 계속 진행). 이를 통해 사용자가 승리 화면을 확인할 수 있는 시간 제공
        exit(1); // 프로그램 종료 (1은 정상 종료를 나타냄). 게임 승리 조건 충족 시 프로그램을 종료하여 메인 메뉴로 돌아가지 않음
    }
}

//[18] 게임 종료 화면
/**
 * @brief 게임의 종료 화면을 출력하는 함수
 *
 * 이 함수는 게임의 종료 화면을 출력하고, 사용자의 키 입력을 기다립니다.
 * 키 입력이 있으면 프로그램이 종료됩니다.
 */
void EndScreen(void)
{
    SetCursorPosition(32, 14);
    printf("게임 종료");
    SetCursorPosition(32, 16);
    printf("아무키나 누르면 종료됩니다.");

    _getch(); // 사용자의 키 입력을 받음
}

/**
 * 메인 함수
 */
int main(void)
{
    // 난수 초기화
    // 프로그램 실행 시 한 번만 호출하여 랜덤한 블록 생성을 위한 준비
    srand((unsigned)time(0));

    // 시작 화면을 표시
    StartScreen();

    // 화면을 지우고 커서 위치 초기화
    ClearScreen();

    // 테트리스 게임판을 그림
    DrawField();

    // 현재 점수를 게임 화면에 표시
    ShowPoint();

    // 테트리스 게임 로직이 실행
    StartGame();

    // 게임 종료 후, 게임 결과 화면 출력
    EndScreen();

    // 화면을 지우고 커서 위치 초기화
    ClearScreen();

    return 0;
}