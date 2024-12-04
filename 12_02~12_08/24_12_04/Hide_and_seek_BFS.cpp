#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int BFS(int N, int M) {
    vector<int> visited(100001, 0); // 방문 여부를 체크
    queue<int> q; // BFS를 위한 큐
    q.push(N);    // 시작점
    visited[N] = 1; // 시작점을 방문 표시 (1부터 시작)

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 동생을 찾은 경우
        if (current == M) {
            return visited[current] - 1; // 시작점에서 1을 뺐음
        }

        // 이동 가능한 3가지 경우
        for (int next : {current - 1, current + 1, current * 2}) {
            if (next >= 0 && next <= 100000 && !visited[next]) {
                visited[next] = visited[current] + 1; // 방문 및 거리 저장
                q.push(next);
            }
        }
    }
    return -1; // 도달 불가능한 경우 (이 문제에서는 발생하지 않음)
}

int main() {
    int N, M; // 수빈이의 위치 N, 동생의 위치 M
    cin >> N >> M;

    int result = BFS(N, M);
    cout << result << endl;

    return 0;
}
