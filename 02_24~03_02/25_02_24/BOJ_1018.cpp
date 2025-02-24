#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

// 8x8 체스판 패턴(WB로 시작하는 경우)
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

// 8x8 체스판 패턴(BW로 시작하는 경우)
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

// 입력받을 보드판
string board[50];

// WB 패턴과 비교하여 다시 칠해야 하는 개수를 반환
int WB_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != WB[i][j]) // WB 패턴과 다른 경우 개수 증가
                cnt++;
        }
    }
    return cnt;
}

// BW 패턴과 비교하여 다시 칠해야 하는 개수를 반환
int BW_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != BW[i][j]) // BW 패턴과 다른 경우 개수 증가
                cnt++;
        }
    }
    return cnt;
}

int main() {
    int size[2]; // 보드의 크기를 저장하는 배열
    int cnt; // 다시 칠해야 하는 칸의 개수를 저장하는 변수
    int min_val = 12345; // 최소 변경 개수를 저장할 변수 (충분히 큰 값으로 초기화)
    pair<int, int> p1; // 보드 크기를 저장할 pair 변수
    
    cin >> p1.first >> p1.second; // 보드 크기 입력
    
    for(int i = 0; i < p1.first; i++)
        cin >> board[i]; // 보드의 상태 입력
    
    // 8x8 크기의 부분 보드를 선택하여 검사
    for(int i = 0; i + 8 <= p1.first; i++)
    {
        for(int j = 0; j + 8 <= p1.second; j++)
        {
            int tmp;
            tmp = min(WB_cnt(i,j), BW_cnt(i,j)); // 두 패턴 중 최소 변경 개수 선택
            if(tmp < min_val) {
                min_val = tmp; // 최소 변경 개수 갱신
            }
        }
    }
    
    cout << min_val; // 최소 변경 개수 출력
    return 0;
}
