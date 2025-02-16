//백준 7795 먹을 것인가 먹힐 것인가
#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

int main() {
    int test_cases; // 테스트 케이스 개수
    cin >> test_cases;

    vector<int> result;

    while (test_cases--) {
        int N, M;
        cin >> N >> M;

        vector<int> v1(N); // A 배열
        vector<int> v2(M); // B 배열

        for (int i = 0; i < N; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> v2[i];
        }
        sort(v1.begin(), v1,end());
        sort(v2.begin(), v2,end());
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v1[i] > v2[j]) {
                    count++;
                }
                else break;
            }
        }
        result.push_back(count);
    }
    for (auto i : result) {
        cout << i << '\n';
    }
    return 0;
}
//정렬해서 짜면 시간을 줄일 수있음
//이 풀이는 완전 탐색 풀이를 이용해서 해결함
//이진탐색,투포인터 풀이도 존재함