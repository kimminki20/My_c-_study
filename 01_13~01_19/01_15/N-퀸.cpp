//코테합격자되기편 N-퀸 문제
//체스의 퀸을 N*N 체스판에 N개 배치했을 떄 서로 공격할 수 없는 위치에 놓을 수 있는 방법 찾기
//이 문제를 완전 탐색으로 풀면 모든 경우를 확인해야하기에 O(N^N)이 되기에 시간복잡도가 너무 높음 -> 백트래킹으로 생각해보기
// 유망함수: 여왕이 추가될 때 마다 행이나, 대각선 방향에 겹치는 여왕이 있으면 더 이상 탐색x
/*문제: 가로,세로 길이가 N인 정사각형 체스판이 있음, 체스판 위의 N개의 퀸이 서로를 공격할 수 없도록 배치하고싶음
  체스판의 길이가 주어지는 경우 퀸 배치 수를 반환하는 solution()함수.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 주어진 두 행이 같은지 확인하는 함수 (퀸이 같은 행에 놓였는지 확인)
bool isSameRow(int placeRow, int currentRow){ 
    return placeRow == currentRow;
}

// 주어진 두 위치가 대각선 상에 있는지 확인하는 함수
// 대각선에 놓여있는 경우 두 위치의 행 차이와 열 차이가 동일
bool isDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow){ 
    return abs(placedCol - currentCol) == abs(placedRow - currentRow);
}

// 주어진 퀸 배치에서 (col, row)에 퀸을 배치할 수 있는지 확인하는 함수
// 같은 행에 퀸이 이미 있거나 대각선에 퀸이 있으면 배치 불가능
bool isSafePosition(const vector<int> &queen, int col, int row){ 
    for(int i = 0; i < col; i++){ // 현재까지 배치된 퀸들을 확인
        if(isSameRow(queen[i], row) || isDiagonalAttack(i, queen[i], col, row)){
            return false; // 퀸이 같은 행에 있거나 대각선에 있으면 안전하지 않음
        }
    }
    return true; // 모든 검사에서 문제가 없으면 안전하게 배치 가능
}

// 퀸을 배치하는 함수 (백트래킹)
long long placeQueens(vector<int> &queen, int col){ 
    int n = queen.size();
    // 모든 퀸을 배치한 경우, 즉 마지막 열에 도달했을 때
    if(col == n){
        return 1; // 하나의 유효한 배치가 완성되었으므로 1을 반환
    }
    long long count = 0; // 가능한 배치의 수를 세는 변수
    // 현재 열(col)에 퀸을 배치할 수 있는 모든 행(row)을 탐색
    for(int row = 0; row < n; ++row){ 
        if(isSafePosition(queen, col, row)){ // 해당 위치에 퀸을 배치할 수 있으면
            queen[col] = row; // 퀸을 현재 열에 배치
            count += placeQueens(queen, col + 1); // 다음 열로 재귀 호출하여 퀸 배치
            queen[col] = -1; // 백트래킹: 퀸을 현재 위치에서 제거
        }
    }
    return count; // 가능한 배치의 수 반환
}

// N-퀸 문제의 메인 함수
long long solution(int n){
    vector<int> queen(n, -1); // 퀸의 배치 상태를 저장하는 벡터, 초기값 -1 (배치 안됨)
    
    // 첫 번째 열(0열)부터 퀸을 배치하는 함수 호출
    return placeQueens(queen, 0); // 가능한 퀸 배치의 수를 반환
}

int main(){
    int N; // 체스판의 크기 N
    cin >> N; // 사용자로부터 N값 입력받기
    cout << solution(N) << endl; // N-퀸 문제의 가능한 배치 수 출력
}
