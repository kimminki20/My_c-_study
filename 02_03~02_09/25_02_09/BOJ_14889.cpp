#include <iostream>
#include <math.h>  // abs() 함수 사용을 위한 헤더
#define max 21  // 최대 인원수를 21로 설정

using namespace std;

int arr[max][max];  // 능력치 저장 배열
bool check[22];  // 팀 분배 여부를 저장하는 배열 (true: 스타트 팀, false: 링크 팀)
int N;  // 총 인원 수
int min_ability = 9999999;  // 최소 능력치 차이를 저장할 변수

// DFS를 사용하여 팀을 나누는 함수
void DFS(int x, int pos) {
    if (x == N / 2) {  // 팀원이 절반이 되면 능력치 차이를 계산
        int start = 0, link = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (check[i] && check[j]) start += arr[i][j];  // 스타트 팀 능력치 합산
                if (!check[i] && !check[j]) link += arr[i][j];  // 링크 팀 능력치 합산
            }
        }
        int temp = abs(start - link);  // 능력치 차이 계산
        if (min_ability > temp) min_ability = temp;  // 최소 차이 갱신
        return;
    }

    // 백트래킹을 사용하여 조합을 생성
    for (int i = pos; i < N; i++) {
        check[i] = true;  // i번째 사람을 스타트 팀에 포함
        DFS(x + 1, i + 1);  // 다음 사람 선택
        check[i] = false;  // 백트래킹 (다시 원상 복구)
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;  // 인원 수 입력
    // 능력치 배열 입력 받기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    DFS(0, 1);  // DFS 탐색 시작
    cout << min_ability;  // 최소 능력치 차이 출력
}
