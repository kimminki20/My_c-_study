#include <iostream>
#include <vector>

using namespace std;

int n; // n : 회원의 수
int score[51]; // 각 회원의 "최대 거리"를 저장하는 배열
vector <int> V[51]; // 회원 간의 관계를 저장하는 벡터 (사용되지 않음)

int dist[51][51]; // dist[x][y] : x에서 y까지 가는 최소 간선 수

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 받기
    cin >> n;

    // dist 배열 초기화
    for (int i = 1; i <= n; i++) // 회원 수 만큼
    {
        for (int j = 1; j <= n; j++) // 모든 회원 쌍에 대해
        {
            if (i == j) continue; // 자기 자신과의 거리는 0으로 설정
            else dist[i][j] = 100000000; // 연결되지 않은 회원 간의 거리는 1000000000으로 초기화 (연결 정보는 입력에서 받음)
        }
    }

    int x, y;
    while (true) {
        cin >> x >> y; // 회원 간의 관계 입력
        if (x == -1 && y == -1) break; // -1 -1이 입력되면 종료
        dist[x][y] = 1; // x와 y가 연결됨, 간선의 가중치는 1
        dist[y][x] = 1; // 양방향 관계
    }

    // 플로이드-워셜 알고리즘으로 모든 회원 간의 최단 거리 계산
    for (int t = 1; t <= n; t++) { // 중간 지점 t를 이용해 최단 거리 갱신
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][t] + dist[t][j]) { 
                    // i -> j 직접 가는 것보다 i -> t -> j 가 더 짧다면 갱신
                    dist[i][j] = dist[i][t] + dist[t][j];
                }
            }
        }
    }

    // 각 회원에 대해 가장 멀리 있는 회원과의 거리를 계산
    int member = -1; // 회장을 결정할 변수
    for (int i = 1; i <= n; i++) {
        int m = 0; // i번 회원과 가장 멀리 있는 회원의 거리
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] > m) m = dist[i][j]; // i와 j 간의 최단 거리 중 가장 큰 값 찾기
        }
        score[i] = m; // i번 회원의 최대 거리를 score에 저장
        if (member > m || member == -1) member = m; // member를 최소값으로 갱신
    }

    // 최소 거리를 가진 회원 수 세기
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (score[i] == member) cnt++; // member와 같은 거리 값을 가진 회원 수 카운트
    }

    // 결과 출력
    cout << member << " " << cnt << "\n"; // 최소 거리와 해당 값을 가진 회원의 수 출력
    for (int i = 1; i <= n; i++) {
        if (score[i] == member) cout << i << " "; // 회장 후보 회원 출력
    }

    return 0;
}
