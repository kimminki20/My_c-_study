#include <iostream>
#include <queue>
#include <tuple> // for using tuple with x, y, day

using namespace std;

int tomato[1001][1001];
int dx[4] = {0, 0, -1, 1}; // 좌우
int dy[4] = {1, -1, 0, 0}; // 상하

int main() {
    int M, N;
    cin >> M >> N; // 가로 M, 세로 N
    
    queue<tuple<int, int, int>> q; // x, y, day
    int unripe = 0; // 익지 않은 토마토의 개수

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                q.push({i, j, 0}); // 익은 토마토 위치와 초기 날짜 추가
            } else if (tomato[i][j] == 0) {
                unripe++; // 익지 않은 토마토 개수 증가
            }
        }
    }

    int days = 0;
    while (!q.empty()) {
        int x, y, day;
        tie(x, y, day) = q.front();
        q.pop();

        days = max(days, day); // 최대 일수를 갱신

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && tomato[nx][ny] == 0) {
                tomato[nx][ny] = 1; // 익은 상태로 변경
                unripe--; // 익지 않은 토마토 개수 감소
                q.push({nx, ny, day + 1}); // 다음 위치와 날짜 추가
            }
        }
    }

    if (unripe > 0) {
        cout << -1 << endl; // 모두 익지 못한 경우
    } else {
        cout << days << endl; // 최소 날짜 출력
    }

    return 0;
}
