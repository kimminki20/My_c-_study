#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, N; // k: 반의 수, N: 학생 수
    cin >> k;

    for (int i = 1; i <= k; i++) { // 반의 수만큼 반복
        cin >> N;
        vector<int> scores(N);

        // 점수 입력
        for (int j = 0; j < N; j++) {
            cin >> scores[j];
        }

        // 정렬
        sort(scores.begin(), scores.end());

        // Max, Min 계산
        int max_score = scores[N - 1];
        int min_score = scores[0];

        // Largest gap 계산
        int largest_gap = 0;
        for (int j = 0; j < N - 1; j++) {
            largest_gap = max(largest_gap, scores[j + 1] - scores[j]);
        }

        // 결과 출력
        cout << "Class " << i << endl;
        cout << "Max " << max_score << ", ";
        cout << "Min " << min_score << ", ";
        cout << "Largest gap " << largest_gap << endl;
    }

    return 0;
}
// vector 사용해서 해결 sort,max 등 사용.