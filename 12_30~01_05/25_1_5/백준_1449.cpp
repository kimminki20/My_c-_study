//백준 1449 수리공 항승
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L; // 물이 새는 위치 수 N, 테이프의 길이 L
    vector<pair<int, bool>> water(N);

    for (int i = 0; i < N; i++) {    // 물이 새는 위치 입력
        cin >> water[i].first;
        water[i].second = false; // 초기값은 모두 false (덮이지 않음)
    }
    sort(water.begin(), water.end()); // 위치를 오름차순으로 정렬

    int count = 0; // 필요한 테이프의 개수
    for (int i = 0; i < N; i++) {
        if (water[i].second) continue; // 이미 덮인 위치는 스킵
        count++;// 새로운 테이프로 덮기 시작
        int start = water[i].first; // 현재 테이프 시작 위치
        for (int j = i; j < N; j++) {
            // 테이프가 덮을 수 있는 범위 내라면 덮음
            if (water[j].first <= start + L - 1) {
                water[j].second = true;
            } else {
                break; // 범위를 벗어나면 중단
            }
        }
    }
    cout << count << endl;
    return 0;
}
