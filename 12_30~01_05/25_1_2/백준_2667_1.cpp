#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {1, -1, 0, 0}; // 좌우
int map[26][26];           // 입력받을 단지
int visit[26][26];         // 방문 기록
int N;                     // 맵의 크기

int BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = 1;
    int count = 1; // 현재 집 포함

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int cx = current.first;
        int cy = current.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny] && map[nx][ny] == 1) {
                visit[nx][ny] = 1;
                q.push({nx, ny});
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    cin >> N; // 맵의 크기 입력받음

    // 입력 데이터 처리
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0'; // 문자 '0' 또는 '1'을 숫자로 변환
        }
    }

    // 단지 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j] && map[i][j] == 1) { // 방문하지 않은 집일 때만 BFS 수행
                v.push_back(BFS(i, j));
            }
        }
    }

    // 결과 출력
    sort(v.begin(), v.end()); // 단지 크기 정렬
    cout << v.size() << '\n'; // 단지 수 출력
    for (int size : v) {
        cout << size << '\n'; // 각 단지 크기 출력
    }

    return 0;
}
