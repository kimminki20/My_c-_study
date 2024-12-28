#include <iostream>
#include <vector>
#include <algorithm> // sort를 사용하기 위함

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b}); // 시작 시간, 종료 시간
    }

    // 종료 시간을 기준으로 정렬 (동시에 종료 시간이 같으면 시작 시간으로 정렬)
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first; // 종료 시간이 같으면 시작 시간 오름차순
        return a.second < b.second;  // 종료 시간 오름차순
    });

    int maxs = 0;
    for (int i = 0; i < N; i++) {
        int a = i;
        int count = 1; // 첫 번째 회의를 선택
        for (int j = i + 1; j < N; j++) {
            if (v[a].second <= v[j].first) { // 현재 회의의 종료 시간 <= 다음 회의의 시작 시간
                a = j;
                count++;
            }
        }
        maxs = max(maxs, count);
    }

    cout << maxs;
    return 0;
}
