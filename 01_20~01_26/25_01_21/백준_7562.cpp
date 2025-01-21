//백준 7562 나이트의 이동
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> // fill 사용을 위해 추가
#define X first
#define Y second
using namespace std;

int board[304][304];
bool vis[304][304];
int dist[304][304]; // 최단 거리를 저장

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; // 나이트의 이동 방향
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int N;
        cin >> N; // 체스판의 크기
        for (int i = 0; i < N; i++) {   // 배열 초기화
            fill(vis[i], vis[i] + N, false);
            fill(dist[i], dist[i] + N, 0);
        }

        int current_x, current_y; // 현재 나이트의 위치
        int move_x, move_y;       // 목표 위치
        cin >> current_x >> current_y;
        cin >> move_x >> move_y;

        if (current_x == move_x && current_y == move_y) {
            cout << 0 << "\n";
            continue;
        }

        queue<pair<int, int>> Q; // BFS를 위한 큐
        vis[current_x][current_y] = true; // 시작점 방문 처리
        Q.push({current_x, current_y});

        bool found = false; // 목표 위치 도달 여부 플래그

        while (!Q.empty() && !found) {
            pair<int, int> cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 범위 밖
                if (vis[nx][ny]) continue; // 이미 방문한 곳

                vis[nx][ny] = true;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;

                if (nx == move_x && ny == move_y) {
                    cout << dist[nx][ny] << "\n";
                    found = true;
                    break;
                }
                Q.push({nx, ny});
            }
        }
    }
    return 0;
}
