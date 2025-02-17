#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;  // 퇴사 날짜 (N+1)
    
    vector<pair<int, int>> schedule(N); // 상담 기간과 이익 저장
    vector<int> max_profit(N + 1, 0); // 각 날짜까지의 최대 이익 저장
    
    for (int i = 0; i < N; i++) {
        cin >> schedule[i].first >> schedule[i].second; // 상담 기간, 수익
    }

    int max_money = 0; // 최종 최대 이익

    for (int i = 0; i < N; i++) {
        // 현재까지의 최대 이익을 유지
        if (i > 0) max_profit[i] = max(max_profit[i], max_profit[i - 1]);

        int date = i + schedule[i].first; // 상담 종료 날짜

        // 상담을 진행할 수 있는 경우
        if (date <= N) {
            max_profit[date] = max(max_profit[date], max_profit[i] + schedule[i].second);
            max_money = max(max_money, max_profit[date]); // 최댓값 갱신
        }
    }

    cout << max_money << "\n"; // 최대 이익 출력
}
