#include <iostream>
#include <queue>

using namespace std;

int grid[101][101];
int visit[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N;

// 일반 BFS 함수
void BFS(int x, int y, bool colorblind) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = 1;

    int current_color = grid[x][y];

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        /* 
        pair<int, int> current = q.front();
        q.pop();
        int cx = current.first;
        int cy = current.second;
        */

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
                // 적록색약일 경우, R과 G를 동일한 색으로 취급
                if (colorblind) {
                    if ((current_color == 1 || current_color == 3) && 
                        (grid[nx][ny] == 1 || grid[nx][ny] == 3)) {
                        visit[nx][ny] = 1;
                        q.push({nx, ny});
                    } else if (grid[nx][ny] == current_color) {
                        visit[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                // 정상인일 경우
                else {
                    if (grid[nx][ny] == current_color) {
                        visit[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    char s;
    cin >> N;

    // 입력 처리
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> s;
            if (s == 'R') {
                grid[i][j] = 1; // R을 1로 저장
            } else if (s == 'B') {
                grid[i][j] = 2; // B를 2로 저장
            } else {
                grid[i][j] = 3; // G를 3로 저장
            }
        }
    }

    int count1 = 0; // 정상인 기준 구역 수
    int count2 = 0; // 적록색약 기준 구역 수

    // 정상인 기준 BFS 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                BFS(i, j, false);
                count1++;
            }
        }
    }

    // 방문 배열 초기화
    fill(&visit[0][0], &visit[0][0] + 101 * 101, 0);

    // 적록색약 기준 BFS 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                BFS(i, j, true);
                count2++;
            }
        }
    }

    cout << count1 << " " << count2 << endl;

    return 0;
}
