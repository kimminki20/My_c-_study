#include <iostream>
#include <vector>

using namespace std;

int visit[51][51] = {0}; // 방문 여부 확인
int field[51][51] = {0}; // 배추밭 정보
int dx[4] = {0, 0, -1, 1}; // 상하좌우 움직임
int dy[4] = {1, -1, 0, 0};
int M, N, K; // 밭의 크기와 배추의 개수

void dfs(int x, int y) {
    visit[x][y] = 1; // 현재 위치 방문 표시
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 유효 범위 확인 및 방문 여부 확인
        if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visit[nx][ny] && field[nx][ny] == 1) {
            dfs(nx, ny); // 인접한 배추 탐색
        }
    }
}

int main() {
    int T; // 테스트 케이스 수
    cin >> T;

    while (T--) {
        cin >> M >> N >> K; // 밭 크기와 배추 개수 입력
        // 초기화
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                visit[i][j] = 0;
                field[i][j] = 0;
            }
        }
        // 배추 위치 입력
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }
        int count = 0; // 구역의 개수
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] == 1 && !visit[i][j]) {
                    dfs(i, j); // 새로운 구역 탐색
                    count++;
                }
            }
        }
        cout << count << endl; // 결과 출력
    }

    return 0;
}
