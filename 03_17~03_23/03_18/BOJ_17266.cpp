//백준 17266 어두운 굴다리
/*
    두 가로등의 위치를 각각 a, b라고 할 때(a < b),높이에 비례한만큼 바닥을 비추기 때문에 
    가장 효율적으로 a와 b사이를 비추기 위해서는 (b - a) / 2만큼의 높이를 가지는 게 최선이다. 
    따라서 0과 첫 가로등 사이의 거리, 마지막 가로등과 n 사이의 거리를 그리고 나머지 가로등 사이의 거리의 절반들 중 최댓값이 답이다.
    ->아이디어로 푼 문제
*/
#include <iostream>  // 입출력
#include <vector>    // 벡터 자료구조
#include <algorithm> // max 함수 사용
#include <cmath>     // ceil 함수 사용
#include <climits>   // INT_MIN 정의
using namespace std;

int main() {
    ios::sync_with_stdio(0); // 입출력 속도 향상을 위한 설정
    cin.tie(0); // 입출력 동기화 해제
    int n,m; 
    cin >> n >> m; // 거리의 범위 (0부터 n까지),가로등의 개수
    vector<int> pos(m); // 가로등의 위치를 저장할 벡터
    for (auto& e : pos) cin >> e; // 벡터에 입력값 저장

    int ans = INT_MIN; // 최대 거리 저장을 위한 변수, 초기값은 가장 작은 정수로 설정

    ans = max(ans, pos[0] - 0); // 첫 번째 가로등과 거리 시작점(0) 사이의 거리 비교
    ans = max(ans, n - pos[m-1]); // 마지막 가로등과 거리 끝(n) 사이의 거리 비교

    if (m > 1) { // 가로등이 2개 이상일 경우
        for (int i = 0; i < m-1; ++i) { 
            int diff = pos[i+1] - pos[i]; // 인접한 가로등 간 거리 계산
            diff = (int)ceil(diff / 2.0); // 두 가로등 사이의 최대 어두운 거리 계산 (가운데 위치를 기준)
            ans = max(ans, diff); // 현재 최댓값과 비교하여 갱신
        }
    }
    
    cout << ans; // 결과 출력
}
