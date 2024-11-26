#include <iostream>
#include <vector>
#include <queue> // BFS를 위해 필요
#include <algorithm>
using namespace std;

int main() {
    int K, N; // 컴퓨터의 갯수, 네트워크의 갯수
    cin >> K >> N;

    // 2차원 벡터로 그래프 표현
    vector<vector<int>> v(K);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1); // a와 b 연결
        v[b - 1].push_back(a - 1); // b와 a 연결 (양방향)
    }

    // 방문 여부를 확인하기 위한 벡터
    vector<bool> visited(K, false);
    queue<int> q;

    // 시작 컴퓨터(1번 컴퓨터)
    q.push(0); //시작 컴퓨터(1번 컴퓨터,인덱스 0번)를 탐색 대상으로 추가
    visited[0] = true; // 1번 컴퓨터는 이미 탐색 완료 

    int infected = 0; // 감염된 컴퓨터 수

    while (!q.empty()) {
        int current = q.front();
        q.pop(); // 가져온 컴퓨터를 큐에서 제거
        infected++; //감연된 컴퓨터로 간주하고 카운트

        // 현재 컴퓨터에 연결된 다른 컴퓨터를 방문
        for (int neighbor : v[current]) { //현재 컴퓨터에 연결된 컴퓨터(neighbor)를 하나씩 확인
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // 시작 컴퓨터(1번)를 제외한 감염된 컴퓨터 수 출력
    cout << infected - 1 << endl;

    return 0;
}
/* BFS 너비 우선 탐색을 활용하여 컴퓨터 네트워크 그래프에서 바이러스 감염을 탐색.
BFS는 큐(queue)를 사용하여 그래프를 레벨 단위로 탐색
*/
