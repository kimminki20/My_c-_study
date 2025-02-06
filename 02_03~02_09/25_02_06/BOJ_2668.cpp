//백준 2668번 숫자 찾기 그래프이론인 DFS사용하여 문제 해결
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n; // 숫자의 개수
vector<int> graph; // 숫자들이 가리키는 배열 (1-based index)
set<int> result; // 최종적으로 선택된 숫자들의 집합

// DFS 탐색 함수 (사이클을 찾음)
void dfs(int start, int current, vector<bool>& visited, set<int>& path) {
    if (visited[current]) {  // 이미 방문한 노드라면
        if (current == start) {  // 시작점으로 돌아오면 사이클 형성됨
            result.insert(path.begin(), path.end()); // 경로에 있는 숫자들을 결과 집합에 추가
        }
        return;
    }
    visited[current] = true; // 방문 체크
    path.insert(current); // 현재 숫자를 경로에 추가
    dfs(start, graph[current], visited, path); // 다음 숫자로 DFS 진행
    visited[current] = false; // 백트래킹 (다른 탐색을 위해 방문 해제)
    path.erase(current); // 백트래킹 (경로에서 숫자 제거)
}

int main() {
    cin >> n;
    graph.resize(n + 1); // 1-based index를 사용하므로 크기를 (n+1)로 설정

    // 입력 받기
    for (int i = 1; i <= n; i++) {
        cin >> graph[i];
    }

    // 모든 숫자에서 DFS 탐색
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1, false); // 방문 여부 체크 배열
        set<int> path; // 현재 탐색 중인 경로 (사이클 판별용)
        dfs(i, i, visited, path); // DFS 시작
    }

    // 결과 출력
    cout << result.size() << "\n"; // 선택된 숫자의 개수 출력
    for (int num : result) { // 오름차순으로 숫자 출력 (set은 자동 정렬됨)
        cout << num << "\n";
    }

    return 0;
}
