#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
vector<int> v[101];
int visited[101];

int bfs(int start, int end) {
    queue<pair<int, int>> q; // (현재 노드, 현재까지의 거리)
    q.push({start, 0});
    visited[start] = 1;

    while (!q.empty()) {
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (now == end) {
            return dist; // 목표 노드에 도달하면 거리 반환
        }

        for (int next : v[now]) {
            if (!visited[next]) {
                visited[next] = 1; // 방문 표시
                q.push({next, dist + 1});
            }
        }
    }

    return -1; // 목표 노드에 도달하지 못하면 -1 반환
}

int main() {
    int x, y;
    cin >> n >> x >> y >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << bfs(x, y);
    return 0;
}
