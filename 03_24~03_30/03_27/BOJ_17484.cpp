//백준 17484 진구의 달 여행(Small)
// dp와 재귀를 사용해서 푼 문제
#include <iostream>
#include <vector>
using namespace std;

int N, M; // N: 행(세로 크기), M: 열(가로 크기)
int map[7][7]; // 달 탐사 지도의 비용을 저장하는 배열
int ans = 99999999; // 최소 비용을 찾기 위한 초기값 (매우 큰 값 설정)
int dx[3] = {-1, 0, 1}; // 이동할 수 있는 방향 (왼쪽 아래, 아래, 오른쪽 아래)

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
// 최소 비용을 구하는 재귀 함수
int solve(int y, int x, int last) {
    if (y == N) return 0; // 마지막 행까지 도착하면 종료
    int tmp = 999999999; // 최소 비용을 저장할 변수 (큰 값으로 초기화)
    for (int i = 0; i < 3; i++) { // 3방향(왼쪽 아래, 아래, 오른쪽 아래) 탐색
        if (x + dx[i] >= 0 && x + dx[i] < M && i != last) // 경계를 벗어나지 않고, 같은 방향 연속 이동이 아닐 때
            tmp = min(tmp, solve(y + 1, x + dx[i], i) + map[y][x]); // 최소 비용 갱신
    }
    return tmp;
}
int main() {
    init(); // 입출력 속도 향상
    cin >> N >> M; // 지도 크기 입력
    // 지도 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    // 첫 번째 행의 각 열에서 출발하여 최소 비용 탐색
    for (int i = 0; i < M; i++) {
        ans = min(ans, solve(0, i, -1)); // 시작 시 last 값을 -1로 설정하여 모든 방향 탐색 가능
    }
    cout << ans; // 최소 비용 출력
    return 0;
}
