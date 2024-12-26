//벡준 9655 돌 게임 문제 다이나믹 프로그래밍으로 푸는 방법.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;           // 돌의 개수
	int DP[1000];    // 게임과정의 횟수

	cin >> N;

	DP[0] = 0; //돌이 없는 경우(게임 불가능)
	DP[1] = 1; //돌 1개 -> SK의 승리
	DP[2] = 2; //돌 2개 -> CY의 승리

    //Dynamic Programming 전개
	for (int i = 3; i <= N; i++) {
		DP[i] = min(DP[i - 1] + 1, DP[i - 3] + 1);
	}
    //1개 가져감 남은 돌 i-1. 즉 이전 상태 DP[i-1]의 게임 회숫 +1
    //3개 가져감 남은 돌 i-1. 즉 이전 상태 DP[i-3]의 게임 회숫 +1

	// 게임 과정 횟수의 홀짝에 따라 승패 결정
	if (DP[N] % 2 == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	return 0;
}