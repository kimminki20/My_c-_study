
/*
투포인터를 이용해서 '먹을 것인가 먹힐 것인가 풀이'
*/
#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    vector<int> result;

    while (test_cases--) {
        int N, M;
        cin >> N >> M;

        vector<int> v1(N);
        vector<int> v2(M);

        for (int i = 0; i < N; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> v2[i];
        }

        // 정렬
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int count = 0;
        int j = 0; // v2의 인덱스

        for (int i = 0; i < N; i++) {
            while (j < M && v2[j] < v1[i]) {
                j++; // v1[i]보다 작은 원소 개수를 찾음
            }
            count += j; // j개의 원소가 v1[i]보다 작음
        } //투포인터를 사용해서 풀이

        result.push_back(count);
    }

    for (auto i : result) {
        cout << i << '\n';
    }

    return 0;
}