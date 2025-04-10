//백준 3758 KCPC
// https://www.acmicpc.net/problem/3758
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; // 테스트 케이스 개수
	cin >> T;
	while (T--) {
		int n, k, t, m;
		cin >> n >> k >> t >> m; // 팀 수, 문제 수, 목표 팀 번호(1부터 시작), 로그 수
		int arr[101][101] = { 0 }; // 각 팀별 문제 최대 점수 저장 배열
		int cnt[101] = { 0 }; // 각 팀의 총 제출 횟수
		int order[101] = { 0 }; // 각 팀의 마지막 제출 시간 (로그 순서)
		t--; // 팀 번호를 0부터 시작하도록 조정

		for (int i = 0; i < m; i++) {
			int id, num, s;
			cin >> id >> num >> s; // 팀 ID, 문제 번호, 획득 점수
			id--; // 팀 번호를 0부터 시작하도록 조정
			num--; // 문제 번호를 0부터 시작하도록 조정
			arr[id][num] = max(arr[id][num], s); // 해당 문제의 최고 점수만 반영
			cnt[id]++; // 해당 팀의 제출 횟수 증가
			order[id] = i; // 해당 팀의 마지막 제출 시간 업데이트
		}

		// 랭킹을 위한 벡터 (총점, 제출 횟수, 마지막 제출 시간, 팀 번호)
		vector<pair<int, pair<int, pair<int, int>>>> v;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < k; j++)
				sum += arr[i][j]; // 팀의 총점 계산
			v.push_back({ sum,{-cnt[i],{-order[i],i}} }); 
			// 총점이 높은 순 정렬, 제출 횟수가 적은 순 정렬, 마지막 제출 시간이 빠른 순 정렬, 팀 번호 오름차순 정렬
		}

		sort(v.begin(), v.end()); // 정렬 수행 (기본적으로 오름차순 정렬)
		for (int i = 0; i < n; i++) {
			if (v[i].second.second.second == t) // 목표 팀의 순위 찾기
				cout << n - i << '\n'; // 현재 팀의 순위를 출력 (1등이 n, 마지막 팀이 1)
		}
	}

	return 0;
}

