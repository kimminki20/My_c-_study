//백준 2636 치즈
#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // memset 사용

#define MAX 1001
using namespace std;

int cheese[MAX][MAX]; // 치즈 배열
int visited[MAX][MAX]; // 방문 여부 체크
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int row, col; // 치즈 판 크기

// BFS로 외부 공기 탐색 & 치즈 녹이기
bool BFS() {
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited)); // 방문 배열 초기화

    q.push({0, 0});
    visited[0][0] = 1; // 외부 공기 방문 처리

    vector<pair<int, int>> meltList; // 녹일 치즈 리스트

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue; // 범위 체크
            if (visited[nx][ny]) continue; // 이미 방문한 곳은 스킵

            if (cheese[nx][ny] == 1) {
                // 치즈라면 녹일 대상에 추가하고 방문 표시
                meltList.push_back({nx, ny});
                visited[nx][ny] = 1;
            } else {
                // 공기라면 계속 탐색
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }

    // 치즈 녹이기
    for (auto [x, y] : meltList) {
        cheese[x][y] = 0;
    }

    return !meltList.empty(); // 녹일 치즈가 있다면 true, 없으면 false
}

int main() {
    cin >> row >> col;

    int total_cheese = 0; // 전체 치즈 개수
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> cheese[i][j];
            if (cheese[i][j] == 1) total_cheese++;
        }
    }

    int time = 0; // 치즈가 녹는 데 걸리는 시간
    int last_cheese = total_cheese; // 마지막 남은 치즈 개수

    while (total_cheese > 0) {
        time++;
        last_cheese = total_cheese;

        if (!BFS()) break; // BFS 실행 (치즈 녹이기)

        // 남은 치즈 개수 업데이트
        total_cheese = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (cheese[i][j] == 1) total_cheese++;
            }
        }
    }

    cout << time << "\n" << last_cheese << "\n";
    return 0;
}
