#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // memset 사용

using namespace std;

#define MAX 1000

int w, h; // 너비, 높이
char grid[MAX][MAX];
bool visited[MAX][MAX];
int fire_time[MAX][MAX]; // 불이 옮겨가는 시간을 판단
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(queue<pair<int, int>>& fire_q, queue<pair<int, int>>& sang_q) {
    memset(fire_time, -1, sizeof(fire_time)); // 초기값 -1 (불이 닿지 않은 곳)
    memset(visited, false, sizeof(visited));  // 방문 배열 초기화

    // 불 BFS (불의 확산 시간 계산)
    queue<pair<int, int>> temp_fire_q = fire_q;
    while (!temp_fire_q.empty()) {
        int fx = temp_fire_q.front().first;
        int fy = temp_fire_q.front().second;
        temp_fire_q.pop();
        fire_time[fx][fy] = 0; // 불의 시작 위치는 0으로 설정
    }

    while (!fire_q.empty()) {
        int fx = fire_q.front().first;
        int fy = fire_q.front().second;
        fire_q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] != '#' && fire_time[nx][ny] == -1) {
                fire_time[nx][ny] = fire_time[fx][fy] + 1;
                fire_q.push({nx, ny});
            }
        }
    }

    // 상근이 BFS
    int time = 0; // 탈출까지 걸린 시간
    visited[sang_q.front().first][sang_q.front().second] = true; // 방문 처리

    while (!sang_q.empty()) {
        int sz = sang_q.size(); // 현재 큐 크기 (같은 시간대에 방문할 모든 위치)
        while (sz--) {
            int sx = sang_q.front().first;
            int sy = sang_q.front().second;
            sang_q.pop();

            if (sx == 0 || sx == h - 1 || sy == 0 || sy == w - 1) { // 가장자리에 도달했다면 탈출 가능
                cout << time + 1 << '\n';
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = sx + dx[i];
                int ny = sy + dy[i];

                if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == '.' && !visited[nx][ny]) { 
                    if (fire_time[nx][ny] == -1 || fire_time[nx][ny] > time + 1) {
                        visited[nx][ny] = true;
                        sang_q.push({nx, ny});
                    }
                }
            }
        }
        time++; // 여기서 증가해야 정상적으로 시간 흐름이 반영됨
    }
    cout << "IMPOSSIBLE\n"; // 탈출 불가
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        cin >> w >> h;
        queue<pair<int, int>> fire_q, sang_q;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '*') {
                    fire_q.push({i, j});
                }
                if (grid[i][j] == '@') {
                    sang_q.push({i, j});
                }
            }
        }
        BFS(fire_q, sang_q);
    }
    return 0;
}
