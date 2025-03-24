//백준 2512 예산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, total;
    cin >> N;
    vector<int> input(N);
    int sum = 0, large = 0;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
        sum += input[i];
        large = max(large, input[i]); // 가장 큰 값 갱신
    }
    cin >> total;
    // 모든 요청 예산 합이 총 예산보다 작으면 최대 예산 그대로 출력
    if (sum <= total) {
        cout << large;
        return 0;
    }
    // 이진 탐색 수행
    int start = 0, end = large, result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0;

        for (int i = 0; i < N; i++) {
            sum += min(input[i], mid);
        }

        if (sum <= total) { // 예산이 총액보다 작거나 같으면 상한액 증가 가능
            result = mid;
            start = mid + 1;
        } else { // 예산이 초과되면 상한액 낮춰야 함
            end = mid - 1;
        }
    }

    cout << result;
}
