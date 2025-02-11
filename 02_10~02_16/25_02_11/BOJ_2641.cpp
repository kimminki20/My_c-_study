#include <iostream>
#include <vector>

#define MAX_N 101  // 표본 수열 최대 길이
#define MAX_INPUT 51  // 비교할 수열 개수 최대값

using namespace std;

// 두 배열이 회전을 포함하여 같은지 확인하는 함수
bool isSamePattern(vector<int>& pattern, vector<int>& candidate) {
    int N = pattern.size();
    
    // 2배 크기의 벡터를 만들어 회전 검사
    vector<int> extended(N * 2);
    for (int i = 0; i < N; i++) {
        extended[i] = extended[i + N] = candidate[i];
    } //배열의 크기를 2배로 해서 같은 값을 한번 더 적음 회전 검사

    // 슬라이딩 윈도우 방식으로 원형 비교  O(N)
    for (int start = 0; start < N; start++) {
        bool match = true;
        for (int j = 0; j < N; j++) {
            if (pattern[j] != extended[start + j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;  // 표본 수열의 길이

    vector<int> pattern(N);
    for (int i = 0; i < N; i++) {
        cin >> pattern[i];
    }

    // 역방향 패턴 만들기
    vector<int> reverse_pattern(N);
    for (int i = 0; i < N; i++) {
        if (pattern[i] == 1) reverse_pattern[N - 1 - i] = 3;
        else if (pattern[i] == 2) reverse_pattern[N - 1 - i] = 4;
        else if (pattern[i] == 3) reverse_pattern[N - 1 - i] = 1;
        else if (pattern[i] == 4) reverse_pattern[N - 1 - i] = 2;
    }

    int M;
    cin >> M;  // 입력받을 수열 개수

    vector<vector<int>> results;
    
    for (int i = 0; i < M; i++) {
        vector<int> candidate(N);
        for (int j = 0; j < N; j++) {
            cin >> candidate[j];
        }

        // 주어진 수열이 패턴과 동일하거나 반전된 패턴과 동일하면 정답
        if (isSamePattern(pattern, candidate) || isSamePattern(reverse_pattern, candidate)) {
            results.push_back(candidate);
        }
    }

    // 정답 출력
    cout << results.size() << "\n";
    for (const auto& res : results) {
        for (int num : res) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
