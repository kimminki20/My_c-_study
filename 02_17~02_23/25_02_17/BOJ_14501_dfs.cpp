#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> schedule;
int max_money = 0;

void dfs(int day, int total_money) {
    if (day >= N) { // 퇴사 날짜 초과하면 종료
        max_money = max(max_money, total_money);
        return;
    }

    // 1. 현재 상담을 선택하는 경우
    if (day + schedule[day].first <= N) { // 퇴사일을 넘지 않으면
        dfs(day + schedule[day].first, total_money + schedule[day].second);
    }

    // 2. 현재 상담을 선택하지 않는 경우 (다음 날로 이동)
    dfs(day + 1, total_money);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    schedule.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> schedule[i].first >> schedule[i].second;
    }

    dfs(0, 0);
    cout << max_money << "\n";
}
