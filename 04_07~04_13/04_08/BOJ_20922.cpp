//백준 20922 겹치는 것은 싫어
// https://www.acmicpc.net/problem/20922

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> freq; // 현재 윈도우 내 숫자 등장 횟수
    int left = 0;
    int maxLength = 0;
    for(int right = 0; right < n; right++) {
        freq[arr[right]]++;
        // 조건 위반 시 (k 초과 등장한 숫자가 있을 때)
        while(freq[arr[right]] > k) {
            freq[arr[left]]--;
            left++;
        }
        // 현재 윈도우 길이 계산
        maxLength = max(maxLength, right - left + 1);
    }
    cout << maxLength << "\n";
    return 0;
}
