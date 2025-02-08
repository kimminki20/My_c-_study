//백준 2468 안전영역
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int board[101][101];
bool vis[101][101];
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N; // N*N의 칸으로 설정하기
    int maxHeight = 0; // 지역 내 최대 높이를 찾기 위한 변수

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            maxHeight = max(maxHeight, board[i][j]);
        }
    } // 지역의 높이를 모두 입력받고 최대 높이를 계산

    int mx = 0; // 최대 안전 영역 개수

    for (int h = 0; h <= maxHeight; h++) { // h는 물의 높이를 의미
        for (int i = 0; i < N; i++) {     // 2D 배열 초기화
            fill(vis[i], vis[i] + N, false);
        }
    //memset(vis,0,sizeof(vis)) 이렇게도 가능
    //void* memset(void* ptr, int value, size_t num);
        int area = 0; // 현재 물 높이에서의 안전 영역 개수
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] <= h || vis[i][j]) continue; // 물에 잠기거나 이미 방문한 지역은 무시
                area++;
                queue<pair<int, int>> Q;
                vis[i][j] = true;
                Q.push({i, j});

                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 경계 초과 검사
                        if (vis[nx][ny] || board[nx][ny] <= h) continue; // 이미 방문했거나 물에 잠긴 지역은 무시
                        vis[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        }

        mx = max(mx, area); // 최대 안전 영역 개수를 갱신
    }

    cout << mx;
    return 0;
}
