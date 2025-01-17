#include <iostream>
#include <vector>
using namespace std;

vector<int> input;
int S, N;
int cnt = 0;
void solve(int index, int sum) {
    if (index == N) return;     // 기저 조건
    if (sum + input[index] == S) cnt++;    // 현재 원소를 더했을 때 S와 같은지 확인
    solve(index + 1, sum);    // 현재 원소를 포함하지 않는 경우
    solve(index + 1, sum + input[index]);  // 현재 원소를 포함하는 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        input.push_back(num);
    } 
    solve(0, 0);// 부분수열 탐색 시작
    cout << cnt << '\n';    // 결과 출력
    return 0;
}
