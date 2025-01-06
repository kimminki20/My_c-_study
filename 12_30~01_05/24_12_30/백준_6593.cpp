#include <iostream>
#include <queue>
#include <tuple>

int building[31][31][31];
int visit[31][31][31] = {0,};
int L, R, C; // L은 빌딩 층수, R과 C는 한 층의 행과 열의 개수
int dx[6] = {0, 0, -1, 1, 0, 0}; // 서, 동쪽
int dy[6] = {-1, 1, 0, 0, 0, 0}; // 남, 북쪽
int dz[6] = {0, 0, 0, 0, -1, 1}; // 아래, 위
int start_point_x, start_point_y, start_point_z;
int end_point_x, end_point_y, end_point_z;

using namespace std;

bool escape_found = false; // 탈출 여부를 기록하는 변수

void BFS(int i, int j, int k) {
    queue<tuple<int, int, int, int>> q; // 큐에 (z, x, y, 시간) 정보를 저장 
    q.push({i, j, k, 0}); // 시작점은 시간 0
    visit[i][j][k] = 1;

    while (!q.empty()) {
        int z, x, y, time;
        tie(z, x, y, time) = q.front();
        q.pop();
        if (z == end_point_z && x == end_point_x && y == end_point_y) {
            cout << "Escaped in " << time << " minute(s)." << endl;
            escape_found = true; // 탈출에 성공하면 true로 설정
            return; // 목표에 도달하면 종료
        }
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < R && ny < C && nz < L
                && !visit[nz][nx][ny] && building[nz][nx][ny] != 0) {
                visit[nz][nx][ny] = 1;
                q.push({nz, nx, ny, time + 1}); // 이동 후 시간 1분 증가
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
    cin >> L >> R >> C; // 값 입력
    if(L == 0 && R == 0 && C == 0){ //종료 조건
        return 0;
    }
     // visit 배열 초기화
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    visit[i][j][k] = 0; // 방문 배열 초기화
                }
            }
        }
    char s;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> s;
                if (s == '.') {
                    building[i][j][k] = 1; // 이동 가능
                } else if (s == '#') {
                    building[i][j][k] = 0; // 이동 불가능
                } else if (s == 'S') { // 시작 위치
                    start_point_z = i;
                    start_point_x = j;
                    start_point_y = k;
                } else { // 탈출 위치
                    end_point_z = i;
                    end_point_x = j;
                    end_point_y = k;
                }
            }
        }
    } 
    escape_found = false;
    BFS(start_point_z, start_point_x, start_point_y); // BFS 시작
    
    // 탈출하지 못한 경우에만 Trapped 출력
    if (!escape_found) {
        cout << "Trapped!" << endl;
       }
    }
}
