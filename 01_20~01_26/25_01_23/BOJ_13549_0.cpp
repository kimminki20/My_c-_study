#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int vis[100001];
int N, K; // 수빈이의 위치 N, 동생의 위치 K

int main() {
    cin >> N >> K;
    queue<int> Q;
    fill(vis, vis + 100001, -1); // 모든 배열을 -1로 초기화
    vis[N] = 0; // N 위치를 시작하는 곳으로 설정해서 0으로 지정
    Q.push(N);

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (cur == K) { // 동생의 위치에 도달하면 출력
            cout << vis[cur];
            return 0;
        }

        // 순간이동 (시간 증가 없음) , 뒤에 달은 조건은 방문한 장소여도 더 짧은 시간인 것을 고르는 것
        if (cur * 2 < 100001 && (vis[cur * 2] == -1 || vis[cur * 2] > vis[cur])) {
            vis[cur * 2] = vis[cur];
            Q.push(cur * 2);
        }

        // 이동 (+1, -1)
        for (int next : {cur + 1, cur - 1}) {
            if (next >= 0 && next < 100001 && (vis[next] == -1 || vis[next] > vis[cur] + 1)) {
                vis[next] = vis[cur] + 1; // 1초 증가
                Q.push(next);
            }
        }
    }
    return 0;
}
