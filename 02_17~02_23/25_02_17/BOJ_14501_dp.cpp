#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    vector<int> T(N), P(N), dp(N+1, 0); // T: 상담 기간, P: 수익, dp: 최대 수익 저장
    
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    // 뒤에서부터 DP 수행 (N-1부터 0까지 역순으로)
    for (int i = N - 1; i >= 0; i--) {
        int nextDay = i + T[i]; // 상담을 마치는 날짜
        if (nextDay <= N) { // 상담이 가능하다면
            dp[i] = max(dp[i + 1], P[i] + dp[nextDay]);
        } else { // 상담이 불가능하다면 (퇴사일 이후 넘어감)
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[0] << "\n"; // 첫 날부터 시작했을 때의 최대 이익 출력
}
